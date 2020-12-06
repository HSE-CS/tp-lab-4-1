// Copyright 2020 Elizaveta Drobot
#include "Automata.h"


int main() {
    setlocale(LC_ALL, "Russian");
    Automata person1;
    person1.on();
    int a = 0;
    std::cout << "Автомат готов к использованию, пожалуйста положите деньги на счет		\n";
    std::cin >> a;
    person1.coin(a);
    std::cout << "Продолжайте вводить денежные средства или введите 0, чтобы перейти к выбору напитка, или введите -1, если хотите вернуть деньги\n";
    std::cin >> a;
    while (a != 0) {
        person1.coin(a);
        std::cin >> a;
    }
    if (a != -1) {
        person1.printMenu();
        int kod = 0;
        std::cout << "\nВведите код напитка   \n";
        std::cin >> kod;
        for (; person1.choice(kod) == 0;) {
            std::cout << "\nНа вашем счете недостаточно средств или неправильно введен код.\n";
            std::cout << "\nпожалуйста положите деньги на счет, или нажмите 0, чтобы перейти к выбору другого продукта\n";
            std::cin >> a;
            while (a != 0) {
                person1.coin(a);
                std::cin >> a;
                std::cout << "\n";
            }
            std::cout << "\nВведите код напитка   \n";
            std::cin >> kod;
        }
    }
    else {
        person1.cancel();
    }
}
