#pragma once

#include <Aircraft-war\Socket.h>

class MainWindow;

class MainWindowPropertySink : public IPropertyNotification
{
public:
	MainWindowPropertySink(MainWindow* pW) throw();

	virtual void OnPropertyChanged(const std::string& str, int type, VisualObject *VOptr);

private:
	MainWindow* m_pW;
};
