//Copyright (c) 2020 Sozinov Kirill

#include "Automata.h"
#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int main()
{
	//vector<string> menu = { "black tea", "green tea", "cappuccino", "latte", "espresso", "americano", "hot chocolate" };
	//vector<unsigned int> prices = { 10, 15, 40, 40, 40, 45, 35 };
	Automata a1{};
	cout << a1.getState() << endl;
	a1.on();
	cout << a1.getState() << endl;
	a1.coin(30);
	cout << a1.getState() << endl;
	a1.coin(10);
	cout << a1.getState() << endl;
	a1.choice(2);
	cout << a1.getState() << endl;
	a1.coin(15);
	a1.choice(1);
	a1.off();
	cout << a1.getState() << endl;
	return 0;
}

