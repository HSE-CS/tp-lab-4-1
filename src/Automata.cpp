#include <iostream>
#include <vector>
#include <string>

#include "../include/Automata.h"

Automata::Automata(std::vector <std::string> menu, std::vector <int> prices){
	this->menu = menu;
	this->prices = prices;
}

void Automata::on(){
	this->state = WAIT;
}

void Automata::off(){
	this->state = OFF;
}

void Automata::coin(int coins){
	this->cash += coins;
}

std::string Automata::getMenu(){
	std::string info = "";
	for(long long unsigned i = 0; i < this->menu.size(); i++){
		info += menu[i] + " " + std::to_string(this->prices[i]) +'\n';
	}
	return info;
}

State Automata::getState(){
	return this->state;
}

void Automata::choice(int number){

	this->state = CHECK;
}
bool Automata::check(int number){
	this->state = COOK;
	return this->prices[number] <= this->cash;
}

void Automata::cancel(){
	this->state = WAIT;
}

void Automata::cook(){
	std::cout << "cooking..." << std::endl;

}

void Automata::finish(){
	this->state = WAIT;
}
