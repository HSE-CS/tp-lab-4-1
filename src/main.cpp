#include "Automata.h"

int main() 
{
	cout << "test 1:" << endl;
	Automata a;
	cout << a.getState() << endl;
	a.on();
	cout << a.getState() << endl;
	a.coin(10, false);
	cout << a.getState() << endl;
	a.coin(15, true);
	cout << a.getState() << endl;
	a.getMenu();
	a.choice(5);
	cout << a.getState() << endl;
	cout << endl;

	cout << "test 2:" << endl;
	Automata b;
	b.on();
	b.coin(998, true);
	cout << b.getState() << endl;
	b.choice(7);
	cout << b.getState() << endl;
	cout << endl;

	cout << "test 3:" << endl;
	Automata c;
	c.on();
	c.coin(100, true);
	cout << c.getState() << endl;
	c.choice(1);
	cout << c.getState() << endl;
	c.coin(100, true);
	cout << c.getState() << endl;
	c.choice(2);
	cout << c.getState() << endl;
	c.coin(100, true);
	cout << c.getState() << endl;
	c.choice(3);
	cout << c.getState() << endl;

	return 0;
}
