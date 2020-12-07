#include <iostream>
#include "Automata.h"

using namespace std;

int main() {
    Automata automata;
    automata.on();
    automata.coin(200);
    cout << automata.getCash() << endl;
    cout << automata.getState() << endl;
    automata.coin(150);
    cout << automata.getCash() << endl;
    automata.choice("coffee");
    automata.getState();
    cout << automata.getState() << endl;
    cout << automata.getCash() << endl;
    automata.off();
    automata.on();
    automata.choice("tea");
    cout << automata.getState() << endl;
    cout << automata.getCash() << endl;
    automata.off();
}
