#include "modelsinks.h"
#include "../modelsinks.h"

planemodelSink(planeviewmodel* pm) throw():m_pm{}
bulletmodelSink(bulletviewmodel* bm) throw():m_bm{}

void modelsinks::OnPropertyChanged(const std::string& str)
{
	if( str == "restart" ) {
		m_pVM->Fire_OnPropertyChanged(str);
	}
	else if( str == "rankadd" ) {
		m_pVM->Fire_OnPropertyChanged(str);
	}
}
