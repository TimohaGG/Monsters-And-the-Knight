#include"Menu.h"

void Action(Player& player, Field& field, int& AccesableX, int& AccesableY) {

	switch (_getch()) {
	case 0x4B: {	//Left
		if (player.x - 1 < AccesableX && AccesableX - 10 >= 0) {
			AccesableX -= 10;
		}
		if (player.x - 1 >= 0 && field.GetEntity(player.x - 1, player.y) == ' ') {
			field.SetEntity(player.x, player.y, ' ');
			player.x--;
			field.SetEntity(player.x, player.y, 'P');
		}

		break;
	}

	case 72: {		//Up
		if (player.y - 1 < AccesableY && AccesableY - 10 >= 0) {
			AccesableY -= 10;
		}
		if (player.y - 1 >= 0 && field.GetEntity(player.x, player.y - 1) == ' ') {
			field.SetEntity(player.x, player.y, ' ');
			player.y--;
			field.SetEntity(player.x, player.y, 'P');
		}
		break;
	}

	case 0x4D: {	//Right
		if (player.x + 1 > AccesableX + 9 && AccesableX != FieldSize - 10) {
			AccesableX += 10;
		}
		if (player.x + 1 <= FieldSize - 1 && field.GetEntity(player.x + 1, player.y) == ' ') {
			field.SetEntity(player.x, player.y, ' ');
			player.x++;
			field.SetEntity(player.x, player.y, 'P');
		}

		break;
	}

	case 0x50: {	//Down
		if (player.y + 1 > AccesableY + 9 && AccesableY != FieldSize - 10) {
			AccesableY += 10;
		}
		if (player.y + 1 <= FieldSize - 1 && field.GetEntity(player.x, player.y + 1) == ' ') {
			field.SetEntity(player.x, player.y, ' ');
			player.y++;
			field.SetEntity(player.x, player.y, 'P');
		}
		break;
	}
	case 83:
	case 115:
	{
		Clear;
		cout << "Shop";
		Pause;
	}break;
	}

}


void ClearConsole() {
	COORD position = { 0,12 };
	HANDLECON;
	SETCONSOLEPOS;
	for (size_t i = 0; i < 15; i++)
	{
		for (size_t i = 0; i < 10; i++)
		{
			cout << " ";
		}
		cout << "\n";
	}
	position = { 0,0 };
	SETCONSOLEPOS;
}

int FindMonsterIndex(int monsterX, int monsterY) {
	for (size_t i = 0; i < Monster::amount; i++)
	{
		if (Monster::arr[i].x == monsterX && Monster::arr[i].y == monsterY) {
			return i;
		}
	}
}

bool EnemyNear(Player player, Field field, int& MonsterIndex) {
	int xTmp = player.x;
	int yTmp = player.y;
	if (field.GetEntity(player.x + 1, player.y) != ' '&& player.x +1<FieldSize) {
		xTmp = player.x + 1;
	}
	else if (field.GetEntity(player.x - 1, player.y) != ' '&&player.x-1>=0) {
		xTmp = player.x - 1;
	}
	else if (field.GetEntity(player.x, player.y + 1) != ' '&&player.y+1<FieldSize) {
		yTmp = player.y + 1;
	}
	else if (field.GetEntity(player.x, player.y - 1) != ' ' && player.y - 1 >= 0) {
		yTmp = player.y - 1;
	}
	else return false;

	MonsterIndex = FindMonsterIndex(xTmp, yTmp);
	return true;
}

void LevelChoose(Player& player) {
	
	int choise;
	do {
		Clear;
		cout << "1. Легкий\n2. Средний\n3.Сложный\n";
		cin >> choise;
	} while (choise < 0 || choise>3);

	switch (choise) {
	case 1: {
		Monster::amount = 10;	
		player.SetHP(100);
	}break;
	case 2: {
		Monster::amount = 20;
		player.SetHP(80);
	}break;
	case 3: {
		Monster::amount = 30;	
		player.SetHP(60);
	}break;
	}

}

