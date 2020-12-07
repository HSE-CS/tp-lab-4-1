#include "Automata.h"

using namespace std;

int main() {
    //Automata automata("/Users/lesyanikolaeva/Documents/lab4/lab4/file.txt");
    Automata automata;
    cout << "after creating:" << automata.getState() << endl;
    automata.on();
    cout << "after on:" << automata.getState() << endl;
    automata.getMenu();
    automata.coin(50);
    cout << "after coin:" << automata.getState() << endl;
    automata.choice("latte");
    cout << "after choice:" << automata.getState() << endl;
    automata.cook();
    cout << "after cook:" << automata.getState() << endl;
    automata.finish();
    cout << "after finish:" << automata.getState() << endl;
    automata.off();
    cout << "after off:" << automata.getState() << endl;
    return 0;
}
