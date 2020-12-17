//
// Created by stoja on 15.12.2020.
//
#include "Automata.h"
//#include "windows.h"
#include <iostream>
Automata::Automata() {
    cash = 0.0;
    state = OFF;
}

void Automata::on(){
    if (state == OFF) {
        state = WAIT;
        std::cout << "Automata on\n";
    }
}

void Automata::off() {
    if (state == WAIT) {
        state = OFF;
        std::cout << "Automata off\n";
    }
}

void Automata::coin(double coin) {
    if (state == WAIT || state == ACCEPT) {
        cash += coin;
        state = ACCEPT;
        std::cout<<"Add "<<coin<<"\nYour cash: "<< cash << "\n";

    }
}

std::string Automata::getMenu() {
    std::string info = "";
    for(std::string position : menu) info += position + " ";
    return info;
}

STATES Automata::getState() {
    return state;
}

void Automata::choice(int pos) {
    if (state == ACCEPT) {
        state = CHECK;
        check(pos - 1);
    }
}

void Automata::check(int pos){
    if (prices[pos] > cash){
        std::cout<<"You have not money)))\n";
        state = ACCEPT;
        return;
        }
    else{
        cook(pos);
    }
}

void Automata::cook(int pos){
    state = COOK;
    std::cout<<"Wait";
    for(int i = 0; i < 10; i++) {
        //Sleep(500);
        std::cout<<".";
    }
    std::cout<<"Your "<<menu[pos];
    finish();
}

void Automata::finish() {
    state = WAIT;
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK || state == COOK) state = WAIT;
}

double Automata::getCash() {
    return cash;
}