#ifndef CIRCLEFILLED_H
#define CIRCLEFILLED_H
#include "drawalgo.h"

class CircleFilled : public DrawAlgo
{
public:
    CircleFilled();
    ~CircleFilled();
    void draw(QPainter&,std::map<std::string,QPoint>);

};

#endif // CIRCLEFILLED_H
