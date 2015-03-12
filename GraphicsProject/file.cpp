#include "file.h"
#include <bits/stdc++.h>

File::File(int w,int h)
{
    HEIGHT = h;
    WIDTH = w;
    grid = new int*[h];
    for(int i = 0 ; i < h; i++){
        grid[i] = new int[w];
        for(int j = 0 ; j < w; ++j){
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
    file.write((char*)grid,sizeof grid);
    file.close();
}

void File::load(){
    std::ifstream in(fileName.c_str(),std::ios::binary);
    in.read((char*)&grid,sizeof grid);
}


int File::getH(){
    return HEIGHT;
}

int File::getW(){
    return WIDTH;
}
