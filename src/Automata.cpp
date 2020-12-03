// Copyright 2020 <Jiiijyyy>
#include "Automata.h"

Automata::Automata() {
	this->cash = 0;
	this->state = OFF;
	this->choices = 8;
}

void Automata::on() {
	this->state = WAIT;
	return;
}

void Automata::off() {
	this->state = OFF;
	return;
}

void Automata::coin(int money) {
	if (this->state == OFF)
		return;
	else {
		this->state = ACCEPT;
		this->cash += money;
		return;
	}
}

int Automata::getCoin() {
	return this->cash;
}

std::string Automata::getMenu() {

}

unsigned Automata::getState() {
	return this->state;
}

void Automata::choice(unsigned choice) {

}

void Automata::check() {

}

void Automata::cancel() {

}

void Automata::cook() {

}

void Automata::finish() {

}
