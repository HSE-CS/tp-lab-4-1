#include "Automata.h"

int main(){
    Automata *a = new Automata();
    cout << a->on() << endl;
    
    a->printMenuToConsole();
    cout << a->choice("coffee") << endl;
    cout << a->cancel() << endl;
    cout << a->coin(12.84) << endl;
    cout << a->coin(20.0) << endl;
    cout << a->coin(100.0) << endl;
    cout << a->off() << endl;
    cout << a->choice("coffee") << endl;
    cout << a->cook() << endl << endl;

    cout << a->choice("black_tea") << endl;
    cout << a->cook() << endl;

    cout << endl << a->cancel() << endl;
    cout << a->off() << endl;
    cout << a->off() << endl;

    cout << endl;
    cout << a->on() << endl;
    cout << a->coin(30.0);
    cout << a->cancel();

    return 0;
}