#include "QtAppForTheTerminal.h"
#include <QFileDialog>
#include <QTextDocument>
#include <QtGui>
#include <QTextEdit>
#include "eztwain.h"
#include <wia.h>
#include <windows.h>


QtAppForTheTerminal::QtAppForTheTerminal(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.buttonOpenFile, SIGNAL(released()),
		this, SLOT(fopenFileSystem()));
	connect(ui.buttonPrint, SIGNAL(released()),
		this, SLOT(fprintThisFile()));
}
void QtAppForTheTerminal::fopenFileSystem()
{
	//-------------определение файла через проводник-----------------
	//отображение подключенных устройств
	QStorageInfo storage = QStorageInfo::root();
	foreach(const QStorageInfo &storage, QStorageInfo::mountedVolumes()) {
		if (storage.isValid() && storage.isReady()) {
			if (!storage.isReadOnly()) {
				ui.labelFilename->setText(storage.rootPath());
				filename = storage.rootPath();
			}
		}
	}
	//открытие проводника на папке подключенного устройства
	QPrinter printer;
	filename = QFileDialog::getOpenFileName(nullptr, "Open File", filename, "File(*.pdf *.png *.xpm *.jpg *.txt *.doc *.docx)");
	
	ui.labelFilename->setText(filename);
}
void QtAppForTheTerminal::fprintThisFile()
{
	
	//auto hInstance = ShellExecute(GetActiveWindow(), L"print", (const wchar_t*)filename.utf16(), NULL, NULL, SW_HIDE);

	//SCANNER
	 /*TWAIN_SetHideUI(TRUE);
	TWAIN_SetIndicators(FALSE);
	TWAIN_SetFileAppendFlag(FALSE);
	TWAIN_SetJpegQuality(75);
	if (TWAIN_OpenDefaultSource()) {
		TWAIN_SetXferCount(1);
		if (!TWAIN_SetAutoScan(FALSE)) {
			MessageBox(NULL, L"SetAutoScan(FALSE) failed - scanner cannot single-scan?", L"TWAIN Alert", MB_ICONINFORMATION | MB_OK);
		}
		// If you can't get a Window handle, use NULL:
		TWAIN_AcquireToFilename(::GetActiveWindow(), "c:\\scan\\image1.tif");
	}
	if (TWAIN_LastErrorCode()) {
		TWAIN_ReportLastError("Unable to scan.");
	}*/


/*	IWiaDevMgr *pWiaDevMgr;
	HRESULT hr;
	hr = CoCreateInstance(CLSID_WiaDevMgr,
		NULL,
		CLSCTX_LOCAL_SERVER,
		IID_IWiaDevMgr,
		(void*)&pWiaDevMgr);
	*/
	
	// 
// RawDataToPrinter - sends binary data directly to a printer 
//  
// szPrinterName: NULL-terminated string specifying printer name 
// lpData:        Pointer to raw data bytes 
// dwCount        Length of lpData in bytes 
//  
// Returns: TRUE for success, FALSE for failure. 
	
	
	std::string str = "Hello World";
	//bool blubb = RawDataToPrinter((LPTSTR)("PRINTER_NAME"), (LPBYTE)str.c_str(), str.size());
	//BOOL RawDataToPrinter(LPTSTR szPrinterName, LPBYTE lpData, DWORD dwCount)
	char  result[MAX_PATH] = { '\0' };
	DWORD length = MAX_PATH;
	GetDefaultPrinter((LPTSTR)result, &length);
	LPTSTR szPrinterName = (LPTSTR)result;
	//bool blubb = RawDataToPrinter((LPTSTR)("\\\\localhost\\DefaultPrinter"), (LPBYTE)str.c_str(), str.size());
	BOOL     bStatus = FALSE;
	HANDLE     hPrinter = NULL;
	DOC_INFO_1 DocInfo;
	DWORD      dwJob = 0L;
	DWORD      dwBytesWritten = 0L;

	LPBYTE lpData = (LPBYTE)str.c_str();		/////////////////////////////////////---------------------------!!!!!!!!!!!!!!!!!!!!!!!!!!
	DWORD dwCount = str.size();					//////////////////////////////////////---------------------------!!!!!!!!!!!!!!!!!!!!!!!!!!
	
	// Open a handle to the printer. 
	bStatus = OpenPrinter(szPrinterName, &hPrinter, NULL);
	if (bStatus) {
		
		// Fill in the structure with info about this "document." 
		DocInfo.pDocName = (LPTSTR)(L"asasin");
		DocInfo.pOutputFile = NULL;
		DocInfo.pDatatype = (LPTSTR)(L"TEXT");

		// Inform the spooler the document is beginning. 
		dwJob = StartDocPrinter(hPrinter, 1, (LPBYTE)&DocInfo);
		if (dwJob > 0) {
			// Start a page. 
			bStatus = StartPagePrinter(hPrinter);
			if (bStatus) {
				// Send the data to the printer. 
				bStatus = WritePrinter(hPrinter, lpData, dwCount, &dwBytesWritten);
				EndPagePrinter(hPrinter);
			}
			// Inform the spooler that the document is ending. 
			EndDocPrinter(hPrinter);
		}
		// Close the printer handle. 
		ClosePrinter(hPrinter);
	}
	// Check to see if correct number of bytes were written. 
	if (!bStatus || (dwBytesWritten != dwCount)) {
		bStatus = FALSE;
	}
	else {
		bStatus = TRUE;
	}
	//return bStatus;
}




