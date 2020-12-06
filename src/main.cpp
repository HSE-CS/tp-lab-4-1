#include <iostream>
#include "../include/Automata.h"

using namespace std;

int main(){
    Automata autom;
    cout << autom.getState() << endl;
    autom.on();
    cout << autom.getMenu() << endl;
    cout << autom.getState() << endl;
    autom.coin(50);
    cout << autom.getState() << endl;
    autom.choice("Double espresso");
    cout << autom.getState() << endl;
    autom.off();
    cout << autom.getState() << endl;
    cout << "\n \n \n";

    autom.on();
    autom.coin(5);
    autom.choice("Latte");
    autom.off();

    return 0;
}

