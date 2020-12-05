//Copyright 2020 FOM
#include "Automata.h"
#include <iostream>

using namespace std;

int main() {
    Automata automata_1;
    automata_1.on();
    cout << automata_1.getMenu() << endl;
    cout << automata_1.getState() << endl;
    automata_1.cancel();
    cout << automata_1.getState() << endl;
    automata_1.choice(0);
    automata_1.check(0);
    automata_1.off();
    cout << automata_1.getState() << endl;
    return 0;
}
