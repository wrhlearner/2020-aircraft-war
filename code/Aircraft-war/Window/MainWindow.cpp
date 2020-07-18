#include "Config.h"
#include "MainWindow.h"
#include "./ui_mainwindow.h"
#include <Utility\Common\NormalNpc.h>
#include <QKeyEvent>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    m_sinkProperty(std::make_shared<MainWindowPropertySink>(this)),
	m_sinkCommand(std::make_shared<MainWindowCommandSink>(this))
{
    ui->setupUi(this);
    initScene();
}

void MainWindow::set_rankadd_command(const std::shared_ptr<ICommandBase>& cmd) throw()
{
	m_cmdrank = cmd;
}

void MainWindow::set_restart_command(const std::shared_ptr<ICommandBase>& cmd) throw()
{
	m_cmdrst = cmd;
}

void MainWindow::set_key_command(const std::shared_ptr<ICommandBase>& cmd) throw()
{
	m_cmdkey = cmd;
}

void MainWindow::set_mouse_command(const std::shared_ptr<ICommandBase>& cmd) throw()
{
	m_cmdmouse = cmd;
}

std::shared_ptr<IPropertyNotification> MainWindow::get_PlanePropertySink() throw()
{
	return std::static_pointer_cast<IPropertyNotification>(m_sinkPropPlane);
}

std::shared_ptr<IPropertyNotification> MainWindow::get_BulletPropertySink() throw()
{
	return std::static_pointer_cast<IPropertyNotification>(m_sinkPropBullet);
}

std::shared_ptr<ICommandNotification> MainWindow::get_RankCommandSink() throw()
{
	return std::static_pointer_cast<ICommandNotification>(m_sinkCommRank);
}

std::shared_ptr<ICommandNotification> MainWindow::get_RstCommandSink() throw()
{
	return std::static_pointer_cast<ICommandNotification>(m_sinkCommRst);
}

std::shared_ptr<ICommandNotification> MainWindow::get_KeyCommandSink() throw()
{
	return std::static_pointer_cast<ICommandNotification>(m_sinkCommKey);
}

std::shared_ptr<ICommandNotification> MainWindow::get_MouseCommandSink() throw()
{
	return std::static_pointer_cast<ICommandNotification>(m_sinkCommMouse);
}

void MainWindow::initScene(){
    setWindowTitle(GAME_TITLE);
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    setWindowIcon(QIcon(GAME_ICON));
    m_GV.setScene(&m_GS);
    Q_Plane.getGS(std::static_pointer_cast<GraphicsScene>(*m_GS));
    Q_Bullet.getGS(std::static_pointer_cast<GraphicsScene>(*m_GS));
} 

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseMoveEvent(QMouseEvent* event){
    int x = event->x;
    int y = event->y;
    m_cmdmouse->SetParameter(x,y,"Move");
    m_cmdmouse->exec();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
   {
        m_cmdmouse->SetParameter(1,0,"Press");
        m_cmdmouse->exec;
    }
    else if(event->button() == Qt::RightButton)
   {
        m_cmdmouse->SetParameter(0,1,"Press");
        m_cmdmouse->exec;
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
   {
        m_cmdmouse->SetParameter(1,0,"Release");
        m_cmdmouse->exec;
    }
    else if(event->button() == Qt::RightButton)
   {
        m_cmdmouse->SetParameter(0,1,"Release");
        m_cmdmouse->exec;
    }
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
　　if (ev->key() == Qt::Key_Up)
　　{
        //qDebug() << "press key up";
        m_cmdkb->SetParameter("Key_Up");
        m_cmdkb->exec();
        return;
　　}
　　if (ev->key() == Qt::Key_Down)
　　{
        //qDebug() << "press key down";
        m_cmdkb->SetParameter("Key_Down");
        m_cmdkb->exec();
        return;
　　}
　　if (ev->key() == Qt::Key_Left)
　　{
        //qDebug() << "press key left";
        m_cmdkb->SetParameter("Key_Left");
        m_cmdkb->exec();
        return;
　　}
　　if (ev->key() == Qt::Key_Right)
　　{
        //qDebug() << "press key right";
        m_cmdkb->SetParameter("Key_Right");
        m_cmdkb->exec();
        return;
　　}
    if (ev->key() == Qt::Key_Z)
    {
        m_cmdkb->SetParameter("Key_Z");
        m_cmdkb->exec();
        //qDebug() << "press shot key";
        return;
    }
    if (ev->key() == Qt::Key_X)
    {
        m_cmdkb->SetParameter("Key_X");
        m_cmdkb->exec();
        //qDebug() << "press bomb key";
        return;
    }

    if (ev->key() == Qt::Key_R)
    {
        m_cmdrst->exec();
        //qDebug() << "press reset key";
        return;
    }
}

void GraphicsScene::Update(std::list<FlyingObject>& Prop, int PropType)
{
/*     if(PropType == 0){
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
    } */
    render();
}