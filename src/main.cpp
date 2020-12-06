//
// Created by sharg on 28.11.2020.
//
#include "Automata.h"


using namespace std;


int main() {
    Automata automata;
    automata.on();
    automata.printMenu();
    automata.coin(10);
    automata.choice("Teafgd");
    automata.off();
    automata.choice("Tea");
    automata.coin(22);
    automata.choice("Tea");
    automata.cancel();
    automata.coin(60);
    automata.cancel();
    automata.choice("Expresso");
    automata.coin(32);
    automata.coin(41);
    automata.choice("Expresso");
    automata.off();
    return 0;
}