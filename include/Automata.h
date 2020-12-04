#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <vector>
#include <string>

enum STATES {OFF, WAIT, ACCEPT, CHECK, COOK};

class Automata
{
private:
	int cash;
	std::vector <std::string> menu;
	std::vector <int> prices;
	int drink_index;
	STATES state; 

public:
	Automata();
	void on();// -включение автомата;
	void off(); //-выключение автомата;
	void coin(int money); //-занесение денег на счёт пользователем;
	std::string getMenu(); //-считывание меню с напитками и ценами для пользователя;
	STATES getState(); // -считывание текущего состояния для пользователя;
	void choice(std::string); //-выбор напитка пользователем;
	bool check(); // -проверка наличия необходимой суммы;
	int cancel(); //-отмена сеанса обслуживания пользователем;
	void cook(); //-имитация процесса приготовления напитка;
	void finish(); //-завершение обслуживания пользователя.
};
#endif
