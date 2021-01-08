#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "subject.h"

using namespace std;

class level {
	bool isinit;
public:
	COORD lanes[8];
	int lane_rand[8];
	int lane_tick[8];
	int light_tick[8];
	vector<obstacle*> lane_vector[8];
	int lane;
	int obj;
	int lvl;
	COORD start, end;
	level();
	level(COORD start, COORD end ,int lvl = 0);
	bool isInit();
	void init(COORD start, COORD end, int lvl = 0);
	void generate();
	void createLevel();
	void update();
	void save();
	void load();
	void clear();
	
};