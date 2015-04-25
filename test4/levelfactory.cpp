#include <vector>
#include "levelfactory.h"
#include <QDebug>
#include <utility>
#include <map>

#include <iostream>
#include <iterator>
#include <fstream>
#include <algorithm> // for std::copy
#include <QFile>
#include <QMessageBox>


int LevelFactory::x[20]={100,133,166,199,232,265,298,331,364,397,460,400,600,600,600,600,600,166,460,400};
int LevelFactory::y[20]={480,480,480,480,480,480,480,480,480,480,450,380,525,500,475,450,425,442,412,342};

std::vector< std::pair<int,int> > parVect;



void LevelFactory::readMap()
{
    QFile file(":/new/img/map.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        qDebug()<<"noe gikk galt ved lesing av fil";
        //TODO: Hva skal throwes?
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        if(line != "-"){
            QString first = line.split(",").takeFirst();
            QString last = line.split(",").takeLast();
            parVect.push_back(std::make_pair(first.toInt(),last.toInt()));

        }
        else
        {
            qDebug()<<"lese map nummer TO";
        }
    }
    file.close();
}



LevelFactory::LevelFactory() : count(0)
{
}

int LevelFactory::getNextY()
{

    return y[count++];
}

int LevelFactory::getNextX()
{
    return x[count];

}

std::pair<int,int> LevelFactory::getCoordinates()
{
    return parVect[count++];

}


