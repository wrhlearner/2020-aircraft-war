#pragma once

#include <Aircraft-war/window/MainWindow.h>
#include <QApplication>
#include <QResource>
#include <Config.h>
#include "window/MainWindow.h"
#include "model/planemodel.h"
#include "model/bulletmodel.h"
#include "viewmodel/planeviewmodel.h"
#include "viewmodel/bulletviewmodel.h"

class PlaneApp
{
public:
	PlaneApp();
	~PlaneApp() throw();

	bool Init();
	void Show(int nCmdShow = SW_SHOWDEFAULT);

private:
	MainWindow  m_wndMain;
	std::shared_ptr<planeViewModel>  m_spplaneModel;
    std::shared_ptr<bulletviewmodel> m_spbulletModel;

};
