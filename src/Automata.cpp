#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include "Automata.h"

using namespace std;

vector<string> Automata::menu = {
	"LATTE", "CAPPU", "ESPRS", "AMERI", "HOTCH"
};

vector<int> Automata::prices = {
	40, 45, 30, 35, 50
};

Automata::Automata() //конструктор
{
	keptSum = 0;
	state = OFF;
	cash = 0;
	aout = (&cout);
	*(aout) << "AUTO SET" << endl;
}

Automata::Automata(ostream* definedStream) //конструктор
{
	keptSum = 0;
	state = OFF;
	cash = 0;
	aout = definedStream;
	*(aout) << "AUTO SET" << endl;
}

bool Automata::on() // -включение автомата;
{
	if (!state)
	{
		state = WAIT;
		return true;
	}
	return false;
}

bool Automata::off() //-выключение автомата;
{
	if (state == WAIT)
	{
		state = OFF;
		return true;
	}
	else
	{
		*(aout) << "END OP 1ST" << endl; //end operation first
		return false;
	}
}

bool Automata::coin(int coins) //-занесение денег на счёт пользователем;
{
	if (state == WAIT || state == ACCEPT) {
		cash += coins;
		state = ACCEPT;
		*(aout) << "COINS " << cash << endl;
		return true;
	}
	return false;
}

vector<string> Automata::getMenu() // -считывание меню с напитками и ценами для пользователя;
{
	return menu;
}

enum STATES Automata::getState() // -считывание текущего состояния для пользователя;
{
	return state;
}

bool Automata::choice(int product) // -выбор напитка пользователем;
{
	if (state == ACCEPT) {
		switch (product)
		{
		case LATTE:
			productChoice = LATTE - 1;
			break;
		case CAPPU:
			productChoice = CAPPU - 1;
			break;
		case ESPRS:
			productChoice = ESPRS - 1;
			break;
		case AMERI:
			productChoice = AMERI - 1;
			break;
		case HOTCH:
			productChoice = HOTCH - 1;
			break;
		default:
			*(aout) << "NO SUCH PR" << endl;
		}
		state = CHECK;
		return true;
	}
	return false;
}

bool Automata::check() // -проверка наличия необходимой суммы;
{
	if (state == CHECK) {
		if (cash >= prices[productChoice]) {
			*(aout) << "WAIT COOK" << endl;
			state = COOK;
		}
		else {
			*(aout) << "NOT ENOUGH" << endl;
			state = ACCEPT;
		}
		return true;
	}
	return false;
}

int Automata::cancel() // -отмена сеанса обслуживания пользователем;
{
	if (state == ACCEPT || state == CHECK) {
		int temp = cash;
		reset();
		return temp;
	}
}

bool Automata::cook() // -имитация процесса приготовления напитка;
{
	if (state == COOK) {
		*(aout) << "COOKING" << endl;
		keptSum += prices[productChoice];
		cash = cash - prices[productChoice];
		state = FINISH;
		return true;
	}
	return false;
}

int Automata::finish() //-завершение обслуживания пользователя.
{
	if (state == FINISH) {
		int temp = cash;
		reset();
		*(aout) << "THANK U GB" << endl;
		return temp;
	}
}

void Automata::reset()
{
	state = WAIT;
	cash = 0;
	productChoice = -1;
}

int Automata::getKeptSum()
{
	return keptSum;
}

void Automata::printBeautifulMenu()
{
	if (state != OFF) {
		map <string, int> Menu;
		for (int i = 0; i < menu.size(); i++) {
			char *temp = new char;
			itoa(i + 1, temp, 10);
			string tempStr = string(temp);
			tempStr += ' ';
			tempStr += menu[i];
			Menu.insert(make_pair(tempStr, prices[i]));
		}
		map <string, int>::iterator i;
		for (i = Menu.begin(); i != Menu.end(); i++) {
			(*aout) << i->first << ' ' << i->second << endl;
		}
	}
}