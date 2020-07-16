#include "command.h"
#include "../planeviewmodel.h"
#include "../bulletviewmodel.h"

Command(planeviewmodel* p) throw():m_pm(pm){
}
Command(bulletviewmodel* p) throw():m_bm(bm){
}
void Command::SetParameter(const std::any& param)
{
	m_param = std::any_cast<TwoStrings>(param);
}

void Command::Exec()
{
	bool bResult = m_pm->Query(m_param.get_S1(), m_param.get_S2());
	m_pm->Fire_OnCommandComplete("query", bResult);
	bool bResult = m_bm->Query(m_param.get_S1(), m_param.get_S2());
	m_bm->Fire_OnCommandComplete("query", bResult);
}
