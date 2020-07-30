#ifndef GLOBAL_H
#define GLOBAL_H

//引用Qt头文件
/*****************************************************************************/
//Qt通用和图形视图框架头文件
#include <QApplication>
#include <QObject>
#include <QtWidgets>
#include <QWidget>
#include <QGraphicsScene>
#include <QList>
//菜单头文件
#include <QDialog>
#include <QStackedLayout>
#include <QVBoxLayout>
//部件头文件
#include <QPushButton>
//debug
#include <QDebug>

//引用其他头文件
/*****************************************************************************/
#include <math.h>

//游戏常数定义
/*****************************************************************************/
//Name
#define BLOODSUPPLYNAME 1
#define BOMBSUPPLYNAME 2
#define BULLETSUPPLYNAME 3

#define PLAYERPLANENAME 4
#define ENEMYPLANENAME 5

#define PLAYERBULLETNAME 6
#define ENEMYBULLETNAME 7

#define BOMBNAME 8
//Size
#define SCENEWIDTH  500
#define SCENEHEIGHT  800

#define BLOODSUPPLYSIZE 30
#define BOMBSUPPLYSIZE 30
#define BULLETSUPPLYSIZE 30

#define PLAYERPLANESIZE 40
#define FISHSIZE 50
#define BOSSSIZE 200

#define PLAYERBULLETSIZE 20
#define FISHBULLETSIZE1 20
#define FISHBULLETSIZE2 20
#define FISHBULLETSIZE3 20

#define BOSSBULLETSIZE1 80
#define BOSSBULLETWIDTH2 200
#define BOSSBULLETHEIGHT2 40
#define BOSSBULLETSIZE3 200
#define BOSSBULLETWIDTH4 200
#define BOSSBULLETHEIGHT4 200

#define BOMBSIZE 30
//Speed
#define BLOODSUPPLYSPEED 20
#define BOMBSUPPLYSPEED 20
#define BULLETSUPPLYSPEED 20

#define PLAYERPLANESPEED 10
#define FISHSPEED 10
#define BOSSSPEED 2

#define PLAYERBULLETSPEED 50

#define FISHBULLETSPEED1 20
#define FISHBULLETSPEED2 20
#define FISHBULLETSPEED3 20

#define BOSSBULLETSPEED1 5
#define BOSSBULLETSPEED2 20
#define BOSSBULLETSPEED3 20
#define BOSSBULLETSPEED4 5

#define BOMBSPEED 20
//UpdateTime
#define UPDATETIME 100
//max step,用于产生NPC、血包、炸弹包
#define MAXSTEP 3150
//Player plane initialization constant
#define BOMBNUMBER 3
#define FIREPOWER 2

//因为包含一些内部逻辑， 直接改动可能会有错误， 改之前确保理解advance函数中step的意义

const int BOSSSHOOTSTEP = 100;
const int FISHSHOOTSTEP = 20;

//Score
#define FISHSCORE 10
#define BOSSSCORE 200
//Hp
#define FISHHP 10
#define BOSSHP 200
//UP（上限）
#define PLAYERPLANEBLOOD 3
#define PLAYERPLANEBOMB 3
#define PLAYERPLANEBULLET 3
//旋转、角度、方向
#define ROTATE 57.26

//类型定义
/*****************************************************************************/
typedef enum {UP, DOWN, LEFT, RIGHT} CHECK_FLAG;
typedef QList<QPixmap> QPixmaps;

//图片引用定义
/*****************************************************************************/
const QString background = ":/images/background/background.jpg";

const QString fish0 = ":/images/enemyplane/fish0.png";
const QString fish1 = ":/images/enemyplane/fish1.png";
const QString fish2 = ":/images/enemyplane/fish2.png";

const QString boss0 = ":/images/enemyplane/boss0.png";

const QString fishbullet0 = ":/images/enemybullet/fishbullet0.png";
const QString fishbullet1 = ":/images/enemybullet/fishbullet1.png";
const QString fishbullet2 = ":/images/enemybullet/fishbullet2.png";

const QString bossbullet0 = ":/images/enemybullet/bossbullet0.png";
const QString bossbullet1 = ":/images/enemybullet/bossbullet1.png";
const QString bossbullet2 = ":/images/enemybullet/bossbullet2.png";
const QString bossbullet3 = ":/images/enemybullet/bossbullet3.png";

const QString playerbullet0 = ":/images/playerbullet/playerbullet0.png";
const QString playerbullet1 = ":/images/playerbullet/playerbullet1.JPG";

const QString bomb0 = ":/images/bomb/bomb0.png";
const QString bomb1 = ":/images/bomb/bomb1.png";

const QString playerplane0 = ":/images/PlayerPlane/playerplane0.png";
const QString playerplane1 = ":/images/PlayerPlane/playerplane1.png";
const QString playerplane2 = ":/images/PlayerPlane/playerplane2.png";
const QString playerplane3 = ":/images/PlayerPlane/playerplane3.png";

const QString bloodsupply = ":/images/bloodsupply/bloodsupply.png";
const QString bombsupply = ":/images/bombsupply/bombsupply.png";


#endif // GLOBAL_H
