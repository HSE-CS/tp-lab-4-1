//  Copyright 2020 PolinaP
#include "automata.h"

int main()
{
	Automata* atm = new Automata();
	atm->on();
	atm->getMenu();
	atm->getState();
	atm->coin(100);
	atm->choice(0);
	atm->finish();
	atm->off();

	return 0;
}
