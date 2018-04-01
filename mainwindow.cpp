#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLibrary>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QLibrary Lib1("DinLib");
     returnSum=(func)Lib1.resolve("_ZN6DinLib5summaEii");
     returnMinus=(func)Lib1.resolve("_ZN6DinLib5minusEii");
     returnUmnozhenie=(func)Lib1.resolve("_ZN6DinLib10umnozhenieEii");
     returnDelenie=(func)Lib1.resolve("_ZN6DinLib7delenieEii");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{   int a=ui->A->text().toInt();
    int b=ui->B->text().toInt();
    int rez;
    QString s;
    if(ui->MinusB->isChecked()){
        rez=returnMinus(a,b);
        s=QString::number(rez);
        ui->label->setText(s);
        }
    if(ui->sumB->isChecked()){
        rez=returnSum(a,b);
        s=QString::number(rez);
        ui->label->setText(s);
        }
    if(ui->DelB->isChecked()){
        rez=returnDelenie(a,b);
        s=QString::number(rez);
        ui->label->setText(s);
        }
    if(ui->UmnB->isChecked()){
        rez=returnUmnozhenie(a,b);
        s=QString::number(rez);
        ui->label->setText(s);
        }

}
