#ifndef CLOUD
#define CLOUD
#include "object.h"
#include <QTimer>

class Cloud : public Object{
    Q_OBJECT
public:
    Cloud(int x, int y);
private:
    QTimer * animate;
    bool left;
public slots:
    void move();

};

#endif // CLOUD

