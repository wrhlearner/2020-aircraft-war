#include "planeviewmodel.h"
#include <QtCore/QVector>
#include "../common/Common.h"
#include"../model/planemodel.h"
planeviewmodel::planeviewmodel():m_pm(std::make_shared<planemodel>()),
								m_cmd(std::make_shared<Command>(this)),
								m_sink(std::make_shared<modelsinks>(this)),
								m_cmd_restart(std::make_shared<RestartCommand>(this))
{  
}

planemodel& planeviewmodel::GetModel() throw()
{
	return *m_pm;
}
void planeviewmodel:SetModel(const std::shared_ptr<planemodel>& model){
	m_pm = model;
	m_pm->AddPropertyNotification(std::static_pointer_cast<IPropertyNotification>(m_sink));
}
std::shared_ptr<ICommandBase> planeviewodel::get_restart_command() throw()
{
    return std::static_pointer_cast<ICommandBase>(m_cmd_restart);
}
bool planeviewodel::restart(int m_X, int m_Y)
{
    return m_pm->restart(m_X,m_Y);
}
