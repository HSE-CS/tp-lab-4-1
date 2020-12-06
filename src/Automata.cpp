// Copyright 2020 dash
#include <string>
#include <iostream>
#include "Automata.h"

Automata::Automata() {
	state = STATES::OFF;
	cash = 0;
}

void Automata::off() {
	if (state == STATES::WAIT) {
		state = STATES::OFF;
	}
}

bool Automata::coin(int cash) {
	if ((state == STATES::WAIT) && (state == STATES::ACCEPT)) {
		state = STATES::ACCEPT;
		cash += cash;
		return true;
	}
	return false;
}

std::string Automata::getMenu() {
	std::string res_m = "";
	for (int i = 0; i < M; i++) {
		res_m += std::to_string(i + 1) + " " + menu[i] + " " + std::to_string(prices[i]) + "\n";
	}
	return res_m;
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
		if (cash >= prices[num - 1]) {
			cook();
		}
	}
}

void Automata::cancel() {
	if (state == OFF) {
		return;
	}
	state = WAIT;
	cash = 0;
}

void Automata::cook() {
	state = COOK;
	finish();
}

void Automata::finish() {
	state = WAIT;
}