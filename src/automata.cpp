#include "../include/automata.h"
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
		uint price = stoi(line.substr(sepIndex+1, line.size() - item.size() - 1));
		this->menu.push_back(item);
		this->prices.push_back(price);
	}
	fdata.close();
}

void Automata::on()
{
	cout << "Turning on the automata" << endl;
	this_thread::sleep_for(std::chrono::milliseconds(500));
	clearconsole();
	cout << "Turning on the automata." << endl;
	this_thread::sleep_for(std::chrono::milliseconds(500));
	clearconsole();
	cout << "Turning on the automata.." << endl;
	this_thread::sleep_for(std::chrono::milliseconds(500));
	clearconsole();
	this->state = STATES::WAIT;
	this->getState();
	int decision;
	while (1)
	{
		this_thread::sleep_for(std::chrono::milliseconds(500));
		clearconsole();
		this->getState();
		cout << "Enter [0] if you want to turn off the automata" << endl << "Enter [1] if you want to insert money" << endl;
		cin >> decision;
		if (decision == 0)
		{
			this->off();
			return;
		}
		bool nextStep = false;
		while (1)
		{
			clearconsole();
			this->getState();
			this->getMenu();
			int res = this->coin();
			if (res == -1)
				break;
			if (res == 1)
			{
				nextStep = true;
				break;
			}
		}
		clearconsole();
		this->getState();
		if (!nextStep)
			continue;
		this->getMenu();
		if (this->choice() == -1)
		{
			this->cancel();
			continue;
		}
		this->getState();
		this->cook();
		this->getState();

	}
}

void Automata::off()
{
	cout << "Turning off the automata" << endl;
	this_thread::sleep_for(std::chrono::milliseconds(500));
	clearconsole();
	cout << "Turning off the automata." << endl;
	this_thread::sleep_for(std::chrono::milliseconds(500));
	clearconsole();
	cout << "Turning off the automata.." << endl;
	this_thread::sleep_for(std::chrono::milliseconds(500));
	clearconsole();
	this->state = STATES::OFF;
	this->getState();
}

int Automata::coin()
{
	this->state = STATES::ACCEPT;
	cout << "How many money do you want to insert?[integer number]" << endl;
	cout << "Enter 0 if you want to cancel, -1 if you want to make choice" << endl;
	int money;
	cin >> money;
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
	cout << "[" << stateNames[this->state] << "]" << endl;
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

int Automata::choice()
{
	cout << "Enter the code of item (on the left side of item label inside the squared brackets)" << endl;
	uint choice;
	cin >> choice;
	return this->check(choice) ? 0 : -1;
}

bool Automata::check(unsigned int choice)
{
	clearconsole();
	this->state = STATES::CHECK;
	if (this->prices[choice] <= this->cash)
	{
		cout << "[SUCCESS]" << endl;
		//this->cook();
		return true;
	}
	else
	{
		cout << "[ERROR]" << endl << "Not enough money!" << endl;
		this_thread::sleep_for(std::chrono::milliseconds(1000));
		//this->cancel();
		return false;
	}
}

void Automata::cancel()
{
	clearconsole();
	cout << "Cancel..." << endl;
	this_thread::sleep_for(std::chrono::milliseconds(2000));
	this->cash = 0;
	this->state = STATES::WAIT;
}

void Automata::cook()
{
	this->state = STATES::COOK;
	this_thread::sleep_for(std::chrono::milliseconds(700));
	clearconsole();
	cout << "cooking." << endl;
	this_thread::sleep_for(std::chrono::milliseconds(700));
	clearconsole();
	cout << "cooking.." << endl;
	this_thread::sleep_for(std::chrono::milliseconds(700));
	clearconsole();
	cout << "cooking..." << endl;
	this_thread::sleep_for(std::chrono::milliseconds(700));
	this->finish();
}

void Automata::finish()
{
	cout << "Your coffee is ready, thank you for using our automata" << endl;
	this->state = STATES::WAIT;
	this->cash = 0;
	this_thread::sleep_for(std::chrono::milliseconds(3000));
}

