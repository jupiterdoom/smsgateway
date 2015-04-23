#include "mainwindows.h"
#include "ui_mainwindows.h"
#include "smsgateway.cpp"


mainwindows::mainwindows(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainwindows)
{
    ui->setupUi(this);
    ISmsGateway* Sms;
    ui->label->setText(Sms->gatewayId());
}

mainwindows::~mainwindows()
{
    delete ui;
}



