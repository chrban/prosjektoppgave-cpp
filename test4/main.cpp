#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QApplication>
#include <QTimer>
#include <game.h>
#include <time.h>
#include <iostream>
#include <fstream>



game * g;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    srand ( time(NULL) );

    g = new game();
    g->showMainMenu();

    return a.exec();
}
