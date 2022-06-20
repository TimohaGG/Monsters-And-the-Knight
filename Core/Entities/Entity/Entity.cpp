#include "Entity.h"


Entity::Entity()
{
	name = "unknown";
	hp = 0;
	damage = 0;
	gold = 0;
	skin = '0';
	isKilled = false;
}

bool Entity::IsKilled()
{
	if (hp <= 0)
		return true;
	else
		return false;
}

int Entity::DecreaseHP(int damage)
{
	return hp -= damage;
}

int Entity::AddGold(int enemyGold)
{
	return gold += enemyGold;
}

void Entity::PrintInfo()
{
	cout << "Существо: \t" << name << "\n";
	cout << "Hp: \t\t" << hp << "\n";
	cout << "Damage: \t" << damage << "\n";
	cout << "Gold: \t\t" << gold << "\n";
	cout << "Skin: \t\t" << skin << "\n";
	cout << "X: " << x << "\tY: " << y << "\n\n";
}



char Entity::ChangeSkin()
{
	cout << "Введите новый символ для существа " << name << "\n";
	char newSkin;
	cin >> skin;
	return skin;
}
