#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

using std::cout;
using std::endl;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Elden Ring Savefile Manager");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(std::filesystem::exists(save_name)){
        QMessageBox test;
        test.setText("Directory already exists.\nDo you want to overwrite it?");
        test.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
        test.setDefaultButton(QMessageBox::Cancel);
        switch(test.exec()){
        case QMessageBox::Cancel:
                return;
        default:
            break;
        }

        std::filesystem::remove_all(save_name);
    }
    std::filesystem::copy(elden_ring_savefile, save_name, std::filesystem::copy_options::recursive);

}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    save_name = "C:\\Users\\cyril\\Desktop\\Elden Ring saves\\" + arg1.toStdString();
}

