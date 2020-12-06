#include <iostream>
#include "Automata.h"

using namespace std;

int main()
{
	Automata newAutomata;

	cout << "*Day 1*\n" << endl;

	newAutomata.on();

	cout << "*User clicks button 'Show menu&prices'*" << endl;
	newAutomata.printBeautifulMenu();

	cout << "*User enters 30 coins*" << endl;
	newAutomata.coin(30);

	cout << "*User chooses hot chocolate*" << endl;
	newAutomata.choice(HOTCH);
	newAutomata.check();

	cout << "*User enters 25 more coins*" << endl;
	newAutomata.coin(25);

	cout << "*User chooses hot chocolate again*" << endl;
	newAutomata.choice(HOTCH);
	newAutomata.check();
	newAutomata.cook();

	int coins = newAutomata.finish();

	cout << "*It has been " << coins << " coins returned to user*\n" << endl;
	cout << "Profit for today: " << newAutomata.getKeptSum() << endl;

	newAutomata.off();


	cout << "\n\n*Day 2*\n" << endl;

	newAutomata.on();

	cout << "*User clicks button 'Show menu&prices'*" << endl;
	newAutomata.printBeautifulMenu();

	cout << "*User enters 30 coins*" << endl;
	newAutomata.coin(30);

	cout << "*User chooses latte*" << endl;
	newAutomata.choice(LATTE);
	newAutomata.check();

	cout << "*User changes his mind and chooses espresso*" << endl;
	newAutomata.choice(ESPRS);
	newAutomata.check();
	newAutomata.cook();

	coins = newAutomata.finish();

	cout << "*It has been " << coins << " coins returned to user*\n" << endl;
	cout << "Profit for today: " << newAutomata.getKeptSum() << endl;

	newAutomata.off();


	cout << "\n\n*Day 3*\n" << endl;

	newAutomata.on();

	cout << "*User clicks button 'Show menu&prices'*" << endl;
	newAutomata.printBeautifulMenu();

	cout << "*User enters 30 coins*" << endl;
	newAutomata.coin(30);

	cout << "*User chooses latte*" << endl;
	newAutomata.choice(LATTE);
	newAutomata.check();

	cout << "*User changes his mind and decides to cancel his order*" << endl;
	coins = newAutomata.cancel();

	cout << "*It has been " << coins << " coins returned to user*\n" << endl;
	cout << "Profit for today: " << newAutomata.getKeptSum() << endl;

	newAutomata.off();

	return 0;
}