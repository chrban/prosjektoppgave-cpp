#ifndef LEVELFACTORY
#define LEVELFACTORY

#include <vector>

class LevelFactory{

public:
    LevelFactory();
    int getNextY();
    int getNextX();
private:
   // std::vector<int> x;
   // std::vector<int> y;
    //static const int * x;
    static int x[4];
    static int y[4];

   // static  int y[20]{200,200,200,200};
    int count;


};

#endif // LEVELFACTORY

