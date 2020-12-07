#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

class Automata {
public:
	enum STATES {
		OFF,
		WAIT,
		ACCEPT,
		CHECK,
		COOK,
	};
private:
	unsigned int cash{ 0 };
	unsigned int drink{ 0 };
	vector<string>menu;
	vector<unsigned int>prices;
	STATES state = STATES::OFF;
	// Приватные методы
	bool check(); //проверка наличия необходимой суммы
	stringstream finish(); //завершение обслуживания пользователя
	pair<vector<string>, vector<unsigned int>> getMenu(); //считывание меню с напитками и ценами для пользователя
public:
	//Для разработчика
	stringstream on(); //включение автомата
	stringstream off(); //выключение автомата
	stringstream getState(); //считывание текущего состояния для пользователя
	string sgetState(); //считывание текущего состояния для теста
	void read_menu(const string dir);
	//Для пользователя
	stringstream coin(unsigned int get_money); //занесение денег на счёт пользователем
	stringstream choice(unsigned int ch_drink); //выбор напитка пользователем
	stringstream cancel(); //отмена сеанса обслуживания пользователем
	stringstream cook(); //имитация процесса приготовления напитка
};

//Взаимодействие автомата с консолью
void printMenu(pair<vector<string>, vector<unsigned int>> menu);
