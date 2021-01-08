#include "subject.h"

obstacle::obstacle(Obstacle id) : id(id){}

void obstacle::init(int x, int y, int level){
    this->x = x;
    this->y = y;
    this->speed =   (int) ( ((float)(level * (level + 1) /2) / (float)(level * 10)) * START_SPEED + START_SPEED );
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
COORD obstacle::getXY() {
    return COORD{ (short)x, (short)y };
}
int obstacle::getSpeed(){
    return speed;
}
Obstacle obstacle::getId(){
    return id;
}
void obstacle::move(Key state){
    this->state = state;
}

void obstacle::update(COORD start, COORD end){
    switch (state){
    case UP:
        y -= 1;
        break;
    case DOWN:
        y += 1;
        break;
    case LEFT:
        x -= 1;
        break;
    case RIGHT:
        x += 1;
        break;
    case UPLEFT:
        y -= 1;
        x -= 1;
        break;
    case UPRIGHT:
        y -= 1;
        x += 1;
        break;
    case DOWNLEFT:
        y += 1;
        x -= 1;
        break;
    case DOWNRIGHT:
        y += 1;
        x += 1;
        break;
    case STOP:
        break;
    default:
        break;
    }
    if (id == PLAYER) state = STOP;

    if (x < start.X) x = start.X;
    if (x > end.X) x = end.X;
    if (y < start.Y) y = start.Y;
    if (y > end.Y) y = end.Y;
}

player::player(int x, int y):obstacle(PLAYER){
    init(x, y);
}
