#include "Automata.h"
#include "windows.h"
#include <string>
// Copyright 2020 GN
#include <iostream>
void Automata::on() {
	this->state = WAIT;
}
void Automata::off() {
	this->cash = 0;
	this->state = OFF;
}
void Automata::coin(int accept) {
	if (this->state != OFF) {
		this->state = ACCEPT;
		this->cash += accept;
	}
}
string* Automata::getMenu() {
	return this->menu;
}
string Automata::getState() {
	int _state=this->state;
	return states[_state];
}
void Automata::choice(string str) {
	if (this->state != OFF) {
		this->state = CHECK;
		this->drink = str;
		check();
	}
}
void Automata::check() {
	if (this->state != OFF) {
		
		this->state = CHECK;
		string _drink = this->drink;
		cout << _drink << "\n";
		int index = 0;
		size_t len_of_array = sizeof(menu)-1;
		//cout << len_of_array<<"\n";
		for (size_t i = 0; i < len_of_array; ++i) {
			if (menu[i] == _drink) {
				index = i;
				break;
			}
		}
		if (prices[index] <= this->cash) {
			this->cash -= prices[index];
			cook();
		}
		else {
			//cout << "No money" << "\n";
			cancel();
		}
	}
}
void Automata::cancel() {
	if (this->state != OFF) {
		this->state = WAIT;
		finish();
	}
}
void Automata::cook() {
	if (this->state != OFF) {
		Sleep(5000);
		// cout << "Enjoy your drink!" << "\n";
		finish();
	}
}
void Automata::finish() {
	if (this->state != OFF) {
		//this->cash = 0;
		this->state = WAIT;
	}
}
int Automata::getCoin() {
	return this->cash;
}
