#include "Automata.h"
#include <iostream>
#include <iomanip>

Automata::Automata() {};

void Automata::on() {
	if (state == States::OFF)
		state = WAIT;
	else std::cout << "Error!!! Invalid state\n";
}

void Automata::off() {
	if (state == States::WAIT)
		state = OFF;
	else std::cout << "Error!!! Invalid state\n";
}
void Automata::coin(int new_money_user) {
	if (state == States::WAIT or state == States::ACCEPT) {
		cash += new_money_user;
		state = States::ACCEPT;
	}
	else std::cout << "Error!!! Invalid state\n";
}
void Automata::getMenu() {
	if (state != States::OFF) {
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
	if (state == States::ACCEPT) {
		size_t index = 0;
		for (; index < menu.size(); index++) {
			if (menu[index] == choise) break;
		}
		if (check(prices[index])) {
			cash -= prices[index];
			state = CHECK;
		}
		else {
			std::cout << "Not enough money. You are back in the WAIT state\n";
			cancel();
		}
	}
	else std::cout << "Error!!! Invalid state\n";
}

bool Automata::check(int price) {
	if (state == States::ACCEPT or state == States::CHECK) {
		if (cash >= price) return true;
		else return false;
	}
	else {
		std::cout << "Error!!! Invalid state\n";
		return false;
	}
}
void Automata::cancel() {
	if (state == States::ACCEPT or state == States::CHECK) {
		state = States::WAIT;
		cash = 0;
		std::cout << "Your money is refunded\n";
	}
	else std::cout << "Error!!! Invalid state\n";
}
void Automata::cook() {
	if (state == States::CHECK)
		state = States::COOK;
	else std::cout << "Error!!! Invalid state\n";
}
void Automata::finish() {
	if (state == States::COOK) {
		state = States::WAIT;
		cash = 0;
		std::cout << "Get your change\n";
	}
	else std::cout << "Error!!! Invalid state\n";
}

