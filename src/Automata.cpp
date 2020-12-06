//Copyright 2020 Ryzhova
#include "Automata.h"

Automata::Automata() {
	cash = 0;
	state = OFF;
}

void Automata::on() {
	if (state == OFF) {
    	state = WAIT;
    	std::cout << "Insert bills into bill acceptor..." << std::endl;
	}
}

void Automata::off() {
    if (state == WAIT)
		state = OFF;
}

void Automata::coin(double cash) {
    if ((state == ACCEPT || state == WAIT) && cash > 0) {
        this->cash += cash;
		state = ACCEPT;
	}
}

double Automata::getCash() {
	return cash;
}

STATES Automata::getState() {
	return this->state;
}

std::string Automata::getMenu() {
	std::string menu;
	for (int i = 0; i < sizeof(prices)/sizeof(double); i++) {
		menu += std::to_string(i) + ". " + this->menu[i] + " - " + std::to_string(prices[i]) + "\n";
	}
	return menu;
}

void Automata::cancel() {
	if (state == ACCEPT || state == CHECK){
		state = WAIT;
		cash = 0; // money is given to the client
	}
}

void Automata::cook(int index) {
	if (state == CHECK) {
		this->state = COOK;
		std::cout << "Thank you for your purchase!" << std::endl;
		finish(index);
	}
}

void Automata::finish(int index) {
	if (state == COOK) {
		if (cash - prices[index] > 0){
			std::cout << "Don't forget your change: " << cash - prices[index] << std::endl;
		}
		cash = 0;
		this->state = WAIT;
	}
}

void Automata::check(int index) {
	if (cash >= prices[index]) {
		cook(index);
		return;
	}
	std::cout << "Not enough cash..." << std::endl;
	state = ACCEPT;
}

void Automata::choice(int index) {
	if (state == ACCEPT && index < 9 && index >= 0) {
		this->state = CHECK;
		check(index);
	}
	else
		std::cout << "Unfortunately there is no such drink..." << std::endl;
}