#include "global.h"
#include "gamebackground.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    GameBackground space;
    space.resize(SCENEWIDTH, SCENEHEIGHT);
    space.move(QApplication::desktop()->rect().center() - QPoint(SCENEWIDTH/2, SCENEHEIGHT/2));
    space.show();

    return app.exec();
}
