// Copyright 2020 <Jiiijyyy>
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_
#include <cmath>
#include <iostream>
#include <string>



class Automata {
 private:
    /* cash - для хранения текущей суммы;
     menu - массив строк названий напитков(может подгружаться из файла);
     prices - массив цен напитков(соответствует массиву menu);
     state - текущее состояние автомата;*/
 public:
     Automata();
     //конструктор
     //    on() - включение автомата;
     //off() - выключение автомата;
     //coin() - занесение денег на счёт пользователем;
     //getMenu() - считывание меню с напитками и ценами для пользователя;
     //getState() - считывание текущего состояния для пользователя;
     //choice() - выбор напитка пользователем;
     //check() - проверка наличия необходимой суммы;
     //cancel() - отмена сеанса обслуживания пользователем;
     //cook() - имитация процесса приготовления напитка;
     //finish() - завершение обслуживания пользователя.
     //void on();
     //void off();
     //bool coin(int chash);
     //std::string* getMenu();
     //STATES getState();
     //void choice(int number);
     //bool check();
     //void cancel();
     //void cook();
     //void finish();
};
#endif  // INCLUDE_AUTOMATA_H_
