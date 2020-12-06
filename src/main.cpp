#include <iostream>

#include "Automata.h"

int main() {
    Menu menu;
    menu.addItem("Cola", 12.3);
    menu.addItem("Pepsi", 13.2);

    Automata automata(&(std::cout), "1234", menu, 24.3);
    automata.on();
    automata.changeAdminPassword("1234", "4321");
    automata.getMenu();
    automata.getMenu((std::string) "4321").addItem("Lipton", 10.4);
    automata.getMenu();
    automata.coin(12.3);
    double refund = automata.cancel();
    std::cout << "Refund is " << refund << std::endl;
    automata.getMenu();
    automata.coin(4.3);
    automata.coin(10);
    automata.choice("Pepsi");
    std::cout << "My change is " << automata.getChange() << std::endl;
    automata.getState();
    std::cout << "Cash is " << automata.getCash("4321") << std::endl;

    automata.coin(104.5);
    automata.choice("Lin");
    automata.choice("Lipton");
    automata.cancel();
    automata.choice("Cola");
    automata.cook();
    std::cout << "My change is " << automata.getChange() << std::endl;
    automata.getState();
    std::cout << "Cash is " << automata.getCash("4321") << std::endl;
    automata.off();

    return 0;
}
