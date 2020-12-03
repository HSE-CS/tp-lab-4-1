// Copyright OsmanovIslam

#ifndef  AUTOMATA_H_
#define  AUTOMATA_H_

#include <iostream>
#include <vector>
#include <string>

class DRINK {
public:
	std::string name;
	double price;
};

enum STATES {
	OFF, WAIT, ACCEPT,
	CHECK, COOK
};

class Automata {
public:
	bool off();
	bool on();
	void coin(double);
	void getMenu();
	STATES getState();
	void cancel();
	void choice(int sel);
	double getCash();
	Automata();
private:
	void check(int sel);
	void cook(int sel);
	void finish(int sel);
	std::vector<double> price;
	STATES state;
	double cash;
	static std::vector<DRINK> menu;
};

#endif //AUTOMATA_H_

