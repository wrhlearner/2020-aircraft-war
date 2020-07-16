#include "bulletviewmodel.h"

bulletviewmodel::bulletviewmodel():m_bm(std::make_shared<bulletmodel>()),
								m_cmd(std::make_shared<Command>(this)),
								m_sink(std::make_shared<modelsinks>(this)),
								m_cmd_rankadd(std::make_shared<RankAddCommand>(this))
{
}

bulletmodel& bulletviewmodel::GetModel() throw()
{
	return *m_bm;
}
void bulletviewmodel:SetModel(const std::shared_ptr<bulletmodel>& model){
	m_bm = model;
	m_bm->AddPropertyNotification(std::static_pointer_cast<IPropertyNotification>(m_sink));
}
std::shared_ptr<ICommandBase> bulletviewmodel::get_rankadd_command() throw()
{
    return std::static_pointer_cast<ICommandBase>(m_cmd_rankadd );
}
bool bulletview::rankadd(UserParameter userinfo){
    return m_bm->rankadd(userinfo);
}
