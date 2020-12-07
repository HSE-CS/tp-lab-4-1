#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

class Automata {
public:
	enum STATES {
		OFF,
		WAIT,
		ACCEPT,
		CHECK,
		COOK,
	};
private:
	unsigned int cash{ 0 };
	unsigned int drink{ 0 };
	vector<string>menu;
	vector<unsigned int>prices;
	STATES state = STATES::OFF;
	// ��������� ������
	bool check(); //�������� ������� ����������� �����
	stringstream finish(); //���������� ������������ ������������
	pair<vector<string>, vector<unsigned int>> getMenu(); //���������� ���� � ��������� � ������ ��� ������������
public:
	//��� ������������
	stringstream on(); //��������� ��������
	stringstream off(); //���������� ��������
	stringstream getState(); //���������� �������� ��������� ��� ������������
	string sgetState(); //���������� �������� ��������� ��� �����
	void read_menu(const string dir);
	//��� ������������
	stringstream coin(unsigned int get_money); //��������� ����� �� ���� �������������
	stringstream choice(unsigned int ch_drink); //����� ������� �������������
	stringstream cancel(); //������ ������ ������������ �������������
	stringstream cook(); //�������� �������� ������������� �������
};

//�������������� �������� � ��������
void printMenu(pair<vector<string>, vector<unsigned int>> menu);
