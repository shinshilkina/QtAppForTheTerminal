#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtAppForTheTerminal.h"
#include <qstring.h>
#include <QtPrintSupport/qprinter.h>
#include <QStorageInfo>


class QtAppForTheTerminal : public QMainWindow
{
	Q_OBJECT

public:
	QtAppForTheTerminal(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtAppForTheTerminalClass ui;
	QString filename;

private slots:

	void fopenFileSystem();
	//void fprintThisFile();


};
