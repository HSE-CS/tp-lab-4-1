  // Copyright Nikolaev Ivan

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Automata.h"


int main()
{
    Automata automata = Automata();
    automata.on();
    cout << automata.getMenu();
    automata.coin(55);
    automata.choice(4);
    automata.off();

    cout << "===============";
    Automata automata2 = Automata();
    automata2.on();
    cout << automata.getMenu();
    automata.coin(10);
    automata.choice(4);
    automata.off();
	return 0;
}