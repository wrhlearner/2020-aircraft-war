#ifndef SPACE_H
#define SPACE_H

#include "planefactory.h"
#include "playerPlane.h"
#include "bloodsupply.h"
#include "bombsupply.h"
#include "bulletsupply.h"
#include "randomizer.h"
#include "menuwidget.h"

class Space : public QGraphicsView
{
    Q_OBJECT
public:
    Space(QWidget *parent = 0);
    void init();
    void bloodsupply();
    void bombsupply();
    void bulletsupply();
    void enemys();
protected:
    void mouseDoubleClickEvent(QMouseEvent *event);
private:
    //QGraphicsTextItem *scoretext, *bloodtext, *bombtext;
    QGraphicsScene *m_scene;
    QTimer *m_timer;
    PlayerPlane *m_player;
    uint m_scores, m_bloods, m_bombs, m_level, m_step;
    bool boss;//boss’Ω±Í ∂
    bool isRunning;
signals:
    void sig_menu();
protected slots:
    void slt_newGame();
    void slt_playerDead();
    void slt_startGame();
    void slt_pauseGame();
    void slt_updata();
    void slt_addscore(int);
    void slt_menu();
    //void slt_updateScore(int);
    //void slt_updateBlood(int);
    //void slt_updateBomb(int);
};

#endif // SPACE_H
