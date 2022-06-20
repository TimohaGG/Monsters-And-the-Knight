
#include"UI/Menu/Menu.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	Field field;
	string PlayerName = "tim";
	Player player(PlayerName);
	Menu menu(field, player);

}