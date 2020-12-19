#ifndef TP_LAB_4_1_AUTOMATA_H
#define TP_LAB_4_1_AUTOMATA_H

#include <vector>
#include <string>

using namespace std;

enum STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

class Automata
{
private:
    double cash;
    STATES state;
    vector<string> menu = {"Tea", "Coffee", "Milk", "Chocolate", "Beer"};
    vector<int> prices = {30, 40, 50, 150, 350};
public:
    Automata();
    void on();
    void off();
    void coin(double cash);
    string getMenu();
    string getState();
    void choice(int drink);
    bool check(int drink);
    void cancel();
    void cook(int drink);
    double finish(int drink);
};

#endif //TP_LAB_4_1_AUTOMATA_H
