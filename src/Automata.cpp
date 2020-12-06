//Copyright 2020 Pasmanik Irina
#include "Automata.h"
#include <iostream>
#include <string>

Automata::Automata() {
	state = States::OFF;
	cash = 0;
}

void Automata::on() {
	if (state == OFF) {
		state = WAIT;
	} else {
		std::cout << "Error: already on" << std::endl;
	}
}

void Automata::off() {
	if (state == WAIT) {
		state = OFF;
	} else {
		std::cout << "Error: in process" << std::endl;
	}
}

void Automata::coin(int coin) {
	if (state == WAIT) {
		state = ACCEPT;
	}
	cash += coin;
	std::cout << "Deposited cash:  " << cash << std::endl;
}

std::string Automata::getMenu() {
	if (state == OFF) {
		std::cout << "Error: need to turn on" << std::endl;
	} else {
		std::string menu = "";
		for (int i = 0; i < SIZE; i++) {
			menu += std::to_string(i+1) + "  " + Automata::menu[i] + "  " + std::to_string(Automata::prices[i]) + "\n";
		}
		return menu;
	}
}

States Automata::getState() {
	return state;
}

int Automata::getCash() {
	return cash;
}

void Automata::choice(int pos) {
	if (state != ACCEPT) {
		std::cout << "Error: cannoot accept" << std::endl;
	} else {
		int choice = pos - 1;
		check(choice);
	}
}

void Automata::check(int pos) {
	state = CHECK;
	if (cash >= Automata::prices[pos]) {
		cash -= Automata::prices[pos];
		std::cout << "Deposited cash:  " << cash << std::endl;
		cook();
	} else {
		cancel();
	}
}

void Automata::cancel() {
	if (state != OFF) {
		std::cout << "Operation is canceled" << std::endl;
		finish();
	}
}

void Automata::cook() {
	state = COOK;
	std::cout << "Please wait..." << std::endl;
	std::cout << "brrrrrrrrrrrrrrr pff" << std::endl;
}

void Automata::finish() {
	state = WAIT;
	cash = 0;
}
