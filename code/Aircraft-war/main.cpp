#include "app/App.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QResource::registerResource(GAME_RES_PATH);
    MainWindow w;
    w.setMouseTrack(true);
    //controller c;
    PlaneApp(&w);
    //w.show();
    //c.show();
    return a.exec();
}