#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

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
    executable = QFileDialog::getOpenFileName(this, "Select executable", "/home");
}


void MainWindow::on_pushButton_2_clicked()
{
    icon = QFileDialog::getOpenFileName(this, "Select icon", "/home");
}

void MainWindow::on_lineEdit_editingFinished()
{

}

