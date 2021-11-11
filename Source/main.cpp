#include "mainwindow.h"
#include "dialog.h"
#include <QApplication>
#include<QTimer>
#include<QSplashScreen>
#include<QMovie>
#include<iostream>
#include<QLabel>
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#define MAX 10

using namespace std;

string idx[MAX], Model[MAX], seriNum[MAX], Bus[MAX];
int BPT[MAX], SPT[MAX];
long long int Size[MAX];

void getDiskInfo()
{
    system("wmic diskdrive get Index > Info.txt");
    system("wmic diskdrive get Size, SerialNumber, SectorsPerTrack, Model, BytesPerSector /FORMAT:LIST >> Info.txt");
    system("powershell -ExecutionPolicy Bypass -F test1.ps1 ");
    system("copy /b Info.txt+BusType.txt final.txt");
    system("powershell -ExecutionPolicy Bypass -F test2.ps1 ");
}

void readData(int &count)
{
    fstream file;
    file.open("temp.txt",ios::in);
    string str;
    while (!file.eof())
    {
        getline(file,str,'\n');
        if (str.empty()) continue;
        if (str.find("Index")!=-1)
        {
            while (!str.empty())
            {
                getline(file,str);
                if (!str.empty())
                {
                    idx[count]=str;
                    count++;
                }
            }
        }
        if (str.find("Byte")!=-1){
            int i=0;
            while (i<count){
            while (str.find("Byte")!=-1){
                BPT[i]=stoi(str.substr(str.find("=")+1));
                getline(file,str);
                Model[i]=str.substr(str.find("=")+1);
                getline(file,str);
                SPT[i]=stoi(str.substr(str.find("=")+1));
                getline(file,str);
                seriNum[i]=str.substr(str.find("=")+1);
                getline(file,str);
                Size[i]=stoll(str.substr(str.find("=")+1));
                i++;
                }
            getline(file,str);
            }
        }
        if (str.find("Bus")!=-1){
            getline(file,str);
            for (int i=0;i<count;i++)
            {
                getline(file,str);
                Bus[i]=str.substr(0,str.find(" "));
            }
        }
    }
    file.close();
}

void display(int count)
{
    ofstream out("test.txt");
    out<<count<<endl;
    for (int i=0;i<count; i++)
    {
        out << setw(30) << left <<"Model ";
        out << setw(50) << right << Model[i] <<endl;
        out << setw(30) << left << "Serial Number" ;
        out << setw(50) << right << seriNum[i] << endl;
        out << setw(30) << left << "BytesPerTrack" ;
        out << setw(50) << right << BPT[i] << endl;
        out << setw(30) << left << "SectorsPerTrack" ;
        out << setw(50) << right << SPT[i] << endl;
        out << setw(30) << left << "Bus" ;
        out << setw(50) << right << Bus[i] << endl;
        out << setw(30) << left << "Size" ;
        out << setw(46) << right << Size[i] << "(KB) "<<Size[i]/(1024*1024*1024) << "(GB) "<<endl  ;
      //  out << setw(76) << right << Size[i]/(1024*1024*1024) << "(GB) \n" << endl;
    }
    out.close();
}







int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //start splashscreen
   Dialog s; s.setAttribute(Qt::WA_TranslucentBackground);  s.setWindowFlags(Qt::FramelessWindowHint); s.setStyleSheet("background:transparent");
   s.show();

   //s.close();


   //initialize data to file
   int count=0;
   getDiskInfo();
   readData(count);
   system("CLS");
   display(count);


   //display window
    MainWindow w;
    w.setAttribute(Qt::WA_TranslucentBackground);
     w.setWindowFlags(Qt::FramelessWindowHint);
     QTimer::singleShot(2650,&s, &QWidget::close);
     QTimer::singleShot(2650,&w,&QWidget::show);
   // w.show();

    return a.exec();
}
