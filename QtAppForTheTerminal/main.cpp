#include "QtAppForTheTerminal.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtAppForTheTerminal w;
	w.show();
	return a.exec();
}
