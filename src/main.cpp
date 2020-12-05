#include "Automata.h"
using namespace std;

int main() {
	Automata obj;
	obj.on();
	obj.getMenu();
	cout << '\n';
	

	cout << "state=" << obj.getState() << '\n';
	obj.cancel();

	obj.coin();
	cout << "state=" << obj.getState() << '\n';
	obj.choice("tea");
	obj.off();
	cout << "state=" << obj.getState() << '\n';

	return 0;
}