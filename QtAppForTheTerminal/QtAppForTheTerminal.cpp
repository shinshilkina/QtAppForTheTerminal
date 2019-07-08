#include "QtAppForTheTerminal.h"
#include <QFileDialog>

QtAppForTheTerminal::QtAppForTheTerminal(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.buttonOpenFile, SIGNAL(released()),
		this, SLOT(fopenFileSystem()));
	//connect(ui.printThisFile, SIGNAL(released()),
	//	this, SLOT(fprintThisFile()));
}
void QtAppForTheTerminal::fopenFileSystem()
{
	//-------------����������� ����� ����� ���������-----------------
	//����������� ������������ ���������
	QStorageInfo storage = QStorageInfo::root();
	ui.labelFilename->setText(storage.rootPath()+" "+ storage.name());

	
	//�������� ����������
	QPrinter printer;
	filename = QFileDialog::getOpenFileName(nullptr, "Open File","C:\\", "File(*.pdf *.png *.xpm *.jpg *.txt *.doc *.docx)");
	
	//UpdateLabel(filename);
}