#include "coursecreator.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QObject>


int x = 25;
int y = 24;

auto buttons = new Button[25][24];

void CourseCreator::drawGrid(QGraphicsScene *scene)
{
    scene->clear();

//    Button** buttons = new Button*[24];
    for(int i = 0; i < x; i++)
    {
//        buttons[i] = new Button[25]();

        for(int j=0; j< y; j++)
        {
//            buttons[i][j] = new Button(); //y


            Button* knapp = new Button(QString(""));

            knapp->setPos(i*32,j*25);

            scene->addItem(knapp);
        }
    }





}

CourseCreator::CourseCreator()
{

}

CourseCreator::~CourseCreator()
{

}

