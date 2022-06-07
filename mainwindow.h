#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString user = "";
    QString executable = "";
    QString icon = "";
    QString programName = "";
    QString destination = "";

private slots:
    void on_selectExecutable_clicked();

    void on_selectIcon_clicked();

    void on_lineEdit_editingFinished();

    void on_selectDestination_clicked();

    void on_generateEntry_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
