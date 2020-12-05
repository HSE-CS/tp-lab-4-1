// Copyright 2020 Lab_4 TiNa
#include "Automata.h"
#include <iostream>
#include <string>

Automata::Automata() {
	state = OFF;
	cash = 0;
}

void Automata::on() {
	if (state == OFF)
		state = WAIT;
}

void Automata::off() {
	if (state == WAIT)
		state = OFF;
}

void Automata::coin(int money) {
	if ((state == WAIT) || (state == ACCEPT)) {
		state = ACCEPT;
		cash += money;
	}
}

std::string Automata::getMenu() {
	std::string res = "";
	for (int i = 0; i < N; i++) {
		res += std::to_string(i + 1) + "." + " " + menu[i] + "\t" + std::to_string(prices[i]) + "\n";
	}
	return res;
}

STATES Automata::getState() {
	return state;
}

void Automata::choice(int num) {
	if (state == ACCEPT) {
		state = CHECK;
		check(num - 1);
	}
}

void Automata::check(int num) {
	if (state == CHECK) {
		if (cash >= prices[num - 1])
			cook();
	}
}

void Automata::cancel() {
	if ((state == ACCEPT) || (state == CHECK)) {
		state = WAIT;
		cash = 0;
	}
		
}

void Automata::cook() {
	state = COOK;
	finish();
}

void Automata::finish() {
	state = WAIT;
}