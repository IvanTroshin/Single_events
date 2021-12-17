#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    threadMP = new QThread(this);
    connect(this, SIGNAL(destroyed()), threadMP, SLOT(quit()));

    MP = new Main_processing();
    connect(this, &MainWindow::signalrunMP, MP, &Main_processing::runRP);

    MP->moveToThread(threadMP);
    threadMP->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

