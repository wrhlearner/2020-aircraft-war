#include "App.h"
#include "window/MainWindow.h"

PlaneApp::PlaneApp()
{
}

PlaneApp::~PlaneApp() throw()
{
}

bool PlaneApp::Init(Mainwindow& wndMain)
{
	//objects
	m_wndMain = wndMain;
	std::shared_ptr<bulletmodel> spbulletModel(std::make_shared<bulletmodel>());
    std::shared_ptr<planemodel> spplaneModel(std::make_shared<planeModel>());
	m_spbulletViewModel = std::make_shared<bulletviewmodel>();
    m_spplaneViewModel = std::make_shared<planeviewmodel>();
	m_spbulletviewmodel->SetModel(spbulletmodel);
    m_spplaneviewmodel->SetModel(spplanemodel);
	//binding
	// properties
	    wndMain.Q_Plane.set_Name(m_spplaneviewmodel->get_StopNumber());
	    wndMain.Q_Bullet.set_Name(m_spbulletviewmodel->get_CityName());
	// commands
	wndMain.set_rankadd_command(m_spbulletviewmodel->get_rankadd_command());
    wndMain.set_restart_command(m_spplaneviewmodel->get_restart_command());
	// notifications
	m_spbulletviewmodel->AddPropertyNotification(m_wndMain.get_BulletPropertySink());
    m_spbulletviewmodel->AddCommandNotification(m_wndMain.get_RankCommandSink());
    m_spplaneviewmodel->AddPropertyNotification(m_wndMain.get_PlanePropertySink());
	m_spplaneviewmodel->AddCommandNotification(m_wndMain.get_RstCommandSink());

	return true;
}

void PlaneApp::Show()
{
	m_wndMain.Show();
}
