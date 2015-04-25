#ifndef LEVELFACTORY
#define LEVELFACTORY
#include <utility>

#include <vector>

class LevelFactory{

public:
    LevelFactory();
    int getNextY();
    int getNextX();
    void fillVect();
    std::pair<int,int> getCoordinates();
    void readMap();
private:
   // std::vector<int> x;
   // std::vector<int> y;
    //static const int * x;
    static int x[20];
    static int y[20];

   // static  int y[20]{200,200,200,200};
    int count;


};

#endif // LEVELFACTORY

