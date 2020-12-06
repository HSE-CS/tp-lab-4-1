#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

enum STATES { 
	OFF, WAIT, ACCEPT, CHECK, COOK, FINISH
};

enum DRINKS {
	LATTE = 1, CAPPU, ESPRS, AMERI, HOTCH
};

class Automata {
private:
	int cash;
	int keptSum;
	static vector<string> menu;
	static vector<int> prices;
	int productChoice;
	enum STATES state;
	ostream* aout;
public:
	Automata(); //�����������
	Automata(ostream* definedStream); //�����������
	bool on(); // -��������� ��������;
	bool off(); //-���������� ��������;
	bool coin(int coins); //-��������� ����� �� ���� �������������;
	vector<string> getMenu(); // -���������� ���� � ��������� � ������ ��� ������������;
	enum STATES getState(); // -���������� �������� ��������� ��� ������������;
	bool choice(int product); // -����� ������� �������������;
	bool check(); // -�������� ������� ����������� �����;
	int cancel(); // -������ ������ ������������ �������������;
	bool cook(); // -�������� �������� ������������� �������;
	int finish(); //-���������� ������������ ������������.
	int getKeptSum();
	void reset();
	void printBeautifulMenu();
};

#endif