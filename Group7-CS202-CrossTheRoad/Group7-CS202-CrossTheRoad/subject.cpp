#include "subject.h"

obstacle::obstacle(Obstacle id) : id(id){
    state = STOP;
    isactive = false;
}

void obstacle::init(int x, int y, COORD start, COORD end, Key mov){
    this->start = start;
    this->end = { end.X - s_obj[id].X , end.Y - s_obj[id].Y };
    
    if (x < 0) { 
        this->x = this->end.X; 
        mov = LEFT;
    } else this->x = x;
    if (y < 0) this->y = this->end.Y;
        else this->y = y;
    
    isactive = true;
    last_coord = COORD{ (short)x, (short)y };
    move(mov);
}
void obstacle::setXY(int x, int y){
    this->x = x;
    this->y = y;
}
void obstacle::setSpeed(int speed) {
    this->speed = speed;
}
void obstacle::setActive(bool isactive) {
    this->isactive = isactive;
}
void obstacle::setAll(int x, int y, int speed, bool isactive){
    this->x = x;
    this->y = y;
    this->speed = speed;
    this->isactive = isactive;
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
bool obstacle::isActive() {
    return isactive;
}
void obstacle::move(Key state){
    if (state != STOP) last_state = state;
    this->state = state;
}

bool obstacle::update(){
    bool check_reach_bound = false;
    last_coord = COORD{ (short) x, (short) y };
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

    if (x < start.X) {
        x = start.X;
        check_reach_bound = true;
    }
    if (x > end.X) {
        x = end.X;
        check_reach_bound = true;
    }
    if (y < start.Y) {
        y = start.Y;
        check_reach_bound = true;
    }
    if (y > end.Y) {
        y = end.Y;
        check_reach_bound = true;
    }
    return check_reach_bound;
}

// (x,y) on screen position, start : top-left boundary,  end : down-right boundary

player::player(int x, int y, COORD start, COORD end):obstacle(PLAYER){
    init(x, y, start, end, STOP);
}
