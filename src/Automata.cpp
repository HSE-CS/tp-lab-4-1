#include "Automata.h"
using namespace std;

Automata::Automata() {
	state = OFF;
	cash = 0;
	install();
}

void Automata::on() {
	if (state == OFF)
		state = WAIT;
}

void Automata::off() {
	if (state == WAIT)
		state = OFF;
}

void Automata::coin(int money) {
	if ((state == WAIT) || (state == ACCEPT)) {
		state = ACCEPT;
		cash += money;
	}
}

void Automata::getMenu() {
	if (state == WAIT)
		for (int i = 0; i < menu.size(); ++i) {
			cout <<menu[i]<<'\t'<<prices[i]<<'\n' ;
		}
}

STATES Automata::getState() {
	return state;
}

void Automata::choice(string napitok) {
	if (state == ACCEPT) {
		state = CHECK;
		if (napitok != "") {
			size_t i = 0;
			for (string iter : menu) {
				if (iter == napitok) {
					check(i);
					return;
				}
				else
					++i;
			}
		}
			cancel();
	}
}

void Automata::check(int n){
	if (state == CHECK)
		if ((cash >= prices[n])&&(n<menu.size())){
			cash -= prices[n];
			state = COOK;
			cook(n);
		}
		else
			cancel();
}

void Automata::cancel(){
	if ((state == ACCEPT) || (state == CHECK)){
		state = WAIT;
		//cash = 0;
	}
}

void Automata::cook(int n){
	if (state = COOK) {
		//cook
		cout << "im cook\t"<< menu[n]<<'\n';
		finish();
	}
}

void Automata::finish() {
	if (state = COOK) {
		state = WAIT;
	}
}

void Automata::install() {
	ifstream input;
	input.open("menu.txt");
	string drink;
	for (size_t i = 0; input >> drink;++i) {
		menu.push_back(drink);
		int price = 0;
		input >> price;
		prices.push_back(price);
	}
	input.close();
}

