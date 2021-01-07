#ifndef subject_h
#define subject_h

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>

enum Obstacle {ANIMAL, DINOSAUR, BIRD, VEHICLE, TRUCK, CAR, PLAYER};
enum Key {UP, DOWN, LEFT, RIGHT, STOP};

class obstacle {
protected:
	//coordinates and velocity
	int x, y, speed;
	//condition
	bool isactive;
	//identity
	Obstacle id;
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
	int getSpeed();
	move(Key); //Every time this is called vx is added to x, vy is added to y
};

class player : protected obstacle {
public:
	player();
};

#endif
