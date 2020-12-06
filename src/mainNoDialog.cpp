#include "../include/automataNoDialog.h"

int main()
{
	Automata automata("data.txt");
	automata.getState();
	automata.on();
	automata.getState();
	automata.getMenu();
	automata.coin();
	automata.choice();
	automata.getState();
	automata.off();
	return 0;
}