#include "Config.h"
#include "MainWindow.h"
#include "./ui_mainwindow.h"
#include <Utility\Common\NormalNpc.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    m_sinkProperty(std::make_shared<MainWindowPropertySink>(this)),
	m_sinkCommand(std::make_shared<MainWindowCommandSink>(this))
{
    ui->setupUi(this);
}


void MainWindow::set_QueryCommand(const std::shared_ptr<ICommandBase>& cmd) throw()
{
	m_cmdQuery = cmd;
}

MainWindow& get_WindowPointer() throw()
{
    MainWindow& p_mw = this;
    return p_mw;
}

std::shared_ptr<IPropertyNotification> MainWindow::get_PropertySink() throw()
{
	return std::static_pointer_cast<IPropertyNotification>(m_sinkProperty);
}
std::shared_ptr<ICommandNotification> MainWindow::get_CommandSink() throw()
{
	return std::static_pointer_cast<ICommandNotification>(m_sinkCommand);
}

void MainWindow::initScene(){
    setWindowTitle(GAME_TITLE);
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    setWindowIcon(QIcon(GAME_ICON));
} 

MainWindow::~MainWindow()
{
    delete ui;
}

void GraphicsScene::Update(std::list<NormalNpc>& Prop, int PropType)
{
    if(PropType == 0){
        std::list<VisualObject>::iterator Npc_VO_iter = VO_Npc.begin();
        while (Npc_VO_iter != Prop.end()){
            ~Npc_VO_iter;
        }
        std::list<NPC>::iterator Npc_iter = Prop.begin();
        while (Npc_iter != Prop.end()){
            VisualObject New_NPC;
            New_NPC(getPixmap(Npc_iter->GetPictureMap, Npc_iter->GetName),*m_GS);
            New_NPC.setOffset(Npc_iter->GetPositionX(),Npc_iter->GetPositionY());
            VO_Npc.push_back(New_NPC);
            ~New_NPC();
        }
        m_GS.show();
    }
}