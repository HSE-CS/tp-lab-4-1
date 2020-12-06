#include "Automata.h"

std::string menu_[6] = {
	"water",
	"milk",
	"cacao",
	"coffe",
	"latte",
	"hot chocolate"
};

int prices_[6] = {
	2, 15, 20, 30, 40, 40
};

Automata::Automata() {
	cash = 0;
	menu = menu_;
	prices = prices_;
	state = OFF;
}

std::string Automata::getMenu() {
	std::string res = "";
	for (int i = 0; i < 6; i++) {
		res = res + menu[i]+' ';
	}
	return res;
}

void Automata::on() {
	state = WAIT;
};

void Automata::off() {
	state = OFF;
};

void Automata::coin(int s) {
	if ((state == WAIT || state == ACCEPT) && s > 2) {
		state = ACCEPT;
		cash = cash + s;
	}
};

unsigned Automata::getState() {
	unsigned _state = this->state;
	return _state;
}

void Automata::choice(unsigned int drink) {
	if (this->state != OFF) {
		this->state = CHECK;
		choice_ = drink;
		check();
	}
}

void Automata::check() {
	if (this->state != OFF) {
		//std::cout << prices[choice_];
		this->state = CHECK;
		if (choice_ <= 6) {
			if (prices[choice_] <= this->cash) {
				this->cash -= prices[choice_];
				cook();
			}
		}
		else {
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
		state = COOK;
		finish();
	}
}

void Automata::finish() {
	if (this->state != OFF) {
		state = WAIT;
	}
}

int Automata::getCoin() {
	return this->cash;
}
