// Copyright 2020 test
#include<iostream>
#include "Automata.h"



int main() {
    Automata test;
    test.on();  // � ������ ������ ������. ������� �������
    std::cout << test.getMenu();  // ����� ��� � ����
    test.coin(10);  // ������� 10
    std::cout << test.getState() << "\n";
    test.choice(5);  // ������ ������� ������� 0_0
    std::cout << test.getState() << "\n";
    std::cout << test.getCoin() << "\n";  // � ������� � ������� ��� � �������? 
    test.coin(20);  // ��� 20 �������� ����� :( 
    test.choice(5);  // ���� ������� �������
    test.finish();  // �����! ��������!
    test.off();  // ��, �� ����� ��� ����� ������� -_-
    std::cout << test.getState() << "\n";
    return 0;
}
