// Copyright 2020 Elizaveta Drobot
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

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
    Automata();//�����������
    void on();// -��������� ��������;
    void off();// -���������� ��������;
    void coin(int);// -��������� ����� �� ���� �������������;
    void getMenu();// -���������� ���� � ��������� � ������ ��� ������������;
    void printMenu();//����� ����
    void getState(int);// -���������� �������� ��������� ��� ������������;
    int printState();//����� ���������
    bool choice(int);// -����� ������� �������������;
    bool check(int);// -�������� ������� ����������� �����;
    void cancel();// -������ ������ ������������ �������������;
    void cook();// -�������� �������� ������������� �������;
    void finish();// -���������� ������������ ������������.


private:
    int cash;
    int total_cash;
    std::vector <std::string> array_menu {"Americano", "Capuchino", "Milk", "Black tea", "Water"};
    std::vector <int> array_prices {35, 40, 30, 25, 10};
    std::vector <int> array_kod {10, 11, 12, 13, 14};
    int state;
};
#endif  // INCLUDE_AUTOMAT_H_
