#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>
#include<QMovie>
#include<QGraphicsEffect>
#include "qgraphicsgloweffect.h"
#include<string>
#include<QString>
#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>
#include<QTime>
using namespace std;


void read(vector<string> &dat, int &count)
{
    ifstream in("test.txt");
    string temp;
    int i=0; int index =0;
    getline(in,temp);
    stringstream iss(temp);
    iss >> count;
    temp.clear();
  while(getline(in,temp))
  {
    dat.push_back(temp);
  }

}

void sep(vector<string> dat, vector<string> &d1, int flag)
{
  for(int i=flag-5 ; i<= flag; i++)
  {
     stringstream iss(dat[i]);
             for(string s; iss>>s;)
               {
                   d1.push_back(s);
               }
  }
  for(int i=0 ; i< d1.size(); i++)
  {
      cout<<d1[i]<<endl;
  }
}

void delay( int millisecondsToWait )
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}

    vector<string>dat;
      int count;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //vector<vector<string>>dat(3);
  //  int count;

      read(dat,count);
 //cout<<"Ewqe q"<<count;



int blur =15; int strong =3;
    QGraphicsGlowEffect * glow1 = new QGraphicsGlowEffect(); glow1->setStrength(strong); glow1->setBlurRadius(blur);
     QGraphicsGlowEffect * glow2 = new QGraphicsGlowEffect(); glow2->setStrength(strong); glow2->setBlurRadius(blur);
      QGraphicsGlowEffect * glow3 = new QGraphicsGlowEffect(); glow3->setStrength(strong); glow3->setBlurRadius(blur);
       QGraphicsGlowEffect * glow4 = new QGraphicsGlowEffect(); glow4->setStrength(strong); glow4->setBlurRadius(blur);
        QGraphicsGlowEffect * glow5 = new QGraphicsGlowEffect(); glow5->setStrength(1); glow5->setBlurRadius(blur);
         QGraphicsGlowEffect * glow6 = new QGraphicsGlowEffect(); glow6->setStrength(1); glow6->setBlurRadius(blur);
    ui->f1exit->setGraphicsEffect(glow1);
    ui->b1->setGraphicsEffect(glow2);
    ui->b2->setGraphicsEffect(glow3);
    ui->b3->setGraphicsEffect(glow4);
   // ui->info1->setGraphicsEffect(glow5);
  //  ui->info2->setGraphicsEffect(glow6);
    QPixmap pix(":/Image/exit3.png");
    ui->exit_img->setPixmap(pix);
    ui->exit_img->setScaledContents(1);

    if(count==1)
    {
        ui->b2->setText("NONE");
        ui->b3->setText("NONE");
    }
    else if(count==2)
    {
        ui->b3->setText("NONE");
    }



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_f1exit_clicked()
{
    close();
}


void MainWindow::on_b1_clicked()
{
    QLabel *p[6]; p[0]=ui->l1; p[1]=ui->l2; p[2]=ui->l3; p[3]=ui->l4; p[4]=ui->l5; p[5]=ui->l6;
    for(int i=0; i<6; i++)
    {
        p[i]->setVisible(0);
    }
    ui->loadgif->setVisible(1);
    QMovie *t = new QMovie(":/Image/7epV.gif");
    ui->loadgif->setMovie(t);
    ui->loadgif->setScaledContents(1);
    t->start();
    delay(1100);
    ui->loadgif->setVisible(0);
     int blur =20; int strong =2;
    QGraphicsGlowEffect * glow1 = new QGraphicsGlowEffect(); glow1->setStrength(strong); glow1->setBlurRadius(blur);
     QGraphicsGlowEffect * glow2 = new QGraphicsGlowEffect(); glow2->setStrength(strong); glow2->setBlurRadius(blur);
      QGraphicsGlowEffect * glow3 = new QGraphicsGlowEffect(); glow3->setStrength(strong); glow3->setBlurRadius(blur);
       QGraphicsGlowEffect * glow4 = new QGraphicsGlowEffect(); glow4->setStrength(strong); glow4->setBlurRadius(blur);
        QGraphicsGlowEffect * glow5 = new QGraphicsGlowEffect(); glow5->setStrength(strong); glow5->setBlurRadius(blur);
         QGraphicsGlowEffect * glow6 = new QGraphicsGlowEffect(); glow6->setStrength(strong); glow6->setBlurRadius(blur);
          ui->l1->setGraphicsEffect(glow1);
          ui->l2->setGraphicsEffect(glow2);
          ui->l3->setGraphicsEffect(glow3);
          ui->l4->setGraphicsEffect(glow4);
          ui->l5->setGraphicsEffect(glow5);
          ui->l6->setGraphicsEffect(glow6);
         QFont f("Times New Roman",10);
    for(int i=0; i<6;i++)
    {
        p[i]->setVisible(1);
        QString a = QString::fromStdString(dat[i]);
        p[i]->setFont(f);
        p[i]->setText(a);
    }



}


