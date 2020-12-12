#include "Automata.h"

using namespace std;

AUTOMATA::AUTOMATA()
{
	cash = 0; state = OFF;
}

void AUTOMATA::on(){
	if (state == OFF) state = WAIT;
}
void AUTOMATA::off() {
	if (state != OFF) state = OFF;
}
void AUTOMATA::coin(int money) {
	if (state == ACCEPT || state == WAIT) { 
		state = ACCEPT;
		cash = cash+money; }
}
string AUTOMATA::getMenu() {
	string info = "";
	int num = 0;
	for (int i = 0; i < (menu.size()); i++) {

		num = num + 1;
		info += to_string(num) + " " + menu[i] + " " + to_string(prices[i]) + '\n';
	}
	return info;
}
STATES AUTOMATA::getState() {
	return state;
}
void AUTOMATA::choice(int number) {
	if (state == ACCEPT) {
		state = CHECK;
		check(number-1);
	}
}
void AUTOMATA::check(int number) {
	if (cash >= prices[number]) {
		cook(number);
		return;
	}
	cout << "Not enough coins" << endl;
	state = ACCEPT;
}
void AUTOMATA::cancel() {
	if (state == ACCEPT || state == CHECK) {
		state = WAIT;
		cash = 0;
		cout << "Canceled" << endl;
	}
}
void AUTOMATA::cook(int number) {
	state = COOK;
	cout << "Cooking..." << endl;
	finish(number);
}
void AUTOMATA::finish(int number) {
	cout << "Get rest of money: " << cash - prices[number] << endl;
	cash = 0;
	state = WAIT;
}
double AUTOMATA::getCash() const {
	return cash;
}
