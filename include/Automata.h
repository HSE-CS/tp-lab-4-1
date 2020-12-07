#ifndef TASK1_AUTOMATA_H
#define TASK1_AUTOMATA_H
#include <string>
enum states {
  OFF,
  WAIT,
  ACCEPT,
  CHECK,
  COOK
};

class Automata {

 private:
  int cash;
  std::string menu[4]{"Чай", "Кофе", "Шоколад", "Кипяток"};
  int prices[4]{40, 90, 60, 5};
  states state;

  void check(int position);
  void cook(int position);
  void finish();

 public:
  Automata();
  void on();
  void off();
  void coin(int income);
  void cancel();
  void choice(int position);
  std::string getMenu();
  states getState();
};
#endif //TASK1_AUTOMATA_H
