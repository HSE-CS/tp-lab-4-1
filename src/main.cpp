#include <iostream>
#include "Automata.h"

using namespace std;

int main() {
  Automata a;
  cout << a.getState() << endl;
  a.on();
  cout << a.getState() << endl;
  a.coin(20);
  a.coin(20);
  cout << a.getState() << endl;
  cout << a.get_cash() << endl;
  cout << a.getMenu();
  a.choice(2);
  cout << a.getState() << endl;
  cout << a.check() << endl;
  a.cook();
  cout << a.getState() << endl;
  a.finish();
  cout << a.getState() << endl;
  cout << a.get_cash() << endl;
  a.off();
  cout << a.getState() << endl;

} 