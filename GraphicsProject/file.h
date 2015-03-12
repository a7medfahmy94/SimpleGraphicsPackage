#ifndef FILE_H
#define FILE_H

#include <string>

class File
{
public:
    File(){}

    File(int w,int h);
    ~File();
    void draw(int x,int y);
    void save();
    void load();
    int get(int,int);
    void set(int,int);
    int getH();
    int getW();
private:
    int ** grid;
    int WIDTH , HEIGHT;
    std::string fileName = "img.dat";
};

#endif // FILE_H
