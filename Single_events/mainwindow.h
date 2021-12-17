#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "main_processing.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void signalrunMP(QStringList files);

private:
    Ui::MainWindow *ui;
    Main_processing *MP;
    QThread *threadMP;
};
#endif // MAINWINDOW_H
