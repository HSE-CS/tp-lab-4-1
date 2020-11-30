#ifndef AUTOMATA
#define AUTOMATA
#include <string>

enum class STATES {
	OFF = 0, WAIT, ACCEPT, CHECK, COOK
};

class Automata
{
private:
	STATES state;
	int cash;
	int prices[50]; //?

public:
	Automata();
	~Automata();
	void on();
	void off();
	void coin();
	void getMenu();
	void getState();
	void choice();
	void check();
	void cancel();
	void cook();
	void finish();
};
#endif