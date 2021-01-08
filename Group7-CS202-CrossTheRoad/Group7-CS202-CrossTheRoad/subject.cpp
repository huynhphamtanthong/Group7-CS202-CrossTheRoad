#include "subject.h"

// Obstacle
obstacle::obstacle() {
	x = 0;
	y = 0;
	vx = 0;
	vy = 0;
}

// Animal
animal::animal() {
	x = 0;
	y = 0;
	vx = 0;
	vy = 0;
}

int animal::getX() {
	return x;
}

int animal::getY() {
	return y;
}

void animal::move() {
	x += vx;
	y += vy;
}

// dog
dog::dog() {
	x = 0;
	y = 0;
	vx = 0;
	vy = 0;
	for (int i = 0; i < 20;++i) {
		a[i] = new char[20];
	}
	for (int i = 0;i < 20;++i) {
		for (int j = 0; j < 20;++j)
			a[i][j] = ' ';
	}
	a = { 0 };
}

dog::dog(int _x, int _y, int _vx, int _vy, int level) {
	x = _x;
	y = _y;
	vx = _vx * level;
	vy = _vy * level;
	for (int i = 0; i < 20;++i) {
		a[i] = new char[20];
	}
	for (int i = 0;i < 20;++i) {
		for (int j = 0; j < 20;++j)
			a[i][j] = ' ';
	}
	a = { 0 };
}

int dog::getX() {
	return animal::getX();
}

int dog::getY() {
	return animal::getY();
}

char** dog::getSymbol() {
	return a;
}

//      __
// (___()'`;
// /,    /`
// \\"--\\

void dog::drawdog() {
	a[x][y + 5] = '_';
	a[x][y + 6] = '_';

	a[x + 1][y] = '(';
	a[x + 1][y + 1] = '_';
	a[x + 1][y + 2] = '_';
	a[x + 1][y + 3] = '_';
	a[x + 1][y + 4] = '(';
	a[x + 1][y + 5] = ')';
	a[x + 1][y + 6] = 39;
	a[x + 1][y + 7] = '`';
	a[x + 1][y + 8] = ';';

	a[x + 2][y] = '/';
	a[x + 2][y + 1] = ',';
	a[x + 2][y + 6] = '/';
	a[x + 2][y + 7] = '`';

	a[x + 3][y] = 92;
	a[x + 3][y + 1] = 92;
	a[x + 3][y + 2] = '"';
	a[x + 3][y + 3] = '-';
	a[x + 3][y + 4] = '-';
	a[x + 3][y + 5] = 92;
	a[x + 3][y + 6] = 92;
}

void dog::move() {
	animal::move();
}

// Bird
bird::bird() {
	x = 0;
	y = 0;
	vx = 0;
	vy = 0;
	for (int i = 0; i < 20;++i) {
		a[i] = new char[20];
	}
	for (int i = 0;i < 20;++i) {
		for (int j = 0; j < 20;++j)
			a[i][j] = ' ';
	}
	drawbird();
}

bird::bird(int _x, int _y, int _vx, int _vy, int level) {
	x = _x;
	y = _y;
	vx = _vx * level;
	vy = _vy * level;
	for (int i = 0; i < 20;++i) {
		a[i] = new char[20];
	}
	for (int i = 0;i < 20;++i) {
		for (int j = 0; j < 20;++j)
			a[i][j] = ' ';
	}
	a = { 0 };
}

int bird::getX() {
	return animal::getX();
}

int bird::getY() {
	return animal::getY();
}

char** bird::getSymbol() {
	return a;
}

// ^v^

void bird::drawbird() {
	a[x][y] = '^';
	a[x][y + 1] = 'v';
	a[x][y + 2] = '^';
}

void bird::move() {
	animal::move();
}

// Vehicle
vehicle::vehicle() {
	x = 0;
	y = 0;
	vx = 0;
	vy = 0;
}

int vehicle::getX() {
	return x;
}

int vehicle::getY() {
	return y;
}

