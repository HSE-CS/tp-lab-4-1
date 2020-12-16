#include <string>
#include <vector>
#define menu_size 3


enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK };

class Automata {

private:
    STATES state;
    int cash;
    std::string menu[menu_size] = {"water","tea","coffee"};
    int prices[menu_size] = {10,15,20};

    int user_choice;


public:
    Automata();

    bool on();
    bool off();
    bool coin(double coins);
    std::string getMenu();
    STATES getState();
    bool choice(int num);
    bool check();
    bool cancel();
    bool cook();
    bool finish();

};