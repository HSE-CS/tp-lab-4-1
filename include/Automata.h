#pragma once
#include<string>
#include<iostream>

enum STATES {
  OFF,
  WAIT,
  ACCEPT,
  CHECK,
  COOK 
};



class Automata {

private:
  int cash;
  std::string* menu;
  int* prices;
  STATES state;
  int c;

public:
  Automata();

  void on();
  void off();
  void coin(int coints);
  int gcash();
  void getMenu();
  int getState();
  void choice(std::string choice);
  int gchoice();
  bool check();
  void cancel();
  void cook();
  void finish();

};