#include<iostream>
#include"Automata.h"


int main() {

  Automata autmat;
  autmat.getState();
  autmat.on();
  autmat.getMenu();
  autmat.coin(30);
  std::cout << autmat.gcash() << std::endl;
  autmat.choice("lemonade");
  std::cout << autmat.gchoice() << std::endl;
  if (autmat.check() == 1) {
  autmat.cook();
  autmat.finish();
  autmat.off();
  }

}