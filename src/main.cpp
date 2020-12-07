#include <iostream>

#include "../include/Automata.h"
using namespace std;


int main(){

	cout << "tp-lab-4-1!!!1!" << endl;
	vector <string> menu;
	vector <int> prices;

	menu.push_back("tea"); prices.push_back(25);
	menu.push_back("coffee"); prices.push_back(45);

	Automata test(menu, prices);
	cout << test.getMenu();
	test.coin(20);
	cout << test.check(0);
	test.coin(10);
	cout << test.check(0);

	return 0;
}
