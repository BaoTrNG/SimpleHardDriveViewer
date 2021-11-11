#include "dialog.h"
#include "ui_dialog.h"
#include<QMovie>
#include<QLabel>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
     QMovie *movie = new QMovie(":/Image/load3.gif");
     ui->gif->setMovie(movie);
     ui->gif->setScaledContents(1);
     movie->start();
}

Dialog::~Dialog()
{
    delete ui;
}
