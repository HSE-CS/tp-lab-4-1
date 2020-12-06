#include "Automata.h"

int main() 
{
	Automata a;
	cout << "State= " << a.getState() << endl;
	a.on();
	cout << "State= " << a.getState() << endl;
	a.coin(10, false);
	cout << "State= " << a.getState() << endl;
	a.coin(15, true);
	cout << "State= " << a.getState() << endl;
	a.getMenu();
	a.choice(5);
	cout << "State= " << a.getState() << endl;
	return 0;
}
