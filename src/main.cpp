#include"Automata.h"

int main() {
	Automata test;
	test.on();
	test.coin(40);
	test.choice(1);
	cout << test.sgetState();
	return 0;
}