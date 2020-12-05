#ifndef AUTOMATA_AUTOMATA_H
#define AUTOMATA_AUTOMATA_H

#include <map>
#include <string>
#include <vector>

enum STATES {
    OFF, WAIT, ACCEPT, CHECK, COOK
};

class Automata {
private:
    int cash;
    bool ready_for_cooking;
    STATES state;
    std::map<std::string, int> drink_price = {
            {"coffee", 200}, {"tea", 150},
            {"milk", 100},{"water", 50},
            {"cola", 175}};
    std::string selected_drink;
public:
    Automata();

    void on();

    void off();

    void coin(int);

    std::map<std::string, int> getMenu() const;

    std::string getState() const;

    int getBalance() const;

    void choice(const std::string &);

    void check();

    void cancel();

    void cook();

    void finish();
};

#endif //AUTOMATA_AUTOMATA_H
