#include <vector>
#include "levelfactory.h"
#include <QDebug>
#include <utility>
#include <map>
//#include "figur.h"
#include <iostream>
#include <iterator>
#include <fstream>
#include <algorithm> // for std::copy
#include <QFile>
#include <QMessageBox>
#include <QPair>
#include <QRegExp>

LevelFactory::LevelFactory() {}

extern game * g; //global variable

void LevelFactory::loadMap( QGraphicsScene* scene, int f  )
{
int frameLokal=0;




    QFile file(":/map/map.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        std::cout<<"Error reading from file";

    }
    QTextStream in(&file);

    while(!in.atEnd()) {
        QGraphicsItem* item;
        QString line = in.readLine(); //seek todo

            QStringList maplist = line.split(",");

            if(maplist[0]=="frame")
            {
                frameLokal = maplist[1].toInt();
            }
            else if(frameLokal == f )
            {

            if(maplist[0]=="box"){
                item = BF->mekk(maplist[1].toInt(),maplist[2].toInt());
                scene->addItem(item);
            }
            else if(maplist[0]=="linus"){
                item = LF->mekk(maplist[1].toInt(),maplist[2].toInt()) ;
                scene->addItem(item);
            }
            else if(maplist[0]=="enemy"){
                item = EF->mekk(maplist[1].toInt(),maplist[2].toInt()) ;
                scene->addItem(item);
            }
            else if(maplist[0]=="ground"){
                item = GF->mekk(maplist[1].toInt(),maplist[2].toInt()) ;
                scene->addItem(item);
            }
            else if(maplist[0]=="cloud"){
                item = CF->mekk(maplist[1].toInt(),maplist[2].toInt()) ;
                scene->addItem(item);
            }
            else if(maplist[0]=="mapdefine"){ //mapdefine, mapname, reqScore
                g->GV->setRequiredScore( maplist[2].toInt() );
            }
            else
                std::cout<<"Undefined object / Error reading from file. (Tip: Check mapfile for syntax error)";

        }
    }
    file.close();
}



