#pragma once

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>

enum Obstacle {PLAYER = 0, DOG = 1, CAR2 = 2, TRUCK = 3, CAR = 4};
enum Key {UP, DOWN, LEFT, RIGHT, UPLEFT, UPRIGHT, DOWNLEFT, DOWNRIGHT, STOP};

const COORD s_obj[5] = {
	{3,3},
	{9, 4},
	{8,3},
	{17,4},
	{4,3}
};


/*
const COORD s_obj[7] = {
	{3,3},
	{4,3},
	{4,3},
	{4,3},
	{4,3},
	{4,3},
	{4,3}
};
*/


const int START_SPEED = 1;

const COORD s_player = {3, 3};
const unsigned char c_player[3 * 3 + 1] = ".O./|\\<\\.";

/* player : 3x3
.O.
/|\\
<\\.
*/

const COORD s_car = {4, 3};
const unsigned char c_car[4 * 3 + 1] = ".__.|__\\O..O";

/* car 4*4
.__.
|__\\
O..O
*/

const COORD s_dog = { 9, 4 };
const unsigned char c_dog[9 * 4 + 1] = ".....__..(___()'`;/,..../`.\\\\'--\\\\..";

//      __
// (___()'`;
// /,    /`
// \\'--\\ 

const COORD s_car2 = { 8, 3 };
const unsigned char c_car2[8 * 3 + 1] = "...__.... /<>\\..(O)--(O)";

/*
	__
   /<>\
 (O)--(O)
*/

const COORD s_truck = { 17, 4 };
const unsigned char c_truck[17 * 4 + 1] = "..._____________.._/_|[][][][][].|(......Group.7..|=--OO-------OO--=";

/*
   _____________
 _/_|[][][][][] |
(      Group 7  |
=--OO-------OO--=
*/


class obstacle {
protected:
	//coordinates and velocity
	int x, y, speed;
	//identity
	Obstacle id;
	//state
	Key state, last_state;
	//range
	COORD start, end;
	//condition
	bool isactive;
public:
	COORD last_coord;
	//Construtor
	obstacle(Obstacle);
	//Initialize
	void init(int x, int y, COORD start, COORD end, Key mov = RIGHT);
	//Access to private members
	void setXY(int, int);
	void setSpeed(int);
	void setActive(bool isactive);
	void setAll(int x, int y, int speed, bool isactive);
	int getX();
	int getY();
	COORD getXY();
	int getSpeed();
	Obstacle getId();
	bool isActive();
	virtual void move(Key);
	virtual bool update();
};

class player : public obstacle {
public:
	player(int, int, COORD, COORD);
};

