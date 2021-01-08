#include "level.h"

level::level(){
	isinit = false;
}

level::level(COORD start, COORD end, int lvl) : start(start), end(end), lvl(lvl) {
	isinit = true;
}

bool level::isInit() {
	return isinit;
}

void level::init(COORD start, COORD end, int lvl) {
	this->start = start;
	this->end = end;
	this->lvl = lvl;
	isinit = true;
}

void level::generate() {
	srand(time(NULL));

	lane = 4;
	if (lvl > 4) lane = 6;
	if (lvl > 8) lane = 8;


	obj = 5 + lvl;

	for (int i = 0; i < lane; ++i) lane_rand[i] = min (rand() % obj, 10);

}

void level::createLevel() {
	srand(time(NULL));

	int padding = (end.Y - start.Y + 1) / lane;
	for (int i = 0; i < lane; ++i) {
		lanes[i].X = start.X;
		lanes[i].Y = start.Y + padding * i;
		lane_tick[i] = 0;
	}

	for (int i = 0; i < lane; ++i) light_tick[i] = rand() % 100 + 1;

	for (int i = 0; i < lane; ++i) {
		for (int j = 0; j < lane_rand[i]; ++j) {
			Obstacle ob = static_cast<Obstacle>(rand() % TRUCK + 1);
			obstacle* t = new obstacle(ob);

			lane_vector[i].push_back(t);
		}
	}
}

void level::update() {
	srand(time(NULL));


	for (int i = 0; i < lane; ++i) {
		--light_tick[i];
		if (light_tick[i] >= 0) {
			for (auto t = lane_vector[i].begin(); t != lane_vector[i].end(); ++t) {
				if (!(*t)->isActive()) {
					if (lane_tick[i] == 0) {
						lane_tick[i] = s_obj[(*t)->getId()].X + rand() % 20 + 10;
						(*t)->init(i % 2 == 0 ? -1 : start.X, lanes[i].Y + 2, start, end);
						break;
					}
				}
				else {
					if ((*t)->update()) (*t)->setActive(false);
				}	
			}
			if (lane_tick[i] > 0) --lane_tick[i];
		}
		
		if (light_tick[i] == -20) light_tick[i] = rand() % 100 + 1;
	}
}

void level::save() {


}

void level::load() {


}

void level::clear() {
	for (int l = 0; l < lane; ++l)  {
		while (lane_vector[l].size() > 0) lane_vector[l].pop_back();
	}
}