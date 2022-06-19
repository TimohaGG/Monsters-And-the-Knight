#pragma once
#include"../Entity/Entity.h"
#include"../../Field/Field.h"
class Monster : public Entity {
public:
	//----------getters----------
	int GetAmount() { return amount; }

	//----------setters----------
	//----------enum----------
	enum _monsterType
	{
		Slime,
		Goblin,
		Zombie,
		Sceletton,
		Orc,
		Giant,
		Dragon,
		AMOUNT
	};

	//----------constructor----------
	Monster(_monsterType md);
	Monster() : Entity() {
	};
	//----------struct----------
	struct MonsterData {
		string name;
		int hp;
		int damage;
		int gold;
		char skin;
	};

	//----------methods----------
	static MonsterData monsterdata[AMOUNT];
	static Monster GetRandomMonster();
	static Monster* CreateMonsters(int& amount);
	static void PrintMonsters();
	static Field DedloyMonsters(Field& field);
	//----------fields-----------
	static Monster* arr;

	static int amount;

};

Monster* SetCoords(Monster*& arr, int amount);
