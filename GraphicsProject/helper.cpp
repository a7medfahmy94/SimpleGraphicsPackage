#include "helper.h"
#include <QPoint>

int Helper::round(double d){
  return d + 0.5;
}


bool Helper::is_set(QPoint& p){
    return ! (p.x() == -1 && p.y() == -1);
}
