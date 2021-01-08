#include "mgraphic.h"

mgraphic::mgraphic(){
    scr = nullptr;
}

void mgraphic::open(unsigned char *scr, COORD size, COORD start, COORD end) {
    this->scr = scr;
    this->start = start;
    this->end = end;
    this->size = size;
    cursor = start;
}

void mgraphic::GOTO(int x, int y){
    COORD t = {x, y};
    GOTO(t);
}

void mgraphic::GOTO(COORD cord){
    cursor = cord;
    cursorOutOfRange();
}

bool mgraphic::cursorOutOfRange(){
    if (cursor.X >= start.X && cursor.X <= end.X
    && cursor.Y >= start.Y && cursor.Y <= end.Y) return true;
    cursor = start;
    return false;
}

void mgraphic::print(string s){
    if (scr == nullptr) return;
    COORD s_cursor = cursor;
    for (int i = 0; i < s.length(); ++i){
        if (s[i] == '\n' || cursor.X == end.X){
            cursor = {s_cursor.X, cursor.Y + 1};
        }
        if (cursorOutOfRange()) break;
        int t = cursor.Y * size.X + cursor.X;
        scr[t] = s[i];
        cursor.X++;
    }
}
void mgraphic::close(){
    scr = nullptr;
}
