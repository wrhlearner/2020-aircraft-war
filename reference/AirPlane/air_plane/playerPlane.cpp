#include "playerPlane.h"

PlayerPlane::PlayerPlane(qreal blood, qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent):
    FlightVehicle(blood, w, h, speed, pixs, scene, parent),
    m_bomb(3), m_bullet(0), W(false), A(false), S(false), D(false), bomb(false) {
    setPos((scene->width() - m_w)/2, scene->height() - m_h);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

PlayerPlane::~PlayerPlane() {

}

QRectF PlayerPlane::boundingRect() const
{
    return m_pixs.at(0).rect();
}

QPainterPath PlayerPlane::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void PlayerPlane::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(0, 0, m_pixs.at(m_pixpos));
}

int PlayerPlane::name() const {
    return PLAYERPLANENAME;
}

void PlayerPlane::advance(int) {
    m_step++;
    if (m_step % PLAYERSHOOTSTEP == 0) {
        shoot();
    }
    if (m_step == PLAYERSHOOTSTEP * 10) m_step = 0;
    if (W && checkPos(UP)) {
        m_pixpos = 0;
        QPointF pos = scenePos();
        pos.ry() -= m_speed;
        setPos(pos);
    }
    if (S && checkPos(DOWN)) {
        m_pixpos = 1;
        QPointF pos = scenePos();
        pos.ry() += m_speed;
        setPos(pos);
    }
    if (A && checkPos(LEFT)) {
        m_pixpos = 2;
        QPointF pos = scenePos();
        pos.rx() -= m_speed;
        setPos(pos);
    }
    if (D && checkPos(RIGHT)) {
        m_pixpos = 3;
        QPointF pos = scenePos();
        pos.rx() += m_speed;
        setPos(pos);
    }
    if (!W && !S && !A && !D) m_pixpos = 0;
    doCollide();
}

void PlayerPlane::posLost() {

}

void PlayerPlane::doCollide()
{
    foreach (QGraphicsItem *t, collidingItems()) {
        if (t->type() != UnFlyer::TYPE) {
            Flyer *flyer = static_cast<Flyer*>(t);
            switch (flyer->name()) {
            case ENEMYPLANENAME:
                strike();
                if (m_blood == 0) {
                    m_bomb = 0;
                    m_bullet = 0;
                    fall();
                }
                break;
            case ENEMYBULLETNAME:
                flyer->fall();
                strike();
                if (m_blood == 0) {
                    m_bomb = 0;
                    m_bullet = 0;
                    fall();
                }
                break;
            case BLOODSUPPLYNAME:
                flyer->fall();
                if (m_blood < PLAYERPLANEBLOOD) {
                    m_blood++;
                    //emit sig_blood(m_blood);
                }
                break;
            case BOMBSUPPLYNAME:
                flyer->fall();
                if (m_bomb < PLAYERPLANEBOMB) {
                    m_bomb++;
                    //emit sig_bomb(m_bomb);
                }
                break;
            case BULLETSUPPLYNAME:
                flyer->fall();
                if (m_bullet < PLAYERPLANEBULLET) {
                    m_bullet++;
                }
                break;
            }
        }
    }
}

void PlayerPlane::fall()
{
    setFlag(QGraphicsItem::ItemIsMovable, false);
    setFlag(QGraphicsItem::ItemIsFocusScope, false);
    setVisible(false);
    deleteLater();
    emit sig_fall();
}

void PlayerPlane::strike() {
    //m_blood--;
    //emit sig_blood(m_blood);
}

void PlayerPlane::shoot()
{
    BulletFactory::PlayerBullets bullets = BulletFactory::pcreator(m_bullet, scene());
    QPointF pos = scenePos();
    pos.rx() += m_w / 2 - PLAYERBULLETSIZE / 2;
    foreach (PlayerBullet* bullet, bullets) {
        bullet->setPos(pos);
    }
    if (bomb && m_bomb > 0) {
        bomb = false;
        //m_bomb--;
        BulletFactory::Bombs bombs = BulletFactory::bcreator(1, scene());
        pos = scenePos();
        pos.rx() += m_w / 2 - BOMBSIZE / 2;
        pos.ry() -= BOMBSIZE / 2;
        foreach (Bomb* bomb, bombs) {
            bomb->setPos(SCENEWIDTH / 2 - BOMBSIZE / 2, SCENEHEIGHT - BOMBSIZE);
        }
    }
}

void PlayerPlane::keyPressEvent(QKeyEvent *event)
{
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
        bomb = true;
        break;
    default:
        event->ignore();
        break;
    }
}

void PlayerPlane::keyReleaseEvent(QKeyEvent *event) {
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
    case Qt::Key_Space:
        event->accept();
        bomb = false;
        break;
    default:
        event->ignore();
        break;
    }
}

