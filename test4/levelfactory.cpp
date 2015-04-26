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
#include <QPair>


int LevelFactory::x[20]={100,130,160,190,220,250,280,310,340,370,460,400,600,600,600,600,600,166,460,400};
int LevelFactory::y[20]={480,480,480,480,480,480,480,480,480,480,450,380,525,500,475,450,425,442,412,342};

std::vector< std::pair<int,int> > parVect;
std::vector<  std::pair<int, std::pair<int,int>  > > superVect; // tanken er: framenumber, x,y koordinater




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


            superVect.push_back( std::make_pair( frame ,std::make_pair(first.toInt(),last.toInt())));
//          parVect.push_back(std::make_pair(first.toInt(),last.toInt()));
            qDebug()<<"first"<<first<<"last"<<last;

        }
        else
        {
            frame++;

            qDebug()<<"trffet - i map.txt, øker frame til"<<frame;
            break;
        }
    }
    file.close();
}


//denne metoden skal sende ut riktige koordinater til boksene som skal tegnes basert på hvilken frame av banen man er på
std::pair<int, int> LevelFactory::frameHandler(std::vector<  std::pair<int, std::pair<int,int>  > > f)
{


        return f[count++].second;



}

int LevelFactory::getFrame()
{
    return frame;
}

void LevelFactory::increaseFrame()
{
    frame--;
}

void LevelFactory::decreaseFrame()
{
    frame++;
}



LevelFactory::LevelFactory() : count(0), frame(0)
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
    return frameHandler(superVect);


//    return parVect[count++];

}


