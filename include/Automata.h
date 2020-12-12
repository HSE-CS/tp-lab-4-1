#pragma once
#define AUTOMATA_H
#ifdef AUTOMATA_H
#include <vector>
#include <string>
#include <iostream>

using namespace std;
enum STATES
{
	OFF, WAIT, ACCEPT, CHECK, COOK
};
class AUTOMATA
{
public:
    AUTOMATA();
    void on();
    void off();
    void coin(int money);
    string getMenu();
    STATES getState();
    void choice(int number);
    void check(int number);
    void cancel();
    void cook(int number);
    void finish(int number);
    double getCash() const;

private:
	int cash;
	vector <string> menu = { "Coffee", "Black tea", "Green tea" ,"Latte", "Espresso" };;
	vector <int> prices = { 25, 10,15,35,30 };
	STATES state;

};



#endif // AUTOMATA_H

