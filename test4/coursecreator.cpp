#include "coursecreator.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QObject>


int x = 25;
int y = 24;

Button* buttons[25][24];

void CourseCreator::drawGrid(QGraphicsScene *scene)
{
    scene->clear();

    for(int i = 0; i < x; i++)
    {
        for(int j=0; j< y; j++)
        {
            buttons[i][j] = new Button(QString(""));
            buttons[i][j]->setPos(i*32,j*25);
            scene->addItem(buttons[i][j]);
        }
    }
}

CourseCreator::CourseCreator()
{


}

CourseCreator::~CourseCreator()
{

}

