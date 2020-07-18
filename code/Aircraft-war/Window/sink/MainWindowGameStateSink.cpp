#include "MainWindowCommandSink.h"

#include "../MainWindow.h"

MainWindowCommandSink::MainWindowCommandSink(MainWindow* pW) throw() : m_pW(pW)
{
}

void MainWindowCommandSink::OnCommandComplete(const std::list<int>& Prop)
{
	//还需要一个widget去显示……等下做
}