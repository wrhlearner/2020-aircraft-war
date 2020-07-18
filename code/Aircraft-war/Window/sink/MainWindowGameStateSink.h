#pragma once

#include <Socket.h>

class MainWindow;

class MainWindowGameStateSink : public ICommandNotification
{
public:
	MainWindowCommandSink(MainWindow* pW) throw();

	virtual void OnCommandComplete(const std::list<int>& Prop);

private:
	MainWindow* m_pW;
};
