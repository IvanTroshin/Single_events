/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *Before;
    QPushButton *Next;
    QPushButton *Open;
    QVBoxLayout *verticalLayout;
    QCustomPlot *Plot_3D_up_dc;
    QCustomPlot *Plot_3D;
    QCustomPlot *Plot_down_dc;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout_2->addWidget(textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Before = new QPushButton(centralwidget);
        Before->setObjectName(QString::fromUtf8("Before"));

        horizontalLayout->addWidget(Before);

        Next = new QPushButton(centralwidget);
        Next->setObjectName(QString::fromUtf8("Next"));

        horizontalLayout->addWidget(Next);


        verticalLayout_2->addLayout(horizontalLayout);

        Open = new QPushButton(centralwidget);
        Open->setObjectName(QString::fromUtf8("Open"));
        QFont font;
        font.setPointSize(9);
        Open->setFont(font);

        verticalLayout_2->addWidget(Open);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Plot_3D_up_dc = new QCustomPlot(centralwidget);
        Plot_3D_up_dc->setObjectName(QString::fromUtf8("Plot_3D_up_dc"));
        Plot_3D_up_dc->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(Plot_3D_up_dc);

        Plot_3D = new QCustomPlot(centralwidget);
        Plot_3D->setObjectName(QString::fromUtf8("Plot_3D"));
        Plot_3D->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(Plot_3D);

        Plot_down_dc = new QCustomPlot(centralwidget);
        Plot_down_dc->setObjectName(QString::fromUtf8("Plot_down_dc"));
        Plot_down_dc->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(Plot_down_dc);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 3);
        verticalLayout->setStretch(2, 1);

        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 4);

        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Before->setText(QCoreApplication::translate("MainWindow", "Before", nullptr));
        Next->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        Open->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
