#ifndef subject_h
#define subject_h

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>

<<<<<<< Updated upstream
enum Obstacle {ANIMAL, DINOSAUR, BIRD, VEHICLE, TRUCK, CAR, PLAYER};
=======
enum Obstacle {ANIMAL, DOG, BAT, VEHICLE, BUS, CAR, PLAYER};
>>>>>>> Stashed changes
enum Key {UP, DOWN, LEFT, RIGHT, UPLEFT, UPRIGHT, DOWNLEFT, DOWNRIGHT, STOP};

const int START_SPEED = 1;

<<<<<<< Updated upstream
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

=======
const COORD s_player = {5, 4};
const unsigned char c_player[5 * 4 + 1] = " ,,, (o o) /_\\  ``` ";

/* 
   ,,,
  (o o)
   /_\
   ``` 
*/

const COORD s_dog = {9, 4};
const unsigned char c_dog[9 * 4 + 1] ="     __  (___()'`;/,    /` \\\\'--\\\\  ";

//      __
// (___()'`;
// /,    /`
// \\'--\\ 


const COORD s_bat = {23, 7};
const unsigned char c_bat[23 * 7 + 1]= " /\\                 /\\ / \\'._   (\\_/)   _.'/ \\|.''._'--(o.o)--'_.''.| \\_ / `;=/ ' \\=;` \\ _/    `\\__| \\___/ |__/`           \\(/|\\)/                 ' ` '         ";
/*
 /\                 /\
/ \'._   (\_/)   _.'/ \
|.''._'--(o.o)--'_.''.|
 \_ / `;=/ ' \=;` \ _/
   `\__| \___/ |__/`
        \(/|\)/       
         ' ` '
*/

const COORD s_car = {8, 3};
const unsigned char c_car[8 * 3 + 1] = "   __     /<>\\  (O)--(O)";

/*
    __
   /<>\ 
 (O)--(O)
*/

const COORD s_bus = {17, 4};
const unsigned char c_bus[17 * 4 + 1] = "   _____________  _/_|[][][][][] |(      Group 7  |=--OO-------OO--=";

/*
   _____________ 
 _/_|[][][][][] |
(      Group 7  |
=--OO-------OO--=
*/




>>>>>>> Stashed changes
class obstacle {
protected:
	//coordinates and velocity
	int x, y, speed;
	//condition
	bool isactive;
	//identity
	Obstacle id;
	//state
	Key state;
public:
	//Construtor
	obstacle(Obstacle);
	//Initialize
	void init(int x, int y, int level = 0);
	//Access to private members
	void setXY(int, int);
	void setAll(int x, int y, int speed);
	int getX();
	int getY();
	COORD getXY();
	int getSpeed();
	Obstacle getId();
	virtual void move(Key);
	virtual void update(COORD start, COORD end);
};

class player : public obstacle {
public:
	player(int, int);
};

#endif
