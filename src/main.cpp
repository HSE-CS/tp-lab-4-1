#include "Automata.h"
#include <iostream>

int main()
{
    Automata automata;
    automata.on();
    cout << automata.getMenu();
    automata.coin(500);
    automata.choice(2);
    return 0;
}