void Menu::Options(Player& player) {
	while (true) {
		cout << "1. Уровень сложности\n";
		cout << "2. Замена скинов\n";
		cout << "3. Правила игры\n";
		int choise;
		cin >> choise;
		switch (choise) {
		case 1: {
			LevelChoose(player);
		}break;
		case 2: {}break;
		case 3: {}break;
		default: {
			Clear;
			return;
		}break;
		}
	}
	
}

int AttackMonster(Player& player, Monster& monster) {
	
	monster.DecreaseHP(player.GetDamage());
	cout << "Вы ударили монстра " << monster.GetName() << ": -" << player.GetDamage() << "HP\n";
	cout << "HP монстра: ";
	if (monster.GetHp() < 0) cout << "0\n\n";
	else cout << monster.GetHp() << "\n\n";
	if (monster.IsKilled()) {
		cout << "Вы победили монстра " << monster.GetName() << "\n";
		cout << "+ " << monster.GetGold() << " золота\n";
		cout << "Уровень повышен!\n";
		int chanse = getRandomNumber(0, 2);
		if (chanse == 0) {
			cout << "Вы получили аптечку!!\n";
			player.IncreseHP();
		}
		monster.SetKill();
		player.AddGold(monster.GetGold());
		player.IncreseLevel();

		Wait(3000);
	}
	return monster.GetHp();
}

int AttackPlayer(Player& player, Monster& monster) {
	if (!monster.IsKilled()) {
	player.DecreaseHP(monster.GetDamage());
	cout << "Вас ударил " << monster.GetName() << ": -" << monster.GetDamage() << "HP\n";
	cout << "Ваш HP: " << player.GetHp()<<"\n";
	Wait(2000);
	}
	return player.GetHp();
}

Monster DeleteMonster(int MonsterIndex) {
	Monster* tmpArr = new Monster[Monster::amount - 1];
	for (size_t i = 0; i < Monster::amount; i++)
	{
		if (i < MonsterIndex)
			tmpArr[i] = Monster::arr[i];
		else if (i > MonsterIndex)
			tmpArr[i - 1] = Monster::arr[i];
	}
	delete[] Monster::arr;
	Monster::arr = new Monster[Monster::amount - 1];
	for (size_t i = 0; i < Monster::amount - 1; i++)
	{
		Monster::arr[i] = tmpArr[i];
	}
	delete[] tmpArr;
	Monster::amount--;
	return* Monster::arr;
}

void StartFight(int MonsterIndex, Player& player) {
	COORD position = { 0,0 };
	HANDLECON;
	

	Monster& enemy = Monster::arr[MonsterIndex];
	Clear;
	do {
		AttackMonster(player, enemy);
		Wait(2000);
		AttackPlayer(player, enemy);
		
		Clear;
	} while (!player.IsKilled() && !enemy.IsKilled());
	
	Clear;
}

void Menu::BeginGame(Field field, Player player) {
	
	
	static int MonsterNumber = 10;

	Monster::CreateMonsters(MonsterNumber);
	Monster::DedloyMonsters(field);

	

	int AccesableX = 40;
	int AccesableY = 40;
	do {

		field.SetEntity(player.x, player.y, player.GetSkin());
		field.PrintAccessableField(AccesableY, AccesableX);
		cout << "Player: " << player.x << "\t" << player.y << "\n";
		cout << "HP: " << player.GetHp()<<"\n";
		cout << "Gold: " << player.GetGold()<<"\n";
		

		Action(player, field, AccesableX, AccesableY);

		int MonsterIndex;
		if (EnemyNear(player, field, MonsterIndex)) {
			StartFight(MonsterIndex, player);
			if (Monster::arr[MonsterIndex].IsKilled()) {
				field.SetEntity(Monster::arr[MonsterIndex].x, Monster::arr[MonsterIndex].y, ' ');
				DeleteMonster(MonsterIndex);

			}
				
				
		}
		ClearConsole();
		

	} while (!player.IsKilled() || Monster::amount != 0);
}