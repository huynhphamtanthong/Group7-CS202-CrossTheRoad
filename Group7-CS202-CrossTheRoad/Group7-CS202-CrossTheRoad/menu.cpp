#include "menu.h"

void menu::color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void menu::init() {
    int set[] = { 12,7,7 };
    char key;
    while (1) {
        system("cls");
        color(set[0]);
        std::cout << "new game" << std::endl;

        color(set[1]);
        std::cout << "load game" << std::endl;

        color(set[2]);
        std::cout << "exit" << std::endl;

        key = getch();

        if (key == 72) {
            if (counter == 1)
                counter = 3;
            else counter--;
        }

        if (key == 80) {
            if (counter == 3)
                counter = 1;
            else counter++;
        }

        if (key == '\r') {
            if (counter == 1) {
                newgame ng;
                ng.init();
                ng.main();
            }
            if (counter == 2) {
                system("cls");
                std::cout << "load game" << std::endl;
                system("pause");
            }
            if (counter == 3) {
                system("cls");
                std::cout << "Exit" << std::endl;
                break;
            }
        }

        set[0] = 7;
        set[1] = 7;
        set[2] = 7;
        set[counter - 1] = 12;
    }
}