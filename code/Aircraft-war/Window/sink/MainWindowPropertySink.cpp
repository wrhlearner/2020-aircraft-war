#include "MainWindowPropertySink.h"
#include "../MainWindow.h"

MainWindowPropertySink::MainWindowPropertySink(MainWindow* pW) throw() : m_pW(pW)
{
}

void MainWindowPropertySink::OnPropertyChanged(const std::string& str, int type, VisualObject *VOptr)
{
	if(str == "Update"){
		m_pW->m_GV->paint();
	}
	else if(str == "Create"){
		if(type == 0){
			m_pW->Q_Plane->createVO(VOptr);
		}
		else if(type == 1){
			m_pW->Q_Bullet->createVO(VOptr);
		}
	}
	else if(str == "Delete"){
		if(type == 0){
			m_pW->Q_Plane->deleteVO(VOptr);
		}
		else if(type == 1){
			m_pW->Q_Bullet->deleteVO(VOptr);
		}
	}
}
/* 	if( Type == "0") {
		m_pW->VO_Plane.Update();
	}
	else if ( Type == "1") {
		m_pW->VO_Bullet.Update();
	} */