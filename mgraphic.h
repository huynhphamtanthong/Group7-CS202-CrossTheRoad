#pragma once

#include <iostream>
#include <windows.h>

#include <cstring>
#include <string.h>
#include <stdio.h>

using namespace std;

class mgraphic {
    unsigned char * scr;
    COORD size;
    COORD start, end;
    COORD cursor;
public:
    mgraphic();
    void open(unsigned char *scr, COORD size, COORD SStart, COORD SEnd);
    void GOTO(int, int);
    void GOTO(COORD);
    bool cursorOutOfRange();
    void print(string s);
    void close();
};
