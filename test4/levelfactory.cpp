#include <vector>
#include "levelfactory.h"
#include <QDebug>
#include <utility>
#include <map>
#include "figur.h"
#include "game.h"

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
int bokser[50];
//std::vector<int> bokser;
//extern game * g;

void LevelFactory::readMap()
{
    int frameIndex=0;
    int antallFrames=0;
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


            superVect.push_back( std::make_pair( frameIndex,std::make_pair(first.toInt(),last.toInt())));
            antallFrames++;
//            qDebug()<<"first"<<first<<"last"<<last<<"bokser[getFrame()]="<<bokser[0];

        }
        else
        {

            bokser[frameIndex]=antallFrames;

//            qDebug()<<"trffet - i map.txt, øker frameIndex til "<<frameIndex<<"bokser[getFrame()]="<<bokser[0]<<"antFrames"<<antallFrames;
            antallFrames=0;
            frameIndex++;

        }
    }
    file.close();
}


//denne metoden skal sende ut riktige koordinater til boksene som skal tegnes basert på hvilken frame av banen man er på
std::pair<int, int> LevelFactory::frameHandler(std::vector<  std::pair<int, std::pair<int,int>  > > f )
{



        qDebug()<<"getFrame er"<< getFrame()<<"f[bokser[getFrame()]]"<<f[bokser[getFrame()]].first ;


//   for(auto i : superVect)  // mhm kan bruke noe i denne duren ja
//   {
//       if( i.first == 0)
//           return i.second;
//   }


    for(int i = bokser[0 /*getFrame() når jeg får det til å fungere...*/ ]; i != 0;i--)
    {
        if(f[i].first == 0 )
        {
                    return f[bokser[getFrame()]--].second;
        }

    }

}

int LevelFactory::getFrame()
{
    return frame;
}

void LevelFactory::setFrame(int f)
{
    frame = f;
}

void LevelFactory::increaseFrame()
{
    qDebug()<<"------------------FRAME var.."<<frame<<"men getFrame er:"<<getFrame();
    frame++;
    qDebug()<<"------------------FRAME ØKES TIL"<<frame;
}

void LevelFactory::decreaseFrame()
{
    frame--;
}

bool LevelFactory::framesLeft()
{
    if( bokser[getFrame()]==0 )
    {
        return false;
    }
    else
    {
        return true;
        qDebug()<<"boolen er tydligvis falsk";
    }
}



LevelFactory::LevelFactory() : count(0), reading(true)
{
    qDebug()<<"FØR  Frame initializes  " << frame;
    frame = 0;
    qDebug()<<"Frame initializes til " << frame;
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
//    qDebug()<<"kaller koordinater"<<getFrame()<<bokser[getFrame()];
    return frameHandler(superVect);

}


