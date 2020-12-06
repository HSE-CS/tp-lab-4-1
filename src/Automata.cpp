#include "Automata.h"
#include <iostream>
#include <iomanip>

Automata::Automata() {};

void Automata::on() {
	if (state == OFF)
		state = WAIT;
	else std::cout << "Error!!! Invalid state\n";
}

void Automata::off() {
	if (state == WAIT)
		state = OFF;
	else std::cout << "Error!!! Invalid state\n";
}
void Automata::coin(int new_money_user) {
	if (state == WAIT or state == ACCEPT) {
		cash += new_money_user;
		state = ACCEPT;
	}
	else std::cout << "Error!!! Invalid state\n";
}
void Automata::getMenu() {
	if (state != OFF) {
		for (int i = 0; i < menu.size(); i++) {
			std::cout << std::setw(12) << std::left << menu[i] << "\t" << prices[i] << std::endl;
		}
	}
	else std::cout << "The machine is off\n";
}
States Automata::getState() {
	return state;
}
void Automata::choise(std::string choise) {
	auto index = find(menu.begin(), menu.end(), choise) - menu.begin();
	if (check(prices[index])) {
		cash -= prices[index];
		state = CHECK;
	}
	else {
		std::cout << "Not enough money. You are back in the WAIT state\n";
		cancel();
	}
}
	
bool Automata::check(int price) {
	if (state == ACCEPT or state == CHECK) {
		if (cash >= price) return true;
		else return false;
	}
	else {
		std::cout << "Error!!! Invalid state\n";
		return false;
	}
}
void Automata::cancel() {
	if (state == ACCEPT or state == CHECK) {
		state = WAIT;
		cash = 0;
		std::cout << "Your money is refunded\n";
	}
	else std::cout << "Error!!! Invalid state\n";
}
void Automata::cook() {
	if (state == CHECK)
		state = COOK;
	else std::cout << "Error!!! Invalid state\n";
}
void Automata::finish() {
	if (state == COOK) {
		state = WAIT;
		cash = 0;
		std::cout << "Get your change\n";
	}
	else std::cout << "Error!!! Invalid state\n";
}

	