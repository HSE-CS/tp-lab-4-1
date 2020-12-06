#include "../include/automataNoDialog.h"
#include <fstream>
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

#define uint unsigned int

#ifdef _WIN32 || _WIN64

#include <windows.h>

void clearconsole()
{
	char fill = ' ';
	COORD tl = { 0,0 };
	CONSOLE_SCREEN_BUFFER_INFO s;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &s);
	DWORD written, cells = s.dwSize.X * s.dwSize.Y;
	FillConsoleOutputCharacter(console, fill, cells, tl, &written);
	FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
	SetConsoleCursorPosition(console, tl);
}

#else

#include <unistd.h>

void clearconsole()
{
	write(1, "\E[H\E[2J", 7);
}

#endif

Automata::Automata(std::string datafile)
{
	this->cash = 0;
	this->state = STATES::OFF;
	ifstream fdata;
	fdata.open(datafile);
	string line;
	while (getline(fdata, line))
	{
		uint sepIndex = line.find(":");
		string item = line.substr(0, sepIndex);
		uint price = stoi(line.substr(sepIndex + 1, line.size() - item.size() - 1));
		this->menu.push_back(item);
		this->prices.push_back(price);
	}
	fdata.close();
}

void Automata::on()
{
	this->state = STATES::WAIT;
	this->getState();
}

void Automata::off()
{
	this->state = STATES::OFF;
}

int Automata::coin(int money)
{
	this->state = STATES::ACCEPT;
	if (money == 0)
	{
		this->cancel();
		return -1;
	}
	else if (money == -1)
	{
		return 1;
	}
	this->cash += money;
	return 0;
}

void Automata::getMenu()
{
	//clearconsole();
	cout << "Balance: " << this->cash << endl;
	for (uint i = 0; i < this->menu.size(); ++i)
		cout << "[" << i << "] " << this->menu[i] << ", price: " << this->prices[i] << endl;
}

STATES Automata::getState()
{
	//clearconsole();
	vector<string> stateNames = { "OFF", "WAIT", "ACCEPT", "CHECK", "COOK" };
	//cout << "[" << stateNames[this->state] << "]" << endl;
	//switch (this->state)
	//{
	//case STATES::OFF:
	//	cout << "[OFF]" << endl;
	//	//cout << "Press 'Enter' to turn on the automata" << endl;
	//	//if (cin.get() == '\n')
	//	//	this->on();
	//case STATES::WAIT:
	//case STATES::ACCEPT:
	//case STATES::CHECK:
	//case STATES::COOK:

	//}
	return this->state;
}

int Automata::choice(unsigned int choice)
{
	return this->check(choice) ? 0 : -1;
}

bool Automata::check(unsigned int choice)
{
	this->state = STATES::CHECK;
	if (this->prices[choice] <= this->cash)
	{
		cout << "[SUCCESS]" << endl;
		return true;
	}
	else
	{
		cout << "[ERROR]" << endl << "Not enough money!" << endl;
		//this->cancel();
		return false;
	}
}

void Automata::cancel()
{
	this->cash = 0;
	this->state = STATES::WAIT;
}

void Automata::cook()
{
	this->state = STATES::COOK;
	this->finish();
}

void Automata::finish()
{
	this->state = STATES::WAIT;
	this->cash = 0;
}
