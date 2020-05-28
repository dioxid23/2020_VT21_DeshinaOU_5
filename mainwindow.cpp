#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Antiplagiat.h"


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

void MainWindow::on_pushButton_clicked()
{
    SmartPtr<string> ftext (new string), fname(new string);
    (*ftext) = (ui->textEdit->toPlainText()).toLocal8Bit().toStdString();
    (*fname) = (ui->lineEdit->text()).toStdString();
    ui->textEdit_2->clear();
    Antiplag check;
    vector<string> sample;
    sample = check.read_file(*fname);
    vector<string> result;
    result = check.check_text(sample, *ftext);
    if (result.size()==0)
        ui->textEdit_2->setText(QString::fromLocal8Bit("Уникальность - 100%"));
    else
    {
        ui->textEdit_2->setText(QString::fromLocal8Bit("Совпадения в словах:"));
        for (int i=0;i<result.size();i++)
        {
            QString str = QString::fromLocal8Bit((result[i]).c_str());
            ui->textEdit_2->append(str);
        }
    }
}
