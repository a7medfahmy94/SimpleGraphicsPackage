#ifndef HELPER_H
#define HELPER_H

#include <QPoint>

class Helper
{
private:
    Helper();
    ~Helper();
public:
    static int round(double);
    static bool is_set(QPoint&);
};

#endif // HELPER_H
