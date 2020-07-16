#ifndef BULLETVIEWMODEL_H
#define BULLETVIEWMODEL_H

#include <QtCore/QVector>
#include "../command/Command.h"
#include"../model/bulletmodel.h"
#include "../sinks/modelsinks.h"

class bulletviewmodel£ºpublic Proxy_PropertyNotification<BusViewModel>,
					public Proxy_CommandNotification<BusViewModel>
{
private:
    std::shared_ptr<bulletmodel> m_bm;
	std::shared_ptr<Command> m_cmd;
	std::shared_ptr<modelsinks> m_sink;
	std::shared_ptr<RankAddCommand > m_cmd_rankadd;
	
public:
    bulletviewmodel();
    bulletmodel& GetModel() throw();
    void SetModel(const std::shared_ptr<bulletmodel>& model);
    std::shared_ptr<ICommandBase> get_rankadd_command() throw();
    bool rankadd(UserParameter userinfo);
    
    
};

#endif // BULLETVIEWMODEL_H
