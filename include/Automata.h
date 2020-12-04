#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <vector>
#include <string>

enum STATES {OFF, WAIT, ACCEPT, CHECK, COOK};

class Automata
{
private:
	int cash;
	std::vector <std::string> menu;
	std::vector <int> prices;
	int drink_index;
	STATES state; 

public:
	Automata();
	void on();// -��������� ��������;
	void off(); //-���������� ��������;
	void coin(int money); //-��������� ����� �� ���� �������������;
	std::string getMenu(); //-���������� ���� � ��������� � ������ ��� ������������;
	STATES getState(); // -���������� �������� ��������� ��� ������������;
	void choice(std::string); //-����� ������� �������������;
	bool check(); // -�������� ������� ����������� �����;
	int cancel(); //-������ ������ ������������ �������������;
	void cook(); //-�������� �������� ������������� �������;
	void finish(); //-���������� ������������ ������������.
};
#endif
