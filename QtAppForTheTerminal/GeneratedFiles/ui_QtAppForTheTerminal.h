/********************************************************************************
** Form generated from reading UI file 'QtAppForTheTerminal.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTAPPFORTHETERMINAL_H
#define UI_QTAPPFORTHETERMINAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtAppForTheTerminalClass
{
public:
    QWidget *centralWidget;
    QPushButton *buttonOpenFile;
    QLabel *labelFilename;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtAppForTheTerminalClass)
    {
        if (QtAppForTheTerminalClass->objectName().isEmpty())
            QtAppForTheTerminalClass->setObjectName(QString::fromUtf8("QtAppForTheTerminalClass"));
        QtAppForTheTerminalClass->resize(600, 400);
        centralWidget = new QWidget(QtAppForTheTerminalClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        buttonOpenFile = new QPushButton(centralWidget);
        buttonOpenFile->setObjectName(QString::fromUtf8("buttonOpenFile"));
        buttonOpenFile->setGeometry(QRect(440, 60, 121, 28));
        labelFilename = new QLabel(centralWidget);
        labelFilename->setObjectName(QString::fromUtf8("labelFilename"));
        labelFilename->setGeometry(QRect(30, 60, 391, 16));
        QtAppForTheTerminalClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtAppForTheTerminalClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        QtAppForTheTerminalClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtAppForTheTerminalClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtAppForTheTerminalClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtAppForTheTerminalClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtAppForTheTerminalClass->setStatusBar(statusBar);

        retranslateUi(QtAppForTheTerminalClass);

        QMetaObject::connectSlotsByName(QtAppForTheTerminalClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtAppForTheTerminalClass)
    {
        QtAppForTheTerminalClass->setWindowTitle(QCoreApplication::translate("QtAppForTheTerminalClass", "QtAppForTheTerminal", nullptr));
        buttonOpenFile->setText(QCoreApplication::translate("QtAppForTheTerminalClass", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        labelFilename->setText(QCoreApplication::translate("QtAppForTheTerminalClass", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtAppForTheTerminalClass: public Ui_QtAppForTheTerminalClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTAPPFORTHETERMINAL_H
