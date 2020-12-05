#include "Automata.h"
#include <iostream>

Automata::Automata() {
	state = States::OFF;
	cash = 0;
}

void Automata::on() {
	if (state == OFF) {
		state = WAIT;
	}
	else {
		std::cout << "error" << std::endl;
	}
}

void Automata::off() {
	if (state == WAIT) {
		state = OFF;
	}
	else {
		std::cout << "error" << std::endl;
	}
}

void Automata::coin() {}

std::string Automata::getMenu() {}

States Automata::getState() {}

void Automata::choice() {}

void Automata::check() {}

void Automata::cancel() {}

void Automata::cook() {}

void Automata::finish() {}