void vehicle::move() {
	x += vx;
	y += vy;
}

// Truck
truck::truck() {
	x = 0;
	y = 0;
	vx = 0;
	vy = 0;
	for (int i = 0; i < 20;++i) {
		a[i] = new char[20];
	}
	for (int i = 0;i < 20;++i) {
		for (int j = 0; j < 20;++j)
			a[i][j] = ' ';
	}
	a = { 0 };
}

truck::truck(int _x, int _y, int _vx, int _vy, int level) {
	x = _x;
	y = _y;
	vx = _vx * level;
	vy = _vy * level;
	for (int i = 0; i < 20;++i) {
		a[i] = new char[20];
	}
	for (int i = 0;i < 20;++i) {
		for (int j = 0; j < 20;++j)
			a[i][j] = ' ';
	}
	a = { 0 };
}

int truck::getX() {
	return vehicle::getX();
}

int truck::getY() {
	return vehicle::getY();
}

char** truck::getSymbol() {
	return a;
}

//	  _____
//	 |     |__
//	 |_____|__|
//	 (O) (O)
void truck::drawtruck() {
	for (int i = 1; i <= 5; ++i)
	{
		a[x][y + i] = '_';
		a[x + 2][y + i] = '_';
	}
	a[x + 1][y] = '|';
	a[x + 2][y] = '|';
	a[x + 1][y + 6] = '|';
	a[x + 2][y + 6] = '|';
	a[x + 2][y + 9] = '|';

	a[x + 3][y] = '(';
	a[x + 3][y + 1] = 'O';
	a[x + 3][y + 2] = ')';
	a[x + 3][y + 4] = '(';
	a[x + 3][y + 5] = 'O';
	a[x + 3][y + 6] = ')';
	
}

void truck::move() {
	vehicle::move();
}

// Car
car::car() {
	x = 0;
	y = 0;
	vx = 0;
	vy = 0;
	for (int i = 0; i < 20;++i) {
		a[i] = new char[20];
	}
	for (int i = 0;i < 20;++i) {
		for (int j = 0; j < 20;++j)
			a[i][j] = ' ';
	}
	drawcar();
}

car::car(int _x, int _y, int _vx, int _vy, int level) {
	x = _x;
	y = _y;
	vx = _vx * level;
	vy = _vy * level;
	a = new char* [20];
	for (int i = 0; i < 20;++i) {
		a[i] = new char[20];
	}
	for (int i = 0;i < 20;++i) {
		for (int j = 0; j < 20;++j)
			a[i][j] = ' ';
	}
	drawcar();
}

int car::getX() {
	return vehicle::getX();
}

int car::getY() {
	return vehicle::getY();
}

char** car::getSymbol() {
	return a;
}

//   /__\
// (O)--(O)
void car::drawcar() {
	a[x][y + 2] = '/';
	a[x][y + 3] = '_';
	a[x][y + 4] = '_';
	a[x][y + 5] = 92;
	a[x + 1][y] = '(';
	a[x + 1][y + 1] = 'O';
	a[x + 1][y + 2] = ')';
	a[x + 1][y + 3] = '-';
	a[x + 1][y + 4] = '-';
	a[x + 1][y + 5] = '(';
	a[x + 1][y + 6] = 'O';
	a[x + 1][y + 7] = ')';
}

void car::move() {
	vehicle::move();
}

// Player
player::player(int _x, int _y) {
	x = _x;
	y = _y;
}

int player::getX() {
	return x;
}

int player::getY() {
	return y;
}

char player::getSymbol() {
	return symbol;
}

void player::up(int d = 1) {
	x -= d;
	if (x < 0) x = 0;
}

void player::down(int d = 1) {
	x += d;
}
void player::left(int d = 1) {
	y -= d;
	if (y < 0) y = 0;
}

void player::right(int d = 1) {
	y += d;
}

bool player::isDead() {
	return dead;
}

bool player::isImpact(obstacle* animal) {
	return x == animal->getX() and y == animal->getY();
}