void MainWindow::on_b2_clicked()
{

    if(count>=2)
    {
          ui->b2->setText("DEVICE 2");
        QLabel *p[6]; p[0]=ui->l1; p[1]=ui->l2; p[2]=ui->l3; p[3]=ui->l4; p[4]=ui->l5; p[5]=ui->l6;
        for(int i=0; i<6; i++)
        {
            p[i]->setVisible(0);
        }
        ui->loadgif->setVisible(1);
        QMovie *t = new QMovie(":/Image/7epV.gif");
        ui->loadgif->setMovie(t);
        ui->loadgif->setScaledContents(1);
        t->start();
        delay(1100);
        ui->loadgif->setVisible(0);
        int blur =20; int strong =2;
            QGraphicsGlowEffect * glow1 = new QGraphicsGlowEffect(); glow1->setStrength(strong); glow1->setBlurRadius(blur);
             QGraphicsGlowEffect * glow2 = new QGraphicsGlowEffect(); glow2->setStrength(strong); glow2->setBlurRadius(blur);
              QGraphicsGlowEffect * glow3 = new QGraphicsGlowEffect(); glow3->setStrength(strong); glow3->setBlurRadius(blur);
               QGraphicsGlowEffect * glow4 = new QGraphicsGlowEffect(); glow4->setStrength(strong); glow4->setBlurRadius(blur);
                QGraphicsGlowEffect * glow5 = new QGraphicsGlowEffect(); glow5->setStrength(strong); glow5->setBlurRadius(blur);
                 QGraphicsGlowEffect * glow6 = new QGraphicsGlowEffect(); glow6->setStrength(strong); glow6->setBlurRadius(blur);
                  ui->l1->setGraphicsEffect(glow1);
                  ui->l2->setGraphicsEffect(glow2);
                  ui->l3->setGraphicsEffect(glow3);
                  ui->l4->setGraphicsEffect(glow4);
                  ui->l5->setGraphicsEffect(glow5);
                  ui->l6->setGraphicsEffect(glow6);
                 QFont f("Times New Roman",10);
        for(int i=0,j=6; i<6 && j<12 ;i++,j++)
        {
            p[i]->setVisible(1);
            QString a = QString::fromStdString(dat[j]);
            p[i]->setFont(f);
            p[i]->setText(a);
        }

    }
}


void MainWindow::on_b3_clicked()
{

    if(count >= 3)
    {
        QLabel *p[6]; p[0]=ui->l1; p[1]=ui->l2; p[2]=ui->l3; p[3]=ui->l4; p[4]=ui->l5; p[5]=ui->l6;
        for(int i=0; i<6; i++)
        {
            p[i]->setVisible(0);
        }
        ui->loadgif->setVisible(1);
        QMovie *t = new QMovie(":/Image/7epV.gif");
        ui->loadgif->setMovie(t);
        ui->loadgif->setScaledContents(1);
        t->start();
        delay(1100);
        ui->loadgif->setVisible(0);
        int blur =20; int strong =2;
            QGraphicsGlowEffect * glow1 = new QGraphicsGlowEffect(); glow1->setStrength(strong); glow1->setBlurRadius(blur);
             QGraphicsGlowEffect * glow2 = new QGraphicsGlowEffect(); glow2->setStrength(strong); glow2->setBlurRadius(blur);
              QGraphicsGlowEffect * glow3 = new QGraphicsGlowEffect(); glow3->setStrength(strong); glow3->setBlurRadius(blur);
               QGraphicsGlowEffect * glow4 = new QGraphicsGlowEffect(); glow4->setStrength(strong); glow4->setBlurRadius(blur);
                QGraphicsGlowEffect * glow5 = new QGraphicsGlowEffect(); glow5->setStrength(strong); glow5->setBlurRadius(blur);
                 QGraphicsGlowEffect * glow6 = new QGraphicsGlowEffect(); glow6->setStrength(strong); glow6->setBlurRadius(blur);
                  ui->l1->setGraphicsEffect(glow1);
                  ui->l2->setGraphicsEffect(glow2);
                  ui->l3->setGraphicsEffect(glow3);
                  ui->l4->setGraphicsEffect(glow4);
                  ui->l5->setGraphicsEffect(glow5);
                  ui->l6->setGraphicsEffect(glow6);
                 QFont f("Times New Roman",10);
        for(int i=0,j=12; i<6 && j<18 ;i++,j++)
        {
            p[i]->setVisible(1);
            QString a = QString::fromStdString(dat[j]);
            p[i]->setFont(f);
            p[i]->setText(a);
        }
    }
}

