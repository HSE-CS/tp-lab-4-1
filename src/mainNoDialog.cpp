#include "../include/automataNoDialog.h"

int main()
{
	Automata automata("data.txt");
	automata.getState();
	automata.on();
	automata.getState();
	automata.getMenu();
	automata.coin(50);
	automata.choice(0);
	automata.getState();
	automata.off();
	return 0;
}