#ifndef LINUS
#define LINUS
#include "object.h"
#include <QTimer>

class Linus : public Object{
    Q_OBJECT
public:
    Linus(int x, int y);
    ~Linus();
public slots:
    void animate();
private:
    QTimer * fps;
    int count;
    bool up;
};

#endif // LINUS
