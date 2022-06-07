#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <unistd.h>
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    user = getenv("USER");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString location = "/home/" + user;
    executable = QFileDialog::getOpenFileName(this, "Select executable", location);
}


void MainWindow::on_pushButton_2_clicked()
{
    QString location = "/home/" + user;
    icon = QFileDialog::getOpenFileName(this, "Select icon", location);
}

void MainWindow::on_lineEdit_editingFinished()
{
    programName = ui->lineEdit->text();
}

void MainWindow::on_pushButton_3_clicked()
{
    QString location = "/home/" + user + "/Desktop";
    destination = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    location,
                                                    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
}


void MainWindow::on_pushButton_4_clicked()
{
    QString locationAndName = destination + "/" + programName + ".desktop";
    std::ofstream shortcut;
    shortcut.open(locationAndName.toStdString());

    shortcut << "[Desktop Entry]\n";
    shortcut << "Exec=" + executable.toStdString()<<"\n";
    shortcut << "Icon=" + icon.toStdString()<<"\n";
    shortcut << "Name=" + programName.toStdString()<<"\n";
    shortcut << "Type=Application";

    shortcut.close();

    QMessageBox::information(this,"..", "Desktop entry created.");
}
