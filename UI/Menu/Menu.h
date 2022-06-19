#pragma once
#include"../../Core/Lib/Lib.h"
#include"../../Core/Entities/Player/Player.h"
#include"../../Core/Entities/Monster/Monster.h"
#include"../../Core/Field/Field.h"

void Move(Player& player, Field& field, int& AccesableX, int& AccesableY);

void ClearConsole();

bool EnemyNear(Player player, Field field);

struct Menu {
	Menu() {
		while (true) {
			cout << "1. Новая игра\n";
			cout << "2. Настройки\n";
			cout << "3. Выход\n";
			int choise;
			cin >> choise;
			switch (choise) {
			case 1: {
				Clear;
				BeginGame();
			}break;
			case 2: {
				Clear;
				Options();
			}break;
			default:
				exit(0);
			}
		}
	}

	void Options();
	void BeginGame();
};