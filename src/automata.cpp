// Copyright 2020 Elizaveta Drobot
#include "Automata.h"
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <chrono>
#include <thread>

std::ifstream fin_menu("menu.txt");
std::ifstream fin_prices("prices.txt");
std::ifstream fin_kod("kod.txt");

Automata::automat() {
    getMenu();
    getState(1);
    this->cash = 0;
}
void Automata::on() {  // -включение автомата;
    if (this->state == 1) {
        getState(0);
    }
    printState();
}
void Automata::off() {  // -выключение автомата;
    if (this->state == 0) {
        getState(1);
    }
    printState();
}
void Automata::coin(int a) {  // -занесение денег на счёт пользователем;
    getState(2);
    printState();
    if ((a == 1) || (a == 2) || (a == 5) || (a == 10) || (a == 50) || (a == 100) || (a == 200)) {
        this->cash += a;
    }
    else {
        std::cout << "\nНеправильный ввод денежных средств. Повторите попытку.\n";
    }
    std::cout << "\nСумма на счету: " << cash << "\n";
}
void Automata::getMenu() {
    for (int i = 0; !fin_menu.eof(); i++) {
        array_menu.resize(array_menu.size() + 1);
        array_prices.resize(array_prices.size() + 1);
        array_kod.resize(array_kod.size() + 1);
        fin_menu >> array_menu[i];
        fin_prices >> array_prices[i];
        fin_kod >> array_kod[i];
    }
    array_menu.resize(array_menu.size() - 5);
    array_prices.resize(array_prices.size() - 5);
    array_kod.resize(array_kod.size() - 5);
}
void Automata::printMenu() {
    for (int i = 0; i < this->array_menu.size(); i++) {
        std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        std::cout << "\n " << array_menu[i] << "= " << array_prices[i] << "          kod = " << array_kod[i] <<"  ";
        std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    }
}
void Automata::getState(int a) {
    this->state = a;
}
int Automata::printState() {  // -считывание текущего состояния для пользователя;
    switch (this->state) {
    case on_automat:
        std::cout << "\nАвтомат включен";
        return on_automat;
        break;
    case off_automat:
        std::cout << "\nАвтомат выключен";
        return off_automat;
        break;
    case waitmoney:
        std::cout << "\nПожалуйста, положите деньги на счет";
        return waitmoney;
        break;
    case luckmoney:
        std::cout << "\nНе хватает денег.";
        return luckmoney;
        break;
    case cooking:
        std::cout << "\nПожалуйста, подождите. Идет приготовление напитка.";
        return cooking;
        break;
    }
}
bool Automata::choice(int kod) {  // -выбор напитка пользователем;
    if (kod > array_kod[array_kod.size()-1]) {
        std::cout << "\nНеправильный код напитка. Попробуйте еще раз.";
        return 0;
    }
    else {
        for (int i = 0; i <= array_kod.size(); i++) {
            if (kod == array_kod[i]) {

                if (check(array_prices[i]) == 0) {
                    return 0;
                }
                return 1;
                break;
            }
        }
    }
}
bool Automata::check(int number) {  // -проверка наличия необходимой суммы;
    if (cash >= number) {
        cash = cash - number;
        total_cash += number;
        cook();
        return 1;
        
    }
    else
    {
        getState(3);
        printState();
        return 0;
    }
}
void Automata::cancel() {  // -отмена сеанса обслуживания пользователем;
    this->cash = 0;
    off();
}
void Automata::cook() {  // -имитация процесса приготовления напитка;
    getState(4);
    printState();
    std::this_thread::sleep_for(std::chrono::seconds(3));
    finish();
}
void Automata::finish() {  // -завершение обслуживания пользователя.
    std::cout << "\nСпасибо за заказ, приходите еще.\n";
    this->cash = 0;
    off();
}
