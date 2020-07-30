#include "player.h"

//初始化飞机
/**************************************************************************************************************************************************/
Player::Player(qreal blood, qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent):
    Aircraft(blood, w, h, speed, pixs, scene, parent),
    m_bomb(BOMBNUMBER), m_firePower(FIREPOWER), W(false), A(false), S(false), D(false), bomb(false)
{
    //设置在父图形项或场景，此处为场景，中的位置坐标
    //坐标系为场景或父部件坐标系，此处为场景坐标系
    setPos((scene->width() - m_width)/2, scene->height() - m_height);
    //使得飞机图形项可以获得键盘焦点
    setFlag(QGraphicsItem::ItemIsFocusable);
}

//绘制飞机
/**************************************************************************************************************************************************/
QRectF Player::boundingRect() const
{
    //QRect QPixmap::rect() const;
    //返回Pixmap图像的包围矩形
    return m_pixmaps.at(0).rect();
}

QPainterPath Player::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    //玩家飞机m_pixpos在flyer.cpp中初始化为0
    painter->drawPixmap(0, 0, m_pixmaps.at(m_pixmapIterator));
}

void Player::advance(int) {
    //检测玩家飞机是否被击落
    if(m_blood == 0)
        BreakDown();
    //键盘改变玩家飞机位置
    if (W && checkPos(UP)) {
        m_pixmapIterator = 0;
        QPointF pos = scenePos();
        pos.ry() -= m_speed;
        setPos(pos);
    }
    if (S && checkPos(DOWN)) {
        m_pixmapIterator = 1;
        QPointF pos = scenePos();
        pos.ry() += m_speed;
        setPos(pos);
    }
    if (A && checkPos(LEFT)) {
        m_pixmapIterator = 2;
        QPointF pos = scenePos();
        pos.rx() -= m_speed;
        setPos(pos);
    }
    if (D && checkPos(RIGHT)) {
        m_pixmapIterator = 3;
        QPointF pos = scenePos();
        pos.rx() += m_speed;
        setPos(pos);
    }
    if (!W && !S && !A && !D)
        m_pixmapIterator = 0;
    //检测玩家飞机碰撞
    Collision();
}


int Player::getName() const {
    return PLAYERPLANENAME;
}

//飞机游戏行为
/**************************************************************************************************************************************************/
void Player::InvalidPosition() {}

void Player::Collision()
{
    //QList<QGraphicsItem *> QGraphicsItem::collidingItems() const
    //返回所有与玩家飞机碰撞的对象
    foreach (QGraphicsItem *t, collidingItems()) {
        //int QGraphicsItem::type() const
        //将对象类型以int型返回
        if (t->type() != FlyerTypeCast::TYPE) {
            //QGraphicsItem类型的变量t转换为QGraphicsObject类型（继承QGraphicsItem类）指针
            FlyingObject *flyer = static_cast<FlyingObject*>(t);
            switch (flyer->getName())
            {
            case ENEMYPLANENAME:
                flyer->BreakDown();
                hitAircraft();
                break;
            case ENEMYBULLETNAME:
                flyer->BreakDown();
                m_blood--;
                qDebug()<<tr("get hit. current hp value: ")<<m_blood;
                if(m_blood==0)
                    BreakDown();
                break;
            case BLOODSUPPLYNAME:
                flyer->BreakDown();
                if(m_blood<PLAYERPLANEBLOOD)
                    m_blood++;
                qDebug()<<tr("get blood supply. current hp value: ")<<m_blood;
                break;
            case BOMBSUPPLYNAME:
                flyer->BreakDown();
                if(m_bomb<BOMBNUMBER)
                    m_bomb++;
                qDebug()<<tr("get bomb supply. current bomb number: ")<<m_bomb;
                break;
            }
        }
    }
}

void Player::BreakDown()
{
    m_blood=0;
    m_bomb = 0;
    m_firePower = 0;
    setFlag(QGraphicsItem::ItemIsMovable, false);
    setFlag(QGraphicsItem::ItemIsFocusScope, false);
    setVisible(false);
    deleteLater();
    emit sig_fall();
}

void Player::hitAircraft()
{
    BreakDown();
}

void Player::shoot()
{
    //每颗子弹的杀伤力其实是通过子弹数量实现的
    //每颗子弹与NPC碰撞都会导致NPC HP值减一
    //一次初始化多个子弹同时发射，击中NPC后的效果是多颗子弹效果总和
    //由于多个子弹完全重合，所以直观上提高了子弹的杀伤力
    GenerateBullet::PlayerBullets bullets = GenerateBullet::pcreator(m_firePower, scene());
    QPointF pos = scenePos();
    pos.rx() += m_width / 2 - PLAYERBULLETSIZE / 2;
    pos.ry() -= PLAYERBULLETSIZE;
    foreach (PlayerBullet* bullet, bullets) {
        bullet->setPos(pos);
    }
}

void Player::emitBomb()
{
    qDebug()<<tr("emit bomb. left bomb number: ")<<m_bomb;
    GenerateBullet::Bombs bombs = GenerateBullet::bcreator(1, scene());
    QPointF pos = scenePos();
    pos.rx() += m_width / 2 - BOMBSIZE / 2;
    pos.ry() -= BOMBSIZE;
    foreach (Bomb* bomb, bombs) {
        bomb->setPos(pos);
    }
}

//飞机键盘操作
/**************************************************************************************************************************************************/
void Player::keyPressEvent(QKeyEvent *event)
{
    //检测键盘事件
    //WASD：飞机向上下左右移动
    //空格：放出炸弹
    //J:发射子弹
    switch (event->key()) {
    case Qt::Key_W:
        event->accept();
        W = true;
        break;
    case Qt::Key_S:
        event->accept();
        S = true;
        break;
    case Qt::Key_A:
        event->accept();
        A = true;
        break;
    case Qt::Key_D:
        event->accept();
        D = true;
        break;
    case Qt::Key_Space:
        event->accept();
        if(m_bomb<=0)
            bomb=false;
        else
        {
            bomb = true;
            m_bomb--;
            emitBomb();
        }
        break;
    case Qt::Key_J:
        event->accept();
        shoot();
        break;
    default:
        event->ignore();
        break;
    }
}

void Player::keyReleaseEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_W:
        event->accept();
        W = false;
        break;
    case Qt::Key_S:
        event->accept();
        S = false;
        break;
    case Qt::Key_A:
        event->accept();
        A = false;
        break;
    case Qt::Key_D:
        event->accept();
        D = false;
        break;
//    case Qt::Key_Space:
//        event->accept();
//        bomb = false;
//        break;
    default:
        event->ignore();
        break;
    }
}

//改变玩家飞机属性
/*******************************************************************************************************************************************/
