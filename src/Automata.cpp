#include <iostream>
#include <string>
#include "Automata.h"

Automata::Automata() {
	this->state = OFF;
	this->cash = 0;

}

std::vector<DRINK>Automata::menu = {
	{"Coffe", 20},
	{"Coffe with milk", 35},
	{"Tea", 15},
	{"Tea with milk", 18}
};

bool Automata::off(){
	if (this->state == WAIT) {
		this->state = OFF;
                return 1;
	}
	else {
		return 0;
	}
}

bool Automata::on() {
	if (this->state != OFF)
	{
		return 0;
	}
	else {
		this->state = WAIT;
		return 1;
	}
}

void Automata::getMenu() {
	std::cout << "OUTPUTING MENU:"<<std::endl;
	for (int i = 0; i < menu.size(); i++) {
		std::cout << menu[i].name << "---" << menu[i].price << std::endl;
	}
}

void Automata::check(int n_product) {
	if (this->state == CHECK && (this->cash >= this->menu[n_product].price))
	{
		this->cash -= menu[n_product].price;
		cook(n_product);
	}
	else {
		return;
	}
		
}
void Automata::coin(double c) {
	if (this->state != WAIT && this->state != ACCEPT) {
		return;
	}
	else {
		this->cash += c;
		this->state = ACCEPT;
	}
}

double Automata::getCash() {
	return this->cash;
}
void Automata::cancel() {
	if (this->state == CHECK || this->state == ACCEPT) {
		this->state = WAIT;
		this->cash = 0;
	}
	else if (this->state == OFF)
	{
		return;
	}
}


void Automata::cook(int n_product) {
	this->state = COOK;
	std::cout << "Cooking.." << std::endl;
	finish(n_product);
}

STATES Automata::getState() {
	return this->state;
}

void Automata::finish(int sel) {
	std::cout << "Your " << menu[sel].name << " is ready" << std::endl;
	this->state = WAIT;
	this->cash = 0;
}

void Automata::choice(int sel) {
	if (this->state == ACCEPT) {
		if (sel < 4 and sel >= 0) {
			this->state = CHECK;
			std::cout << menu[sel].name << " was chosen" << std::endl;
			check(sel);
		}
	}
	else
	{
		return;
	}
}
