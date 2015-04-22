#ifndef MAINWINDOWS_H
#define MAINWINDOWS_H

#include <QMainWindow>

namespace Ui {
class mainwindows;
}

class mainwindows : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainwindows(QWidget *parent = 0);
    ~mainwindows();

private:
    Ui::mainwindows *ui;
};

#endif // MAINWINDOWS_H
