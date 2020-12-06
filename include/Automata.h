#include <cmath>
#include <iostream>
#define n 4
using namespace std;
enum STATES {OFF, WAIT, ACCEPT, CHECK, COOK};
class Automata
{
private:

    int cash;
    string menu[n]={"tea", "milk", "coffee", "chocolate"};
    int prices[n]={40,50,90,75};
    STATES state;
public:
    Automata();
    void on();
    void off();
    void coin(int);
    string getMenu();
    STATES getState();
    void choice(int);
    void check(int);
    void cancel();
    void cook();
    void finish();
};