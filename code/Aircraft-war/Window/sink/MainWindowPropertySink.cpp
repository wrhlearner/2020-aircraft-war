#include "MainWindowPropertySink.h"
#include "../MainWindow.h"
#include <list>

MainWindowPropertySink::MainWindowPropertySink(MainWindow* pW) throw() : m_pW(pW)
{
}

void MainWindowPropertySink::OnPropertyChanged(const list<Npc>& Prop, const int& Type)
{
	if( Type == "0" or Type == "1" ) {
		m_pW->m_GS.Update(Prop,Type);
	}
}