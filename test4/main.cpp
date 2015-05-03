#include <QApplication>
#include <game.h>

game * g;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    srand ( time(NULL) );

    g = new game();
    g->showMainMenu();

    return a.exec();
}
