#include "Automata.h"

using namespace std;

int main()
{
    Automata a;
    a.on();
    cout << a.getMenu() << std::endl;
    a.coin(30.01);
    a.coin(5.0);
    a.choice(2);
    a.coin(50);
    a.choice(3);
    a.off();
    return 0;
}

