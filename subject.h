#ifndef subject_h
#define subject_h

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>

enum Obstacle {ANIMAL, DINOSAUR, BIRD, VEHICLE, TRUCK, CAR, PLAYER};
enum Key {UP, DOWN, LEFT, RIGHT, UPLEFT, UPRIGHT, DOWNLEFT, DOWNRIGHT, STOP};

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
