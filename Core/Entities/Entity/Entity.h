#pragma once
#include "../../Lib/Lib.h"

class Entity {
public:
	
	//----------constructor----------
	Entity(string name, int hp, int damage, int gold, char skin)
		:name(name), hp(hp), damage(damage), gold(gold), skin(skin), isKilled(false) {}
	Entity();

	//----------getters----------
	int GetHp() { return hp; }
	int GetDamage() { return damage; }
	int GetGold() { return gold; }
	char GetSkin() { return skin; }
	string GetName() { return name; }

	//----------setters----------
	void SetKill() { isKilled = true; }

	//----------methods----------
	bool IsKilled();
	char ChangeSkin();
	int DecreaseHP(int damage);
	int AddGold(int enemyGold);
	void PrintInfo();

	int x;
	int y;
protected:
	string name;
	int hp;
	int damage;
	int gold;
	char skin;
	bool isKilled;

};