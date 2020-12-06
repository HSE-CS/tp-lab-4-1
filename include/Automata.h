#ifndef TP_LAB_4_1_AUTOMATA_H
#define TP_LAB_4_1_AUTOMATA_H

#include <string>
#include <map>

using namespace std;

enum STATES {OFF, WAIT, ACCEPT, CHECK, COOK};

class Automata{
private:
    double cash;
    map <string, double> menu;
    string target;
    STATES state;
    void check();
    void cook();
    void finish();

public:
    Automata();
    void on();
    void off();
    string getMenu();
    STATES getState();
    void coin(double);
    void choice(string);
    void cancel();
};

#endif //TP_LAB_4_1_AUTOMATA_H
