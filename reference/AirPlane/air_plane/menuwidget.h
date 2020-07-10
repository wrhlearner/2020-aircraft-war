#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QDialog>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QPushButton>

class MenuWidget : public QDialog
{
    Q_OBJECT
public:
    explicit MenuWidget(bool isRunning, QWidget *parent = 0);
signals:
    void sig_newGame();
    void sig_quit();
protected slots:
    void slt_quit();
    void slt_newGame();

private:
    QPushButton *m_new;
    QPushButton *m_back;
    QPushButton *m_quit;
    bool states;
    void initUI();
};

#endif // MENUWIDGET_H
