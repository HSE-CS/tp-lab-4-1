// Copyright 1(6).12.2020 BD 
#include "Automata.h"

int main() {
    Automata a1;
    a1.on();
    cout << a1.getMenu();
    a1.coin(5);
    cout << a1.getState() << "\n";
    a1.choice(3);
    cout << a1.getState() << "\n";
    cout << a1.getCoin() << "\n";
    //cout << a1.getChange() << "\n";
    a1.finish();
    a1.off();
    //a1.coin(20);
    //cout << a1.getCoin() << "\n";
    //a1.choice(2);
    //cout << a1.getChange() << "\n";
    //a1.finish(); 
    //a1.off();
    //cout << a1.getState() << "\n";
    return 0;
}