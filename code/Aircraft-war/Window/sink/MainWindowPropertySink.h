#pragma once

#include <Aircraft-war\Socket.h>

class MainWindow;

class MainWindowPropertySink : public IPropertyNotification
{
public:
	MainWindowPropertySink(MainWindow* pW) throw();

	virtual void OnPropertyChanged(const std::list<Npc>& Prop, const int& Type);

private:
	MainWindow* m_pW;
};
