#ifndef subject_h
#define subject_h

class obstacle {
private:
	//coordinates and velocity
	int x, y, vx, vy;
	char symbol = 'X';
public:
	obstacle(int, int, int, int); //This constructor set the initial x, y, vx, vy
	//Access to private members
	int getX();
	int getY();
	char getSymbol();
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
