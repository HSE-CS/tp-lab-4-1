#include <iostream>
#include <string>
#include "Automata.h"

using namespace std;
int main()
{
	Automata Drink;
	cout << "-----------------------------------------" << endl;
	Drink.on();
	Drink.coin(30);
	Drink.choice(2);
	Drink.cancel();
	cout << "-----------------------------------------" << endl;
	Drink.coin(40);
	Drink.choice(1);
	Drink.cancel();
	cout << "-----------------------------------------" << endl;
	cout << Drink.getCash() << endl;
	Drink.coin(10);
	Drink.choice(3);

}