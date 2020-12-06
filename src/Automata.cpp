#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include "Automata.h"

using namespace std;

vector<string> Automata::menu = {
	"LATTE", "CAPPU", "ESPRS", "AMERI", "HOTCH"
};

vector<int> Automata::prices = {
	40, 45, 30, 35, 50
};

Automata::Automata() //êîíñòðóêòîð
{
	keptSum = 0;
	state = OFF;
	cash = 0;
	aout = (&cout);
	*(aout) << "AUTO SET" << endl;
}

Automata::Automata(ostream* definedStream) //êîíñòðóêòîð
{
	keptSum = 0;
	state = OFF;
	cash = 0;
	aout = definedStream;
	*(aout) << "AUTO SET" << endl;
}

bool Automata::on() // -âêëþ÷åíèå àâòîìàòà;
{
	if (!state)
	{
		state = WAIT;
		return true;
	}
	return false;
}

bool Automata::off() //-âûêëþ÷åíèå àâòîìàòà;
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

bool Automata::coin(int coins) //-çàíåñåíèå äåíåã íà ñ÷¸ò ïîëüçîâàòåëåì;
{
	if (state == WAIT || state == ACCEPT) {
		cash += coins;
		state = ACCEPT;
		*(aout) << "COINS " << cash << endl;
		return true;
	}
	return false;
}

vector<string> Automata::getMenu() // -ñ÷èòûâàíèå ìåíþ ñ íàïèòêàìè è öåíàìè äëÿ ïîëüçîâàòåëÿ;
{
	return menu;
}

enum STATES Automata::getState() // -ñ÷èòûâàíèå òåêóùåãî ñîñòîÿíèÿ äëÿ ïîëüçîâàòåëÿ;
{
	return state;
}

bool Automata::choice(int product) // -âûáîð íàïèòêà ïîëüçîâàòåëåì;
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

bool Automata::check() // -ïðîâåðêà íàëè÷èÿ íåîáõîäèìîé ñóììû;
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

int Automata::cancel() // -îòìåíà ñåàíñà îáñëóæèâàíèÿ ïîëüçîâàòåëåì;
{
	if (state == ACCEPT || state == CHECK) {
		int temp = cash;
		reset();
		return temp;
	}
}

bool Automata::cook() // -èìèòàöèÿ ïðîöåññà ïðèãîòîâëåíèÿ íàïèòêà;
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

int Automata::finish() //-çàâåðøåíèå îáñëóæèâàíèÿ ïîëüçîâàòåëÿ.
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
			Menu.insert(make_pair(menu[i], prices[i]));
		}
		map <string, int>::iterator i;
		int number = 1;
		for (i = Menu.begin(); i != Menu.end(); i++) {
			(*aout) << number << ' ' << i->first << ' ' << i->second << endl;
			number++;
		}
	}
}
