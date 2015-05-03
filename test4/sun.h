#ifndef SUN
#define SUN

#include "object.h"
#include <QTimer>

class Sun : public Object{
    Q_OBJECT
public:
    Sun(int x, int y);
    ~Sun();
private:
    QTimer * animate;
    bool turn;
public slots:
    void spinn();
};

#endif // SUN

