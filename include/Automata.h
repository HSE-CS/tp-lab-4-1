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
 int cash; //��� �������� ������� �����;
 std::vector<std::string> menu;//������ ����� �������� ��������(����� ������������ �� �����);
 std::vector<int> price; //������ ��� ��������(������������� ������� menu);
 states state; //������� ��������� ��������
 int user; //����� ����������
 int change; //�����
public:
 Automata(); //�����������
 Automata(const std::string); //����������� � ���� �� �����
 void on(); //��������� ��������;
 void off(); //���������� ��������;
 void coin(int); //��������� ����� �� ���� �������������;
 std::string getMenu(); //���������� ���� � ��������� � ������ ��� ������������;
 states getState(); //���������� �������� ��������� ��� ������������;
 void choice(const std::string drink); //����� ������� �������������;
 bool check();  //�������� ������� ����������� �����;
 void cancel(); //������ ������ ������������ �������������;
 void cook(); //�������� �������� ������������� �������;
 void finish(); //���������� ������������ ������������.
};

#endif // !INCLUDE_AUTOMATA_H
