#pragma once
//----------libraries----------
#include<iostream>
#include<string>
#include<Windows.h>
#include <stdio.h>
#include <conio.h>
#include<iomanip>
//----------namespace----------
using std::cin;
using std::cout;
using std::string;
using std::setw;
using std::left;
using std::right;
//----------defines----------

#define Pause system("pause")
#define Clear system("cls")
#define FieldSize 100 
#define HANDLECON HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE)
#define SETCONSOLEPOS SetConsoleCursorPosition(hConsole, position)
#define Wait(num) Sleep(num);

