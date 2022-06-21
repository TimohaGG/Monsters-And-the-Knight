#include"Monster.h"

Monster::MonsterData Monster::monsterdata[Monster::AMOUNT]{
	//name	hp	damage	gold	skin
	{ "Slime",  20, 3, 10 ,'s'},
	{ "Goblin", 25, 4, 25, 'g' },
	{ "Zombie", 30, 4, 30, 'Z' },
	{ "Sceletton", 30, 5, 30, 'S' },
	{ "Orc", 50, 8, 50, 'O'},
	{ "Giant", 70, 15, 70, 'G' },
	{ "Dragon", 100, 30, 100, 'D' }
};


Monster::Monster(_monsterType md)
{
	name = monsterdata[md].name;
	hp = monsterdata[md].hp;
	damage = monsterdata[md].damage;
	gold = monsterdata[md].gold;
	skin = monsterdata[md].skin;
}



int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

Monster Monster::GetRandomMonster()
{
	int num = getRandomNumber(0, Monster::AMOUNT - 1);
	return Monster(static_cast<_monsterType>(num));

}



void Monster::PrintMonsters()
{
	for (size_t i = 0; i < amount; i++)
	{
		arr[i].PrintInfo();
	}
}

Field Monster::DedloyMonsters(Field& field)
{
	for (size_t i = 0; i < amount; i++)
	{
		field.SetEntity(arr[i].x, arr[i].y, arr[i].skin);
	}
	return field;
}

bool FreeCoord(Monster* arr, int index) {
	for (size_t i = 0; i < index; i++)
	{
		if (arr[i].x == arr[index].x && arr[i].y == arr[index].y)
			return false;

	}
	return true;
}

Monster* SetCoords(Monster*& arr, int amount)
{
	for (size_t i = 0; i < amount; i++)
	{
		do {
			do {
				arr[i].x = getRandomNumber(0, FieldSize);
				arr[i].y = getRandomNumber(0, FieldSize);
			} while (arr[i].x % 10 == 0 || arr[i].y % 10 == 0 || arr[i].x % 10 == 9 || arr[i].y % 10 == 9);


		} while (!FreeCoord(arr, i));
	}
	return arr;
}




Monster* Monster::CreateMonsters(int& amount)
{
	Monster::amount = amount;
	arr = new Monster[amount];
	for (size_t i = 0; i < amount; i++)
	{
		arr[i] = Monster::GetRandomMonster();
	}
	SetCoords(arr, amount);
	return arr;
}

Monster* Monster::arr = NULL;
int Monster::amount = 10;

void Monster::MonsterData::PrintInf()
{
	cout << "Monster: " << name << " (" << skin << ")\t" << "HP: " << hp << "\t\tDamage: " << damage << "\n";
}
