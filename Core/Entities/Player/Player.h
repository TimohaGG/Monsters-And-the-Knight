#pragma once
#include"../Entity/Entity.h"

class Player: public Entity{
public:
	int GetLevel() { return level; }
	void IncreseLevel() { level++; damage += 4; }

	Player(string name) :Entity(name, 100, 2, 0, 'P') {
		x = 45;
		y = 45;
	
	}
	void PrintInfo() {
		Entity::PrintInfo();
		cout << "Level: \t\t" << level<<"\n";
	}
private:
	int level=1;

};
