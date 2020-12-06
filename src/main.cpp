#include "Automata.h"

int main()
{
    Automata atom;
    cout<<atom.getState()<<endl;
    atom.on();
    cout<<atom.getMenu()<<endl;
    cout<<atom.getState()<<endl;
    atom.coin(100);
    cout<<atom.getState()<<endl;
    atom.choice(2);
    cout<<atom.getState()<<endl;
    atom.check(2);
    cout<<atom.getState()<<endl;
    atom.off();
    cout<<atom.getState()<<endl;
    return 0;
}//