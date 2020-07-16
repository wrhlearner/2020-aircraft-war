#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <VisualObject.h>
#include <Socket.h>
#include <Aircraft-war\window\sink\MainWindowCommandSink.h>
#include <Aircraft-war\window\sink\MainWindowPropertySink.h>
#include <Aircraft-war\Socket.h>
#include <Aircraft-war\view\VisualObject.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    GraphicsView m_GV;
    GraphicsScene m_GS;
    std::list<VisualObject> VO_Npc;//, VO_Boss, VO_Bullet, VO_Item;
    VisualObject VO_Player;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initScene();

    void set_keyCommand(const int& keyv) throw();
    void set_QueryCommand(const std::shared_ptr<ICommandBase>& cmd) throw();
    MainWindow& get_WindowPointer() throw();
	std::shared_ptr<IPropertyNotification> get_PropertySink() throw();
	std::shared_ptr<ICommandNotification> get_CommandSink() throw();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<ICommandBase> m_cmdQuery;
	std::shared_ptr<MainWindowPropertySink> m_sinkProperty;
	std::shared_ptr<MainWindowCommandSink> m_sinkCommand;
};

class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT

public:
    GraphicsScene(qreal x, qreal y, qreal width, qreal height, QObject* parent = nullptr);
    ~GraphicsScene();

    void Update(std::list<NormalNpc>& Prop, int PropType);

};

class GraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    GraphicsView(QGraphicsScene* scene, QWidget* parent = nullptr);
    ~GraphicsView();
};


#endif // MAINWINDOW_H