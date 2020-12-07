#include"Automata.h"

int main() {
	Automata test;
	test.cancel();
	cout << test.getState().str();
	return 0;
}