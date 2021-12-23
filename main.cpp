#include "mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QMessageBox>
#include<QTextStream>
#include<QPlainTextEdit>
#include<string.h>
#include<string>
#include <QMainWindow>
#include<stack>
#include<sstream>
#include<QFile>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include<iostream>
#include <QApplication>
using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
