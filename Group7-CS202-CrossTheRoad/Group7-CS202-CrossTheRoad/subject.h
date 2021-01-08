#ifndef subject_h
#define subject_h

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>

class obstacle {
protected:
	//coordinates and velocity
	int x, y, vx, vy;
public:
	obstacle(); //This constructor set the initial x, y, vx, vy
	//Access to private members
	virtual int getX() = 0;
	virtual int getY() = 0;
	virtual char** getSymbol() = 0;
	virtual void move() = 0; //Every time this is called vx is added to x, vy is added to y
};

class animal : public obstacle {
public:
	animal();
	//Access to private members
	int getX();
	int getY();
	virtual char** getSymbol() = 0;
	void move(); //Every time this is called vx is added to x, vy is added to y
};

class dog : public animal {
private:
	char** a; // Contain the symbol;
public:
	dog();
	dog(int, int, int, int, int level);
	//Access to private members
	int getX();
	int getY();
	char** getSymbol();
	void drawdog();
	void move(); //Every time this is called vx is added to x, vy is added to y
};

class bird :public animal {
private:
	char** a; // Contain the symbol;
public:
	bird();
	bird(int, int, int, int, int level);
	//Access to private members
	int getX();
	int getY();
	char** getSymbol();
	void drawbird();
	void move(); //Every time this is called vx is added to x, vy is added to y
};

class vehicle :public obstacle {
public:
	vehicle();
	//Access to private members
	int getX();
	int getY();
	virtual char** getSymbol() = 0;
	void move(); //Every time this is called vx is added to x, vy is added to y
};

class truck : public vehicle {
private:
	char** a; // Contain the symbol;
public:
	truck();
	truck(int, int, int, int, int level);
	//Access to private members
	int getX();
	int getY();
	char** getSymbol();
	void drawtruck();
	void move(); //Every time this is called vx is added to x, vy is added to y
};

class car : public vehicle {
private:
	char** a; // Contain the symbol;
public:
	car();
	car(int, int, int, int, int level);
	//Access to private members
	int getX();
	int getY();
	char** getSymbol();
	void drawcar();
	void move(); //Every time this is called vx is added to x, vy is added to y
};

class player {
private:
	int x, y;
	bool dead = 0;
	char symbol = 'Y';
public:
	// (0, 0) is at the top left corner
	//x-axis points downwards, y points to the right
	player(int, int); //This constructor set the initial x and y
	//Access to private members
	int getX();
	int getY();
	char getSymbol();
	bool isDead();
	//Moving by some distance
	void up(int);
	void down(int);
	void left(int);
	void right(int);
	//impact or not (this does not modify dead state)
	bool isImpact(obstacle*);
};

#endif
