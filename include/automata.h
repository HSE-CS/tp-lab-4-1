// Copyright 2020 Elizaveta Drobot
#ifndef INCLUDE_Automata_H_
#define INCLUDE_Automata_H_

#define _CRT_SECURE_NO_WARNINGS

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <string>
#include <map>
#include <vector>

enum STATES {
    on_automat = 0,
    off_automat = 1,
    waitmoney = 2,
    luckmoney = 3,
    cooking = 4

};

class Automata
{
public:
    automat();//конструктор
    void on();// -включение автомата;
    void off();// -выключение автомата;
    void coin(int);// -занесение денег на счёт пользователем;
    void getMenu();// -считывание меню с напитками и ценами для пользователя;
    void printMenu();//вывод меню
    void getState(int);// -считывание текущего состояния для пользователя;
    int printState();//вывод состояния
    bool choice(int);// -выбор напитка пользователем;
    bool check(int);// -проверка наличия необходимой суммы;
    void cancel();// -отмена сеанса обслуживания пользователем;
    void cook();// -имитация процесса приготовления напитка;
    void finish();// -завершение обслуживания пользователя.


private:
    int cash;
    int total_cash;
    std::vector <std::string> array_menu {"Americano", "Capuchino", "Milk", "Black tea", "Water"};
    std::vector <int> array_prices {35, 40, 30, 25, 10};
    std::vector <int> array_kod {10, 11, 12, 13, 14};
    int state;
};
#endif  // INCLUDE_Automata_H_
