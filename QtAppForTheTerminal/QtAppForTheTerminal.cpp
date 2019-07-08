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
	foreach(const QStorageInfo &storage, QStorageInfo::mountedVolumes()) {
		if (storage.isValid() && storage.isReady()) {
			if (!storage.isReadOnly()) {
				ui.labelFilename->setText(storage.rootPath());
				filename = storage.rootPath();
			}
		}
	}
	//�������� ���������� �� ����� ������������� ����������
	QPrinter printer;
	filename = QFileDialog::getOpenFileName(nullptr, "Open File", filename, "File(*.pdf *.png *.xpm *.jpg *.txt *.doc *.docx)");
	
	//UpdateLabel(filename);
}