#include "subject.h"

obstacle::obstacle(Obstacle id) : id(id){}

void obstacle::init(int x, int y, int level){
    this->x = x;
    this->y = y;
    this->speed =   (int) ( ((float)(level * (level + 1) /2) / (float)(level * 10)) * 5 + 5 );
}
void obstacle::setXY(int x, int y){
    this->x = x;
    this->y = y;
}
void obstacle::setAll(int x, int y, int speed){
    this->x = x;
    this->y = y;
    this->speed = speed;
}
int obstacle::getX(){
    return x;
}
int obstacle::getY(){
    return y;
}
int obstacle::getSpeed(){
    return speed;
}
move(Key key){
    switch (key){
    case UP:
        break;
    case DOWN:
        break;
    case LEFT:
        break;
    case RIGHT:
        break;
    case STOP:
        break;
    }
}
