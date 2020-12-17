//
// Created by stoja on 15.12.2020.
//

#ifndef TP_LAB_4_1_AUTOMATA_H
#define TP_LAB_4_1_AUTOMATA_H
#include <vector>
#include <string>
enum STATES
{
    OFF, WAIT, ACCEPT, CHECK, COOK
};
class Automata{
  public:
    Automata();
    void on();
    void off();
    void coin(double);
    std::string getMenu();
    STATES getState();
    void choice(int);
    void check(int);
    void cancel();
    double getCash();
  private:
    void cook(int);
    void finish();
    double cash;
    std::vector<std::string> menu = {"Tea-1", "Coffee-2", "Mulled wine-3", "Milk-4", "\"B-52\"-5"};
    std::vector<double> prices = {100, 150, 200, 150, 250};
    STATES state;
};

#endif //TP_LAB_4_1_AUTOMATA_H
