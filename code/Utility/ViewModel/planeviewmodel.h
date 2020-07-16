#ifndef PLANEVIEWMODEL_H
#define PLANEVIEWMODEL_H


#include <QtCore/QVector>
#include "../command/Command.h"
#include"../model/planemodel.h"
#include "../sinks/modelsinks.h"
class planeviewmodel:public Proxy_PropertyNotification<BusViewModel>,
					public Proxy_CommandNotification<BusViewModel> 
{
private:
    std::shared_ptr<planemodel> m_pm;
    std::shared_ptr<Command> m_cmd;
	std::shared_ptr<modelsinks> m_sink;
	std::shared_ptr<RestartCommand> m_cmd_restart;
public:
    planeviewmodel();
    planemodel& GetModel() throw();
    void SetModel(const std::shared_ptr<planemodel>& model);
    std::shared_ptr<ICommandBase> get_restart_command() throw();
    bool restart(int m_X, int m_Y);
};

#endif // PLANEVIEWMODEL_H
