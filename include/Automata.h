#include <vector>
#include <string>

#ifndef INCLUDE_TASK_H_
#define INCLUDE_TASK_H_

enum State{
	OFF,
	WAIT,
	ACCEPT,
	CHECK,
	COOK,
};

class Automata{
private:
	int cash;
	std::vector <std::string> menu;
	std::vector <int> prices;
	State state;
public:
	Automata(std::vector <std::string> menu, std::vector <int> prices);
	void on();
	void off();
	void coin(int coins);
	std::string getMenu();
	State getState();
	void choice(int number);
	bool check(int number);
	void cancel();
	void cook();
	void finish();
};

#endif /* INCLUDE_TASK_H_ */
