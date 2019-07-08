#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtAppForTheTerminal.h"

class QtAppForTheTerminal : public QMainWindow
{
	Q_OBJECT

public:
	QtAppForTheTerminal(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtAppForTheTerminalClass ui;
};
