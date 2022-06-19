#include "Field.h"

void PrintSymbols(int amount) {
	for (size_t i = 0; i < amount; i++)
	{
		cout << "# ";
	}
	cout << "\n";
}
void Field::PrintAllField()
{
	PrintSymbols(FieldSize + 2);
	for (size_t i = 0; i < FieldSize; i++)
	{
		for (size_t j = 0; j < FieldSize + 1; j++)
		{
			if (j == 0)
				cout << "# " << field[i][j] << " ";
			else if (j == FieldSize)
				cout << "# ";
			else
				cout << field[i][j] << " ";
		}
		cout << "\n";
	}
	PrintSymbols(FieldSize + 2);
}


void Field::PrintAccessableField(int y, int x)
{
	PrintSymbols(12);
	for (size_t i = y; i < y + 10; i++)
	{
		for (size_t j = x; j < x + 11; j++)
		{
			if (j == x)
				cout << "# " << field[i][j] << " ";
			else if (j == x + 10)
				cout << "# ";
			else
				cout << field[i][j] << " ";
			/*if (j == x || j == x + 11)
				cout << "# ";
			else
				cout << field[i][j]<<" ";*/
		}
		cout << "\n";
	}

	PrintSymbols(12);
}

void Field::SetEntity(int x, int y, char Sym)
{
	field[y][x] = Sym;
}

Field::Field()
{
	for (size_t i = 0; i < FieldSize; i++)
	{
		for (size_t j = 0; j < FieldSize; j++)
		{
			field[i][j] = ' ';
		}
	}

}
