#include "Automata.h"
#include <iostream>
#include <string>

std::string name[] = { "Coffee with milk",//50
                       "Hot milk",//40
                       "Green tea",// 30
                       "Latte",//60
                       "Chocolate",//70
                       "Chocolate with milk",//80
                       "Black tea"//,90
};

int cost[] = { 50, 40, 30, 60, 70, 80, 90 };

//конструктор
Automata::Automata()
{
    // - для хранения текущей суммы;
    cash = 0;
    // - массив строк названий напитков (может подгружаться из файла);
    menu[] = name[];
    // - массив цен напитков (соответствует массиву menu);
    prices[] = cost[];
    // - текущее состояние автомата;
    state = off;
    // needed sum
    sum = 0;
    //choice
    client = 0;
}

// - включение автомата;
void Automata::on()
{
    state on;
    state wait;
}
// - выключение автомата;
void Automata::off()
{
    state off;
}
// - занесение денег на счёт пользователем;
void Automata::coin(int tmp)
{
    if (getState() == wait)
    {
        cash = tmp;

    }

}
// - считывание меню с напитками и ценами для пользователя;
std::string Automata::getMenu()
{

}
// - считывание текущего состояния для пользователя;
STATES Automata::getState()
{
    return state;
}
// - выбор напитка пользователем;
void Automata::choice(std::string client)
{

}
// - проверка наличия необходимой суммы;
bool Automata::check()
{

}
// - отмена сеанса обслуживания пользователем;
void Automata::cancel()
{

}
// - имитация процесса приготовления напитка;
void Automata::cook()
{

}
// - завершение обслуживания пользователя.
void Automata::finish()
{
    cancel();
}


