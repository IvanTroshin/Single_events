#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    threadMP = new QThread(this); // Создание потока
    connect(this, SIGNAL(destroyed()), threadMP, SLOT(quit())); // удаление патока

    MP = new Main_processing(); // Вызов класса
    connect(this, &MainWindow::signalrunMP, MP, &Main_processing::runRP);

    MP->moveToThread(threadMP); // Перезача класса в поток
    threadMP->start(); // Запуск потока

    connect(MP, &Main_processing::text_to_edit_signal, this, &MainWindow::text_to_edit); // запись в textediter
    connect(MP, &Main_processing::text_to_edit_del_delete, this, &MainWindow::text_to_edit_delete);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::text_to_edit(QString text)
{
    ui->textEdit->insertPlainText(text);
}

void MainWindow::text_to_edit_delete()
{
    ui->textEdit->textCursor().deletePreviousChar();
}

QStringList files;
void MainWindow::on_Button_Open_clicked()
{
    files = QFileDialog::getOpenFileNames(this, "Open", "C://", "*.txt");       // Выбрать несколько файлов

    ui->Button_Open->setEnabled(false); // Зажим кнопки
    ui->Button_Before->setEnabled(false); // Зажим кнопки

//    ui->textEdit->setTextColor(QColor(0, 0, 0, 200));
    ui->textEdit->insertPlainText("--------------------\n");
    ui->textEdit->insertPlainText("Start read");
    ui->textEdit->insertPlainText("\r");
    ui->textEdit->insertPlainText("--------------------\n");

    ui->textEdit->insertPlainText("Number of files:");

    ui->textEdit->insertPlainText(QString::number(files.size()));

//    ui->Button_Before->setEnabled(true); // Зажим кнопки

//    ui->Save->setEnabled(true); // Зажим кнопки
}


void MainWindow::on_Button_Next_clicked()
{
    ui->Button_Before->setEnabled(true); // Зажим кнопки
    signalrunMP(files);   // Испускание сигнала для потока
}


void MainWindow::on_Button_Before_clicked()
{
    text_to_edit("10");
}

