#include "MainWindowCommandSink.h"

#include "../MainWindow.h"

MainWindowCommandSink::MainWindowCommandSink(MainWindow* pW) throw() : m_pW(pW)
{
}

void MainWindowCommandSink::OnCommandComplete(const std::string& str, bool bOK)
{
	if( str == "KBIO" ) {
		if( !bOK ) {
			QMessageBox::critical(NULL, "Keyboard I/O ERROR", "Unexpected error.", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		}
	}
	else if( str == "MSIO"){
		if( !bOK ) {
			QMessageBox::critical(NULL, "Mouse I/O ERROR", "Unexpected error.", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		}
	}
	else if( str == "RST"){
		if( !bOK ) {
			QMessageBox::critical(NULL, "Reset ERROR", "Unexpected error.", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		}
	}
	else if( str == "RANK"){
		if( !bOK ) {
			QMessageBox::critical(NULL, "Rank ERROR", "Unexpected error.", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		}
	}
}