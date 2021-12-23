#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QMessageBox>
#include<QTextStream>
#include<QPlainTextEdit>
#include<string>
#include <QMainWindow>
#include<time.h>
#include<cstdlib>
#include<vector>

#include<sstream>
#include<QFile>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>

#include<check.h>
#include<format.h>
#include<json.h>
#include<minifying.h>
#include<compressDecompress.h>
#include<QIntegerForSize>
using namespace std;
 string mytextstring;
 extern string detection;
 vector<int>i_comp;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionopen_triggered()
{

    QString F = "All Files (*.*);;xml Files (*.xml)";
    QString fileName = QFileDialog::getOpenFileName(this,"open file","E://",F);
    QFile xmlfile(fileName);

    if(!xmlfile.open(QIODevice::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,"warning","cannot Open File : " + xmlfile.errorString());
    }
    setWindowTitle(fileName);
    QTextStream in(&xmlfile);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);
    xmlfile.close();
    mytextstring = text.toStdString();

}




void MainWindow::on_pushButton_clicked()
{
detection.clear();
    string s;

    s=Consistent(mytextstring);
    QString t1=QString::fromStdString(detection);



QMessageBox::warning(this,"Information" , "Detection : "+ t1 );
     QString t=QString::fromStdString(s);
     ui->plainTextEdit->setPlainText(t);





}


void MainWindow::on_pushButton_2_clicked()
{
    string s;

  i_comp=compress(mytextstring);
  char c[1000];
  for(int k=0;k<i_comp.size();k++)
  {
      c[k]=i_comp[k];
  }
  for(int n=0;n<1000;n++)
  {
      s+=c[n];
  }
 s.c_str();
  QString u=QString::fromStdString(s);
  ui->plainTextEdit->setPlainText(u);

}


void MainWindow::on_pushButton_3_clicked()
{
string s;
        s=decompress(i_comp);
        QString u=QString::fromStdString(s);
        ui->plainTextEdit->setPlainText(u);
}


void MainWindow::on_pushButton_4_clicked()
{
    string c="\n";
         string xx;
          string s;
        vector<string> json(1000);
         vector<string>xml;
         unsigned int size =xml.size();
         PARSE(mytextstring,xml,size);
        xml_to_json(xml,json,size);
       for(int i=0;i<json.size();i++){
         xx=xx .append(json[i])+c;

      }

       QString t=QString::fromStdString(xx);
        ui->plainTextEdit->setPlainText(t);
}


void MainWindow::on_pushButton_5_clicked()
{
    string s;
      s=formate(mytextstring);
    QString t1=QString::fromStdString(s);
     ui->plainTextEdit->setPlainText(t1);
}


void MainWindow::on_pushButton_6_clicked()
{
    string s;
      s= Minifying(mytextstring);
    QString t2=QString::fromStdString(s);
     ui->plainTextEdit->setPlainText(t2);
}

