#include <Aircraft-war/window/MainWindow.h>
#include <controller.h>
#include <QApplication>
#include <QResource>
#include <Config.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QResource::registerResource(GAME_RES_PATH);
    MainWindow w;
    controller c;
    w.show();
    c.show();
    return a.exec();
}
