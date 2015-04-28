#ifndef GLOBALVAR
#define GLOBALVAR


class GlobalVar{
public:
    int getFrame();
    void setFrame(int f);
    void increaseFrame();
    void decreaseFrame();
private:
    int frame;

};


#endif // GLOBALVAR


