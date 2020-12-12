#include "Automata.h"
using namespace std;

int main() {
    AUTOMATA a;
    if (OFF == a.getState()) cout << "true test1" << endl;
    a.on();
    if (WAIT == a.getState()) cout << "true test2" << endl;
    a.cancel();
    if (WAIT == a.getState()) cout << "true test3" << endl;
    a.on();
    a.coin(10);
    a.cancel();
    if (0 == a.getCash()) cout << "true test4" << endl;
    a.on();
    a.coin(10);
    a.cancel();
    a.off();
    if (OFF== a.getState()) cout << "true test5" << endl;
    a.on();
    a.coin(10);
    if (ACCEPT== a.getState()) cout << "true test6" << endl;
    a.off();
    a.on();
    a.coin(30);
    a.choice(5);
    if (a.getState()== WAIT) cout << "true test7" << endl;
    a.off();
    a.cancel();
    if (a.getState()== OFF) cout << "true test8" << endl;
    a.on();
    a.coin(6.1);
    a.choice(5);
    if (ACCEPT== a.getState()) cout << "true test9" << endl;
    a.coin(30);
    a.cancel();
    if (a.getState()== WAIT) cout << "true test10" << endl;
    
}
