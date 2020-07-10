#include "space.h"

Space::Space(QWidget *parent) : QGraphicsView(parent), boss(false),  isRunning(false) {
    m_scene = new QGraphicsScene;
    m_scene->setSceneRect(0, 0, SCENEWIDTH, SCENEHEIGHT);
    setScene(m_scene);

    setWindowFlags(Qt::FramelessWindowHint);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setCacheMode(QGraphicsView::CacheBackground);
    setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    setOptimizationFlags(QGraphicsView::DontClipPainter | QGraphicsView::DontSavePainterState);
    setRenderHint(QPainter::Antialiasing);

    QPixmap pix(SCENEWIDTH, SCENEHEIGHT);
    pix.load(background);
    QPixmap temp = pix.scaled(SCENEWIDTH, SCENEHEIGHT, Qt::KeepAspectRatioByExpanding);
    setBackgroundBrush(temp);

    m_timer = new QTimer;
    connect(m_timer, SIGNAL(timeout()), this, SLOT(slt_updata()));
    connect(this, SIGNAL(sig_menu()), this, SLOT(slt_menu()));

    init();
}

void Space::init() {
//    scoretext = new QGraphicsTextItem("0");
//    scoretext->setPos(0, 0);
//    m_scene->addItem(scoretext);

//    bloodtext = new QGraphicsTextItem("0");
//    bloodtext->setPos(0, 10);
//    m_scene->addItem(bloodtext);


//    bombtext = new QGraphicsTextItem("0");
//    bombtext->setPos(0, 20);
//    m_scene->addItem(bombtext);

    m_scores = 0, m_bloods = PLAYERPLANEBLOOD, m_bombs = 0, m_level = 1, m_step = 0;
    QPixmaps t;
    t.append(QPixmap(playerplane0));
    t.append(QPixmap(playerplane1));
    t.append(QPixmap(playerplane2));
    t.append(QPixmap(playerplane3));
    m_player = new PlayerPlane(PLAYERPLANEBLOOD, PLAYERPLANESIZE, PLAYERPLANESIZE, PLAYERPLANESPEED, t, m_scene);
    m_player->setFocus();
    connect(m_player, SIGNAL(sig_fall()), this, SLOT(slt_playerDead()));
    //connect(m_player, SIGNAL(sig_score(int)), this, SLOT(slt_updateScore(int)));
    //connect(m_player, SIGNAL(sig_blood(int)), this, SLOT(slt_updateBlood(int)));
    //connect(m_player, SIGNAL(sig_bomb(int)), this, SLOT(slt_updateBomb(int)));
}

void Space::slt_newGame()
{
    m_scene->clear();
    init();
    m_timer->start(50);
    isRunning = true;
}

void Space::slt_playerDead()
{
    m_timer->stop();
    isRunning = false;
}

void Space::slt_startGame()
{
    if (isRunning) m_timer->start(50);
}

void Space::slt_pauseGame()
{
    if (isRunning) m_timer->stop();
}

void Space::slt_updata()
{
    m_scene->advance();
    m_step++;
    if (m_step % 50 == 0 && !boss) {
        enemys();
    }
    if (m_step % 233 == 0) {
        bulletsupply();
    }
    if (m_step % 666 == 0) {
        bombsupply();
        m_step = 0;
    }
    if (m_step % 2333 == 0) {
        bloodsupply();
    }
}

void Space::slt_addscore(int score)
{
    m_scores += score;
    if (score == BOSSSCORE) {
        boss = false;
        m_level = 1;
        m_scores = 0;
        //slt_updateScore(m_scores);
    }
    if (m_scores != 0 && m_scores % 50 == 0) {
        m_level++;
        if (m_level == 7) m_level = 1;
    }
}

void Space::bloodsupply()
{
    QPixmaps t;
    t.append(QPixmap(bloodsupplypix));
    BloodSupply *bloodsupply = new BloodSupply(BLOODSUPPLYSIZE, BLOODSUPPLYSIZE, BLOODSUPPLYSPEED, t, m_scene);
    qreal x = Randomizer::creat(SCENEWIDTH - BLOODSUPPLYSIZE);
    bloodsupply->setPos(x, 0);
}

void Space::bombsupply()
{
    QPixmaps t;
    t.append(QPixmap(bombsupplypix));
    BloodSupply *bombsupply = new BloodSupply(BOMBSUPPLYSIZE, BOMBSUPPLYSIZE, BOMBSUPPLYSPEED, t, m_scene);
    qreal x = Randomizer::creat(SCENEWIDTH - BOMBSUPPLYSIZE);
    bombsupply->setPos(x, 0);
}

void Space::bulletsupply()
{
    QPixmaps t;
    t.append(QPixmap(bulletsupplypix));
    uint x = Randomizer::creat(SCENEWIDTH - BULLETSUPPLYSIZE);
    BulletSupply *bulletsupply = new BulletSupply(BULLETSUPPLYSIZE, BULLETSUPPLYSIZE, BULLETSUPPLYSPEED, t, m_scene);
    bulletsupply->setPos(x,0);
}

void Space::enemys()
{
    if (m_level == 6) {
        PlaneFactory::BossPlanes bossplanes = PlaneFactory::bcreator(1, scene());
        foreach (Boss *b, bossplanes) {
            int x = Randomizer::creat(SCENEWIDTH - BOSSSIZE);
            b->setPos(x, 0);
            connect(b, SIGNAL(sig_score(int)), this, SLOT(slt_addscore(int)));
        }
        boss = true;
    }
    else {
        PlaneFactory::FishPlanes fishplanes = PlaneFactory::fcreator(m_level, scene());
        foreach (Fish *f, fishplanes) {
            int z =  Randomizer::creat(6);
            if (z == 1) {
                int y = Randomizer::creat(SCENEHEIGHT / 2 - FISHSIZE);
                f->setPos(0, y);
            }
            else if (z == 2) {
                int y = Randomizer::creat(SCENEHEIGHT / 2 - FISHSIZE);
                f->setPos(SCENEWIDTH - FISHSIZE, y);
            }
            else {
                int x = Randomizer::creat(SCENEWIDTH - FISHSIZE);
                f->setPos(x, 0);
            }
            connect(f, SIGNAL(sig_score(int)), this, SLOT(slt_addscore(int)));
        }
    }
}

void Space::slt_menu()
{
    if (isRunning) {
        slt_pauseGame();
        QScopedPointer<MenuWidget> w(new MenuWidget(true, this));
        connect(w.data(), SIGNAL(sig_newGame()), this, SLOT(slt_newGame()));
        connect(w.data(), SIGNAL(sig_quit()), this, SLOT(close()));
        w->setModal(true);
        w->show();
        w->exec();
        slt_startGame();
    }
    else {
        QScopedPointer<MenuWidget> w(new MenuWidget(false, this));
        connect(w.data(), SIGNAL(sig_newGame()), this, SLOT(slt_newGame()));
        connect(w.data(), SIGNAL(sig_quit()), this, SLOT(close()));
        w->setModal(true);
        w->show();
        w->exec();
    }
}

void Space::mouseDoubleClickEvent(QMouseEvent *event) {
    event->accept();
    emit sig_menu();
}

//void Space::slt_updateScore(int score) {
//    QString text = QString::number(score, 10);
//    scoretext->setPlainText(text);
//}

//void Space::slt_updateBlood(int blood) {
//    QString text = QString::number(blood, 10);
//    bloodtext->setPlainText(text);
//}

//void Space::slt_updateBomb(int bomb) {
//    QString text = QString::number(bomb, 10);
//    bombtext->setPlainText(text);
//}
