// Copyright 2020 Nikita Stifeev
#include "Automata.h"

Automata::Automata() {
	cash_money = 0;
	current_status = OFF;
	number_drink = -1;
}

int Automata::on() {
	if (current_status == OFF) {
		changeState(WAIT);
		getMenu();
		return 11;
	}
	else {
		std::cout << error[0] << std::endl;		
		return 0;
	}
}

int Automata::off() {
	if (current_status == WAIT) {
		changeState(OFF);
		return 11;
	}
	else {
		std::cout << error[1] << std::endl;
		return 1;
	}
}

int Automata::coin(int money) {
	if (current_status == WAIT || current_status == ACCEPT) {
		if (current_status == WAIT) {
			changeState(ACCEPT);
		}
		if (money > 0) {
			cash_money += money;
		}
		return 11;
	}
	else {
		std::cout << error[2] << std::endl;
		return 2;
	}
}

int Automata::choice(int drink) {
	if (current_status == ACCEPT) {
		if (drink >= 0 && drink <= 4) {
			number_drink = drink;
			changeState(CHECK);
		}
		else {
			std::cout << error[3] << std::endl;
			return 3;
		}
		return 11;
	}
	else {
		std::cout << error[4] << std::endl;
		return 4;
	}
}

int Automata::check() {
	if (current_status == CHECK) {
		if (cash_money > price[number_drink]) {
			std::cout << "Wait..." << std::endl;
			cash_money -= price[number_drink];
			return 11;
		}
		else {
			std::cout << error[5] << std::endl;
			return 5;
		}
	}
	else {
		std::cout << error[4] << std::endl;
		return 4;
	}
}

int Automata::cancel() {
	if (current_status == CHECK || current_status == ACCEPT) {
		changeState(WAIT);
		return 11;
	}
	else {
		std::cout << error[4] << std::endl;
		return 4;
	}
}

int Automata::cook() {
	if (current_status == CHECK) {
		changeState(COOK);
		return 11;
	}
	else {
		std::cout << error[4] << std::endl;
		return 4;
	}
}

int Automata::finish() {
	if (current_status == COOK) {
		changeState(WAIT);
		if (cash_money > 0) {
			std::cout << "Take the change " << cash_money << std::endl;
			cash_money = 0;
			number_drink = -1;
		}
		return 11;
	}
	else {
		std::cout << error[4] << std::endl;
		return 4;
	}
}

std::string Automata::getState() {
	static std::string states[] = { "OFF", "WAIT", "ACCEPT", "CHECK", "COOK" };
	return states[current_status];
}

void Automata::getMenu() {
	unsigned int size = sizeof(menu) / sizeof(std::string);
	for (int i = 0; i < size; i++) {
		std::cout << i << " " << menu[i] << "  " << price[i] << std::endl;
	}
}

void Automata::changeState(STATUS state) {
	current_status = state;
	switch (current_status) {
	case WAIT:
		std::cout << "wait" << std::endl;
		break;
	case ACCEPT:
		std::cout << "accept" << std::endl;
		break;
	case CHECK:
		std::cout << "check" << std::endl;
		break;
	case COOK:
		std::cout << "cook" << std::endl << "cooking" << std::endl;
		break;
	case COMPLETE:
		std::cout << "complete" << "please take it" << std::endl;
		break;
	}
}

unsigned int Automata::getCash() {
	return cash_money;
}