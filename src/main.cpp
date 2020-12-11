#include "Automata.h"
using namespace std;

int main() {
	

	Automata test;
	test.on();
	cout << test.getMenu()<<endl;
	int b;
	cin >> b;
	 test.choice(b);
	 cout << test.getState()<<endl;
	 int c;
	 cin >> c;
	 test.coin(c);
	 cout << test.getState()<<endl;
	 test.cook();
	 cout << test.getState() << endl;
	 test.finish();
	 cout << test.getState() << endl;
	 
	return 0;
}
