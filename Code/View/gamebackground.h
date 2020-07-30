#ifndef SPACE_H
#define SPACE_H

#include "global.h"
#include "menu.h"
#include "player.h"
#include "bombsupply.h"
#include "bloodsupply.h"
#include "generatenpc.h"
#include "randalg.h"

class GameBackground : public QGraphicsView
{
    Q_OBJECT
public:
    GameBackground(QWidget *parent = 0);
    void init();
    void CreateNPC();
    void CreateBloodSupply();
    void CreateBombSupply();
protected:
    void mouseDoubleClickEvent(QMouseEvent *event);

private:
    QGraphicsScene *m_scene;
    QTimer *m_timer;
    Player *m_player;
    uint m_scores, m_bloods, m_bombs, m_level, m_step;
    bool boss;
    bool gameStarted;

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
};

#endif // SPACE_H
