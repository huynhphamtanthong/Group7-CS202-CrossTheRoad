#ifndef loadsave_h
#define loadsave_h

#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

int loadgame(){ // Name, Level, Points
	ifstream load;
	load.open("SavedGames.txt");
	if (!load.is_open()) {
		cout << "Cannot open file!" << endl;
		return 0;
	}
	else
	{
		int level[100], point[100], vector<string> name;
		int i = 0;
		int choice = -1;
		string tmp;
		cout << "Please choose any games you wanna continue." << endl;
		while (!load.eof()) {
			load >> level[i];
			load >> point[i];
			load >> tmp;
			name.push_back(tmp);
			cout << "No." << i + 1 << " : " << tmp << "; Level: " << level[i] << "; Points: " << point[i] << endl;
			++i;
		}
		cin >> choice;
		return level[choice - 1];
	}
}

void savegame(int level, int point) { // already getch 'S' or other keys
	cout << "Input name of this game: " << endl;
	string name;
	getline(cin, name, '\n');
	ofstream save;
	save.open("SavedGames.txt");
	if (!save.is_open())
		cout << "Cannot open file!." << endl;
	else {
		save << name << " " << level << " " << point << endl;
	}
}

#endif // !loadsave_h

