#ifndef manager_h
#define manager_h

#include <iostream>
#include <thread>
#include <vector>
#include <stdio.h>
#if       _WIN32_WINNT < 0x0500
  #undef  _WIN32_WINNT
  #define _WIN32_WINNT   0x0500
#endif
#include <Windows.h>
#include <windows.h>
#include <chrono>
#include <conio.h>

#include "subject.h"

using namespace std;

enum GAME_STATE{MENU, PAUSEMENU, GAMMING, SAVE, LOAD, EXIT};



class manager {
    COORD scrSize;
public:
    GAME_STATE state, last_state;
    void init();
    void ui_loop();
    void ui_menu_loop();
    void ui_pausemenu_loop();
    void ui_game_loop();

};

Key getInput(bool bKey[6]);
void goto_xy(int x, int y);
void goto_xy(COORD coord);
void set_color(int color);
int curPosition(int x, int y, COORD size);
void clrscr();

void FixConsoleWindow();
void remove_scrollbar();
void ShowConsoleCursor(bool showFlag);
COORD getWindowSize();

void drawHorizontalLine(char c, COORD start, int length);
void drawVerticalLine(char c, COORD start, int length);
void drawObject(unsigned char * obj, COORD size, COORD pos);
void drawObject(obstacle *obj);
void clearObject(const unsigned char* obj, COORD size, COORD pos);
void clearObject(obstacle* obj);
void drawString(string s, COORD start);
void fillBlock(char c, COORD start, int width, int height);
string centered(string s, int width);

#endif // manager_h
