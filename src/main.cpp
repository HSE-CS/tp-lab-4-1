//
// Created by Kostin Andrej on 2020.
//
#include "Automata.h"


int main() {


    Automata automata1;

    automata1.on();
    cout << "State: "<< automata1.getState() << endl << endl;

    automata1.coin(500);
    cout << "State: "<< automata1.getState() << endl << endl;

    auto* menu = new string [9];
    menu = automata1.getMenu();
    cout << "State: "<< automata1.getState() << endl << endl;


    if (automata1.getState() == WAIT){
        cout << "SUCCESS" << endl;
    }
    automata1.cook();
    delete[] menu;

    return 0;





}