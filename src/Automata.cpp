// Copyright 2020 SalakhovRamazan

#include "Automata.h"

Automata::Automata()
{
	this->cash = 0;
	this->state = OFF;
}

void Automata::off() {
	this->cash = 0;
	this->state = OFF;
}

void Automata::on() {
	this->state = WAIT;
}

States Automata::getState()
{
	return this->state;
}

void Automata::coin(int value) {
	if (this->state == WAIT || this->state == ACCEPT) {
		this->state = ACCEPT;
		this->cash += value;
	}
	else {
		std::cout << "You are already done that" << std::endl;
		return;
	}
}

std::string Automata::getMenu() {
	std::string result = "";
	int length = 0;
	for (size_t i = 0; i < MENU; i++)
{
		result += this->menu[i] + ":" + std::to_string(this->prices[i]) + "\n";
	}
	return result;
}

void Automata::choice(int value) {
	if (this->state == ACCEPT) {
		if (this->check(value)) {
			std::cout << "Wait..." << std::endl;
			this->cook();
		}
		else {
			std::cout << "You have not enough money for purchasing this product. Put more coins or chose another product." << std::endl;
			this->cancel(1);
		}
	}
}

bool Automata::check(int value) {
	if (this->state == ACCEPT)
	{
		this->state = CHECK;
		if (this->prices[value] <= this->cash) {
			return true;
		}
		return false;
	}
}

void Automata::cook() {
	if (this->state == CHECK) {
		this->state = COOK;
		std::cout << "Your order is preparing..." << std::endl;
	}
}

void Automata::cancel(int reason) {
	if (reason) {
		this->state = ACCEPT;
	}
	else
	{
		this->state = WAIT;
	}
}

void Automata::finish() {
	if (this->state == COOK) {
		this->cash = 0;
		this->state = WAIT;
	}
}