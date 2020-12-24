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

// Dinosaur
dinosaur::dinosaur() {
	x = 0;
	y = 0;
	vx = 0;
	vy = 0;
	// symbol
}

dinosaur::dinosaur(int _x, int _y, int _vx, int _vy) {
	x = _x;
	y = _y;
	vx = _vx;
	vy = _vy;
	// symbol
}

int dinosaur::getX() {
	return animal::getX();
}

int dinosaur::getY() {
	return animal::getY();
}

char** dinosaur::getSymbol() {
	return a;
}

void dinosaur::move() {
	animal::move();
}

// Bird
bird::bird() {
	x = 0;
	y = 0;
	vx = 0;
	vy = 0;
	// symbol
}

bird::bird(int _x, int _y, int _vx, int _vy) {
	x = _x;
	y = _y;
	vx = _vx;
	vy = _vy;
	// symbol
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
	// symbol
}

truck::truck(int _x, int _y, int _vx, int _vy) {
	x = _x;
	y = _y;
	vx = _vx;
	vy = _vy;
	// symbol
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

void truck::move() {
	vehicle::move();
}

// Car
car::car() {
	x = 0;
	y = 0;
	vx = 0;
	vy = 0;
	// symbol
}

car::car(int _x, int _y, int _vx, int _vy) {
	x = _x;
	y = _y;
	vx = _vx;
	vy = _vy;
	// symbol
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