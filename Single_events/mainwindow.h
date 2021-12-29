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

    void text_to_edit(QString text);    // Запись в текст эдитор
    void text_to_edit_delete();         // Удаление элемента

signals:
    void signalrunMP(QStringList files);

private slots:
    void on_Button_Open_clicked();

    void on_Button_Next_clicked();

    void on_Button_Before_clicked();

private:
    Ui::MainWindow *ui;
    Main_processing *MP;
    QThread *threadMP;
};
#endif // MAINWINDOW_H
