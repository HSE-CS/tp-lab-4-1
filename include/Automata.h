#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

enum STATES { 
	OFF, WAIT, ACCEPT, CHECK, COOK, FINISH
};

enum DRINKS {
	LATTE = 1, CAPPU, ESPRS, AMERI, HOTCH
};

class Automata {
private:
	int cash;
	int keptSum;
	static vector<string> menu;
	static vector<int> prices;
	int productChoice;
	enum STATES state;
	ostream* aout;
public:
	Automata(); //конструктор
	Automata(ostream* definedStream); //конструктор
	bool on(); // -включение автомата;
	bool off(); //-выключение автомата;
	bool coin(int coins); //-занесение денег на счёт пользователем;
	vector<string> getMenu(); // -считывание меню с напитками и ценами для пользователя;
	enum STATES getState(); // -считывание текущего состояния для пользователя;
	bool choice(int product); // -выбор напитка пользователем;
	bool check(); // -проверка наличия необходимой суммы;
	int cancel(); // -отмена сеанса обслуживания пользователем;
	bool cook(); // -имитация процесса приготовления напитка;
	int finish(); //-завершение обслуживания пользователя.
	int getKeptSum();
	void reset();
	void printBeautifulMenu();
};

#endif