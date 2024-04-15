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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_selectExecutable_clicked()
{
    QString location = "/home/" + user;
    executable = QFileDialog::getOpenFileName(this, "Select executable", location);
}


void MainWindow::on_selectIcon_clicked()
{
    QString location = "/home/" + user;
    icon = QFileDialog::getOpenFileName(this, "Select icon", location);
}

void MainWindow::on_lineEdit_editingFinished()
{
    programName = ui->lineEdit->text();
}

void MainWindow::on_selectDestination_clicked()
{
    QString location = "/home/" + user + "/Desktop";
    destination = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    location,
                                                    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
}


void MainWindow::on_generateEntry_clicked()
{
    if (executable.isEmpty())
    {
        QMessageBox::information(this,"..", "You need to select an executable!");
        return;
    }

    int result = access(executable.toStdString().c_str(), X_OK);
    if(result != 0) {
        QMessageBox::information(this, "..", "Warning: The selected executable does not have the required execution permissions.");
    }

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

