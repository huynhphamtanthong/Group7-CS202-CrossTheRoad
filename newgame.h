#ifndef newgame_h
#define newgame_h

#include <windows.h>
#include <thread>
#include <iostream>
#include <conio.h>
#include <stdio.h>

class newgame {
public:
    void init();
    void exitgame(std::thread* t);
    void main();
    void running();
private:
    bool is_running;
};
#endif // newgame_h
