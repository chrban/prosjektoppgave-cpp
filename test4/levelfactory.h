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
    std::pair<int,int> frameHandler(std::vector<std::pair<int, std::pair<int, int> > > f);
    int getFrame();

    void increaseFrame();
    void decreaseFrame();
    bool reading;
    bool framesLeft();
private:
   // std::vector<int> x;
   // std::vector<int> y;
    //static const int * x;
    static int x[20];
    static int y[20];

   // static  int y[20]{200,200,200,200};
    int count;
    int frame;


};

#endif // LEVELFACTORY

