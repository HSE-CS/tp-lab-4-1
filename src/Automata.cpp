//Copyright 2020 Uskova
#include "Automata.h"

#include <iostream>
#include <string>
#include <Windows.h>


Automata::Automata() {
	this->cash = 0.0;
	this->state = STATES::OFF;
}

void Automata::on() {
	if (this->state == STATES::OFF)
	{
		std::cout << "Turning on..." << std::endl;
		Sleep(3000);
		this->state = STATES::WAIT;
		std::cout << "The machine is ready to work." << std::endl;
		std::cout << " " << std::endl;
		std::cout << "Pay an amount and select a drink." << std::endl;
	}
	else
		std::cout << "The machine is already turned on." << std::endl;
}

void Automata::off() {
	if (this->state == STATES::WAIT) {
		this->state = STATES::OFF;
		std::cout << "Turning off..." << std::endl;
		Sleep(4000);
		std::cout << "The machine is off." << std::endl;
	}
	else 
		std::cout << "You should end the current session befor turning off. Click cancel." << std::endl;
}

double Automata::coin(double cash) {
	if (this->state == STATES::WAIT || this->state == STATES::ACCEPT) {
		this->state = STATES::ACCEPT;
		this->cash += cash;
		std::cout << "Credited: " << cash << std::endl;
		Sleep(1000);
		std::cout << "Your balance: " << this->cash << std::endl;
		return this->cash;
	}
	else 
		std::cout << "You can not pay an amount on the current stage. Please, take your money back.\n" << cash << std::endl;
}

double Automata::cancel() {
	this->state = STATES::WAIT;
	double money = this->cash;
	this->cash = 0.0;
	std::cout << "Take the change:\n" << money << std::endl;
	return money;
}


void Automata::getMenu() {
	if (this->state != OFF) {
		std::cout << "Menu:" << std::endl;
		for (int i = 0; i < 12; i++)
		{
			std::cout << i + 1 << ". " << this->menu[i] << " - " << this->prices[i] << std::endl;
		}
	}
	else
		std::cout << "The machine is off." << std::endl;
}

STATES Automata::getState() {
	return this->state;
}

void Automata::choice(int num) {
	if (num <= 12 && num > 0)
	{
		this->state = CHECK;
		std::cout << "Great choice!" << std::endl;
		std::cout << " " << std::endl;
		check(num);
	}
	else {
		std::cout << "Wrong number. Try again." << std::endl;
		this->state = ACCEPT;
	}
}

bool Automata::check(int num) {
	this->state = CHECK;
	if (this->prices[num - 1] <= this->cash) {
		cook(num);
		return 1;
	}
	else {
		std::cout << "Insufficient funds for the selected drink. Add " << this->prices[num - 1] - this->cash << " rub. or choose another drink." << std::endl;
		this->state = ACCEPT;
		return 0;
	}
}



void Automata::cook(int num) {
	if (this->state == CHECK) {
		this->state = COOK;
		this->cash -= this->prices[num - 1];
		std::cout << "Cooking... " << std::endl;
		Sleep(5000);
		finish();
	}
	else {
		std::cout << "Error. I can not cook on this stage." << std::endl;
	}
	

}

void Automata::finish() {
	if (this->state == COOK) {
		std::cout << "Done!" << std::endl;
		std::cout << "Take your change: " << this->cash << std::endl;
		this->cash = 0;
		this->state = WAIT;
	}
	else {
		std::cout << "Error" << std::endl;
	}

}
