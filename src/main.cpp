//  Copyright 2020 Nikita Naumov
#include "Automata.h"

int main() {

    Automata automata_1;

    automata_1.off();
    std::cout << "\n================================================================================================\n";
    std::cout << automata_1.getMenu();
    std::cout << "\n================================================================================================\n";
    automata_1.on();
    std::cout << "\n================================================================================================\n";
    automata_1.getMenu();
    std::cout << "\n================================================================================================\n";
    std::cout << "Automata is " << automata_1.getState();
    std::cout << "\n================================================================================================\n";

    automata_1.coin();

    int option = -1;

    while (automata_1.getState() == acceptingMoney){
        std::cout << "\n================================================================================================\n";
        std::cout << "What do you want to do?" << std::endl << "To enter money press 1\tTo order press 2\tTo cancel operation press 5" << std::endl;
        std::cin >> option;
        switch (option) {
        case 1:
            automata_1.coin();
            break;
        case 2:
            automata_1.choice();
            break;
        case 5:
            automata_1.cancel();
            break;
        default:
            std::cout << "Wrong parameter. Try again" << std:: endl;
            break;
        }
    }
    
    

    return 0;
}