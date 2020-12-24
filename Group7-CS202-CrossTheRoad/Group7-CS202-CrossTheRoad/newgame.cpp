
#include "newgame.h"
#include <iostream>

void newgame::running() {
    while (is_running) {
        system("cls");
        std::cout << "run";
    }
}

void newgame::init() {
    is_running = true;
}

void newgame::exitgame(std::thread* t) {
    system("cls");
    is_running = false;
    t->join();
}

void newgame::main() {
    std::thread t1(&newgame::running, this);
    while (1) {
        int key = _getch();
        if (key == 27) {
            exitgame(&t1);
            return;
        }
    }
}