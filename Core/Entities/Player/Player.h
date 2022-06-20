#pragma once
#include"../Entity/Entity.h"

class Player : public Entity {
public:
	
	int GetLevel() { return level; }
	void IncreseLevel() { level++; damage += 4; }
	void IncreseHP() { hp = 100; }
	void SetHP(int hp) { this->hp = hp; }
	Player(string name) :Entity(name, 100, 5, 0, 'P') {
		x = 45;
		y = 45;

	}
	void PrintInfo() {
		Entity::PrintInfo();
		cout << "Level: \t\t" << level << "\n";
	}
private:
	int level = 1;

};
