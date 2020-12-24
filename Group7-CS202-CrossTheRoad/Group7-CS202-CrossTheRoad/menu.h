#ifndef menu_h
#define menu_h

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>

class menu {
public:
    void color(int color);
    void init();
private:
    int counter = 1;
};

#endif // menu_h