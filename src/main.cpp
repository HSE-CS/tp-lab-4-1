#include "Automata.h"

int main() {
	string menu[3] = {"coffee", "tea", "milk"};
	int prices[3] = {10, 15, 20};
	Automata automata1(menu, prices);
	cout << automata1.getState() << "\n";
	automata1.on();
	cout << automata1.getState() << "\n";
	automata1.coin(10);
	cout << automata1.getState() << "\n";
	cout << automata1.getCoin() << "\n";
	string* _menu = automata1.getMenu();
	cout << _menu[0] << "\n";
    automata1.choice("coffee");
	cout << automata1.getState() << "\n";
	automata1.off();
	cout << automata1.getState() << "\n";
	automata1.coin(10);
	cout << automata1.getState() << "\n";
	cout << automata1.getCoin() << "\n";
    cout << "new" << endl;
	Automata automata2(menu, prices);
	automata2.on();
	automata2.coin(10);
	automata2.choice("tea");
	//automata2.cook();
	cout << automata2.getCoin() << "\n";
}
