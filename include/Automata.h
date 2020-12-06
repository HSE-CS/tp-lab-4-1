#include <string>
#ifndef Automata_H
#define Automata_H
class Automata
{
    private:
        enum States {OFF,WAIT,ACCEPT,CHECK,COOK,FINISH};
        int cash,number,change;
        std :: string menu[3] = {"coffe","tea","coca-cola"};
        int price [3] = {50,15,30};
        States state;
    public:
        Automata();
        void on();
        void off();
        void coin(int cout);
        std:: string* getMenu();
        Automata::States getState();
        void choice(int number);
        bool check();
        void cook();
        int finish();
        int cancel();
		int getCash();

        
};
#endif