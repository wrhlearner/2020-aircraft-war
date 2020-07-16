#include "MainWindowCommandSink.h"

#include "../MainWindow.h"

MainWindowCommandSink::MainWindowCommandSink(MainWindow* pW) throw() : m_pW(pW)
{
}

void MainWindowCommandSink::OnCommandComplete(const std::string& str, bool bOK)
{
	if( str == "KBIO" ) {
		if( !bOK ) {
			QMessageBox::critical(NULL, "I/O ERROR", "Unexpected error.", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		}
	}
	else if( str == "CONF"){
		if( !bOK ) {
			QMessageBox::critical(NULL, "Conf ERROR", "Unexpected error.", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		}
	}
}