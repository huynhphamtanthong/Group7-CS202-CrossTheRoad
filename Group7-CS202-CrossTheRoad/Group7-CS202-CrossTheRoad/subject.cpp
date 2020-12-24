#include "subject.h"

obstacle::obstacle(int _x, int _y, int _vx, int _vy) {
	x = _x;
	y = _y;
	vx = _vx;
	vy = _vy;
}

int obstacle::getX() {
	return x;
}

int obstacle::getY() {
	return y;
}

char obstacle::getSymbol() {
	return symbol;
}

void obstacle::move() {
	x += vx;
	y += vy;
}

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