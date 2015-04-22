#include "mainwindows.h"
#include "ui_mainwindows.h"

mainwindows::mainwindows(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainwindows)
{
    ui->setupUi(this);
}

mainwindows::~mainwindows()
{
    delete ui;
}
