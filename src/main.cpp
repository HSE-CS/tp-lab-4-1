#include<iostream>
#include"Automata.h"


int main() {

  unsigned int ch;
  int cash = 0;

  Automata avt;
  avt.getState();

  std::cout << " avt.on() " << std::endl;
  avt.on();
  avt.getState();

  std::cout << " avt.getMenu() " << std::endl;
  avt.getMenu();
  avt.getState();

  std::cout << " avt.getCoin(10) " << std::endl;
  avt.coin(10);
  std::cout<< avt.get_cash() << std::endl;
  avt.getState();

  std::cout << " avt.getChoice(1) ( lemonade = 60 ) " << std::endl;
  avt.choice(1);
  std::cout << avt.get_ch() << std::endl;
  avt.getState();

  std::cout << " avt.check() and avt.canel() " << std::endl;
  if (avt.check() == false) avt.cancel();
  avt.getState();

  std::cout << " avt.coin(50) " << std::endl;
  avt.coin(50);
  std::cout << avt.get_cash() << std::endl;
  std::cout << " avt.coin(10) " << std::endl;
  avt.coin(10);
  std::cout << avt.get_cash() << std::endl;
  avt.getState();

  std::cout << " avt.choice(1) ( lemonade = 60 ) " << std::endl;
  avt.choice(1);
  std::cout << avt.get_ch() << std::endl;
  avt.getState();

  std::cout << " avt.check() and cook() " << std::endl;
  if (avt.check() == true) avt.cook();
  avt.getState();

  std::cout << " avt.finish() " << std::endl;
  avt.finish();
  avt.getState();

  std::cout << " avt.off() " << std::endl;
  avt.off();
  avt.getState();

}