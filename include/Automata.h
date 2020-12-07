#ifndef INCLUDE_AUTOMATA_H
#define INCLUDE_AUTOMATA_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

enum states {
	OFF,
	ON,
	WAIT,
	COOK,
	ACCEPT,
	CHECK
};

class Automata {
private:
 int cash; //для хранения текущей суммы;
 std::vector<std::string> menu;//массив строк названий напитков(может подгружаться из файла);
 std::vector<int> price; //массив цен напитков(соответствует массиву menu);
 states state; //текущее состояние автомата
 int user; //заказ покупателя
 int change; //сдача
public:
 Automata(); //конструктор
 Automata(const std::string); //конструктор с меню из файла
 void on(); //включение автомата;
 void off(); //выключение автомата;
 void coin(int); //занесение денег на счёт пользователем;
 std::string getMenu(); //считывание меню с напитками и ценами для пользователя;
 states getState(); //считывание текущего состояния для пользователя;
 void choice(const std::string drink); //выбор напитка пользователем;
 bool check();  //проверка наличия необходимой суммы;
 void cancel(); //отмена сеанса обслуживания пользователем;
 void cook(); //имитация процесса приготовления напитка;
 void finish(); //завершение обслуживания пользователя.
};

#endif // !INCLUDE_AUTOMATA_H
