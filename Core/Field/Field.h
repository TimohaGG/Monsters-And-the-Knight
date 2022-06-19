#pragma once
#include"../Lib/Lib.h"

class Field {
public:
	//----------construcor----------
	Field();

	//----------methods----------
	void PrintAllField();
	void PrintAccessableField(int y, int x);
	void SetEntity(int x, int y, char Sym);
	char GetEntity(int x, int y) { return field[y][x]; }
	
private:
	
	char field[FieldSize][FieldSize];

};