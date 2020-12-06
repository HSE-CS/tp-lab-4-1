//Copyright (c) 2020 Sozinov Kirill

#include "Automata.h"
#include <string>
#include <utility>
#include <vector>

Automata::Automata(std::vector<std::string> menu, std::vector<unsigned int> prices) {
	cash = 0;
	this->menu = menu;
	this->prices = prices;
	state = OFF;
}

void Automata::on() {
	if (state == OFF) {
		state = WAIT;
	}
}

void Automata::off() {
	if (state == WAIT) {
		state = OFF;
	}
}

void Automata::coin(unsigned int money) {
	if (state == WAIT || state == ACCEPT) {
		if (state == WAIT) {
			state = ACCEPT;
		}
		cash += money;
	}
}

std::pair< std::vector <std::string>, std::vector <unsigned int> > Automata::getMenu() {
	return std::make_pair(this->menu, this->prices);
}


STATES Automata::getState()  {
	return state;
}

bool Automata::check(unsigned int drink_index) {
	return this->cash > prices[drink_index];
}

void Automata::choice(unsigned int drink_index) {
	if (state == ACCEPT) {
		state = CHECK;
		if (check(drink_index)) {
			cash -= prices[drink_index];
			cook();
		}
		else
			cancel();
	}
}

void Automata::cancel() {
	state = WAIT;
	cash = 0;
}

void Automata::cook() {
	if (state == CHECK) {
		state == COOK;
		finish();
	}
}

void Automata::finish() {
	if (state == COOK)
		state = WAIT;
}