#include"Menu.h"

void Move(Player& player, Field& field, int& AccesableX, int& AccesableY) {

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

Monster FindMonster(int monsterX, int monsterY) {
	for (size_t i = 0; i < Monster::amount; i++)
	{
		if (Monster::arr[i].x == monsterX && Monster::arr[i].y == monsterY) {
			return Monster::arr[i];
		}
	}
}

bool EnemyNear(Player player, Field field, Monster& MonsterToFight) {
	int xTmp=player.x;
	int yTmp=player.y;
	if (field.GetEntity(player.x + 1, player.y) != ' ') {
		xTmp = player.x + 1;
	}
	else if (field.GetEntity(player.x - 1, player.y) != ' ') {
		xTmp = player.x - 1;
	}
	else if (field.GetEntity(player.x, player.y + 1) != ' ') {
		yTmp = player.y + 1;
	}
	else if (field.GetEntity(player.x, player.y - 1) != ' ') {
		yTmp = player.y - 1;
	}
	else return false;

	MonsterToFight= FindMonster(xTmp, yTmp);
	return true;
}


void Menu::Options() {
	while (true) {
		cout << "1. Уровень сложности\n";
		cout << "2. Замена скинов\n";
		cout << "3. Правила игры\n";
		int choise;
		cin >> choise;
		switch (choise) {
		case 1: {}break;
		case 2: {}break;
		case 3: {}break;
		default: {
			Clear;
			return;
		}break;
		}
	}
}

void StartFight() {
	Clear;
	
}

void Menu::BeginGame() {
	COORD position = { 0,0 };
	HANDLECON;
	Field field;
	static int MonsterNumber = 30;
	
	Monster::CreateMonsters(MonsterNumber);
	Monster::DedloyMonsters(field);

	Player player("Tim");

	int AccesableX = 40;
	int AccesableY = 40;
	do {

		field.SetEntity(player.x, player.y, player.GetSkin());
		field.PrintAccessableField(AccesableY, AccesableX);
		cout << "Player: " << player.x << "\t" << player.y << "\n";
		
		if (_getch()) {
			Move(player, field, AccesableX, AccesableY);
		}Monster MonsterToFight;
		
		if (EnemyNear(player, field, MonsterToFight)) {
			
			
			StartFight();
			
		}
		ClearConsole();


	} while (!player.IsKilled()||Monster::amount!=0);
}