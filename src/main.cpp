#include "Automata.h"
#include <iostream>

int main()
{
    Automata automata;
    automata.on();
    cout << automata.getState();
    return 0;
}