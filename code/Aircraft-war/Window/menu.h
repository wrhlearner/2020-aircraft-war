#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include "global.h"

class Menu : public QDialog
{
    Q_OBJECT
public:
    explicit Menu(bool isRunning, QWidget *parent = 0);
signals:
    void sig_newGame();
    void sig_quit();
    void sig_back();
protected slots:
    void slt_quit();
    void slt_newGame();
    void slt_back();

private:
    QPushButton *m_new;
    QPushButton *m_back;
    QPushButton *m_quit;
    QPushButton *m_help;
    QPushButton *m_config;

    bool states;
    void initUI();
};

#endif // MENUWIDGET_H
