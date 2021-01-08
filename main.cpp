#include <iostream>
#include <thread>
#include <vector>
#include <stdio.h>
#include <Windows.h>

#include "manager.h"
#include "subject.h"

using namespace std;

int main()
{
    // Change in console window
    manager game;
    game.init();

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    printf("columns: %d\n", columns);
    printf("rows: %d\n", rows);

    for (int i = 0; i < columns; ++i) cout << i % 10;
    cout << endl;
    for (int i = 0; i < 9; ++i) cout << c_player[i] ;
    cout << endl;
    for (int j = 0; j < s_player.Y; ++j){
        for (int i = 0; i < s_player.X; ++i) cout << c_player[curPosition(i, j, s_player)];
        cout << endl;

    }
    for (int j = 0; j < s_car.Y; ++j){
        for (int i = 0; i < s_car.X; ++i) cout << c_car[curPosition(i, j, s_car)];
        cout << endl;

    }
    system("pause");

    while (game.state != EXIT) game.ui_loop();

    return 0;
}
