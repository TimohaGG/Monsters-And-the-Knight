
#include"UI/Menu/Menu.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	Field field;
	string PlayerName = "tim";
	Player player(PlayerName);

	static int MonsterNumber = 10;
	Monster::CreateMonsters(MonsterNumber);

	Menu menu(field, player);

}