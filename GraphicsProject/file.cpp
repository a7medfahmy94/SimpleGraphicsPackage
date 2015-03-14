#include "file.h"
#include <bits/stdc++.h>

File::File(int w,int h)
{
    HEIGHT = w;//this is not wrong ,,, it's working
    WIDTH = h;
    grid = new int*[HEIGHT];
    for(int i = 0 ; i < HEIGHT; i++){
        grid[i] = new int[WIDTH];
        for(int j = 0 ; j < WIDTH; ++j){
            grid[i][j] = 0;
        }
    }
}

File::~File()
{
    for(int i = 0 ; i < HEIGHT; i++){
        delete[] grid[i];
    }
    delete[] grid;
}

int File::get(int i,int j){
    return grid[i][j];
}
void File::set(int i,int j){
    grid[i][j] = 1;
}

void File::draw(int x,int y){
    grid[x][y] = 1;
}

void File::save(){
    std::ofstream file(fileName.c_str(),std::ios::binary);
    for(int i = 0 ; i < HEIGHT; i++){
        file.write((char*)grid[i],WIDTH*4);
    }
    file.close();
}

void File::load(){
    std::ifstream in(fileName.c_str(),std::ios::binary);
    for(int i = 0 ; i < HEIGHT; i++){
        in.read((char*)grid[i],WIDTH*4);
    }
}


int File::getH(){
    return HEIGHT;
}

int File::getW(){
    return WIDTH;
}
