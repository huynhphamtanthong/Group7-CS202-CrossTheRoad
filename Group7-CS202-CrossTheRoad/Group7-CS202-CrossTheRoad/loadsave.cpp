#include "loadsave.h"

int loadgame(){ // Name, Level, Points
	std::ifstream load;
	load.open("SavedGames.txt");
	if (!load.is_open()) {
		std::cout << "Cannot open file!" << std::endl;
		return 0;
	}
	else
	{
		int level[100], point[100]; std::vector<std::string> name;
		int i = 0;
		int choice = -1;
		std::string tmp;
		std::cout << "Please choose any games you wanna continue." << std::endl;
		while (!load.eof()) {
			load >> level[i];
			load >> point[i];
			load >> tmp;
			name.push_back(tmp);
			std::cout << "No." << i + 1 << " : " << tmp << "; Level: " << level[i] << "; Points: " << point[i] << std::endl;
			++i;
		}
		std::cin >> choice;
		return level[choice - 1];
	}
}

void savegame(int level, int point) { // already getch 'S' or other keys
	std::cout << "Input name of this game: " << std::endl;
	std::string name;
	getline(std::cin, name, '\n');
	std::ofstream save;
	save.open("SavedGames.txt");
	if (!save.is_open())
		std::cout << "Cannot open file!." << std::endl;
	else {
		save << name << " " << level << " " << point << std::endl;
	}
}
