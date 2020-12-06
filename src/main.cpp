// Copyright 2020 Elizaveta Drobot
#include "Automata.h"


int main() {
    setlocale(LC_ALL, "Russian");
    Automata person1;
    person1.on();
    int a = 0;
    std::cout << "������� ����� � �������������, ���������� �������� ������ �� ����		\n";
    std::cin >> a;
    person1.coin(a);
    std::cout << "����������� ������� �������� �������� ��� ������� 0, ����� ������� � ������ �������, ��� ������� -1, ���� ������ ������� ������\n";
    std::cin >> a;
    while (a != 0) {
        person1.coin(a);
        std::cin >> a;
    }
    if (a != -1) {
        person1.printMenu();
        int kod = 0;
        std::cout << "\n������� ��� �������   \n";
        std::cin >> kod;
        for (; person1.choice(kod) == 0;) {
            std::cout << "\n�� ����� ����� ������������ ������� ��� ����������� ������ ���.\n";
            std::cout << "\n���������� �������� ������ �� ����, ��� ������� 0, ����� ������� � ������ ������� ��������\n";
            std::cin >> a;
            while (a != 0) {
                person1.coin(a);
                std::cin >> a;
                std::cout << "\n";
            }
            std::cout << "\n������� ��� �������   \n";
            std::cin >> kod;
        }
    }
    else {
        person1.cancel();
    }
}
