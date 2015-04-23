#ifndef LEVELFACTORY
#define LEVELFACTORY

#include <vector>

class LevelFactory{

public:
    LevelFactory();
    int getNextY();
    int getNextX();
private:
    vector<int> x;
    vector<int> y;
    int count;

};

#endif // LEVELFACTORY

