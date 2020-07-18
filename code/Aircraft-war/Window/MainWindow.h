#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <VisualObject.h>
//#include <Socket.h>
#include <Aircraft-war\window\sink\MainWindowCommandSink.h>
#include <Aircraft-war\window\sink\MainWindowPropertySink.h>
#include <Aircraft-war\Socket.h>
#include <Aircraft-war\view\VisualObject.h>
#include <Utility\ViewModel\planeviewmodel.h>
#include <Utility\ViewModel\bulletviewmodel.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    GraphicsView m_GV;
    GraphicsScene m_GS;
    VisualObjects Q_Plane, Q_Bullet;//, Q_Item;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initScene();
    void keyPressEvent(QKeyEvent *ev)
    void mouseMoveEvent(QMouseEvent* event)
    void mousePressEvent(QMouseEvent* event)
    void mouseReleaseEvent(QMouseEvent* event)
    void set_mouse_command(const std::shared_ptr<ICommandBase>& cmd) throw();
    void set_key_command(const std::shared_ptr<ICommandBase>& cmd) throw();
    void set_rankadd_command(const std::shared_ptr<ICommandBase>& cmd) throw();
    void set_restart_command(const std::shared_ptr<ICommandBase>& cmd) throw();
	std::shared_ptr<IPropertyNotification> get_PropertySink() throw();
	std::shared_ptr<ICommandNotification> get_CommandSink() throw();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<ICommandBase> m_cmdrank, m_cmdrst, m_cmdkey, m_cmdmouse;
	std::shared_ptr<MainWindowPropertySink> m_sinkPropPlane, m_sinkPropBullet;
    std::shared_ptr<MainWindowGameStateSink> m_sinkPropGameState;
	std::shared_ptr<MainWindowCommandSink> m_sinkCommRank, m_sinkCommRst, m_sinkCommKey, m_sinkCommMouse;
};

class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT

public:
    GraphicsScene(qreal x, qreal y, qreal width, qreal height, QObject* parent = nullptr);
    ~GraphicsScene();
};

class GraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    GraphicsView(QGraphicsScene* scene, QWidget* parent = nullptr);
    ~GraphicsView();
};


#endif // MAINWINDOW_H