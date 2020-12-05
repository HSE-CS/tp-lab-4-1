#include <string>
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK, };


class Automata {
private:
	int cash;
	vector<string> menu = {"colla"};
	vector<int> prices = {10};
	STATES state;

public:
	Automata();
	void on();
	void off();
	void coin(int money=10);
	void getMenu();
	STATES getState();
	void choice(string);
	void check(int);
	void cancel();
	void cook(int);
	void finish();

	void install();
};