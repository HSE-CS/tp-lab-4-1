#include "Automata.h"

void Automata::on() 
{
	if (this->state == OFF) 
	{
		this->state = WAIT;
	}
}

void Automata::off() 
{
	this->state = OFF;
}

void Automata::coin(int donation, bool next) 
{
	if ((this->state == WAIT) && (next==true))
	{
		this->state = ACCEPT;
		this->donation = this->donation + donation;
	}
	else
	{
		this->state = WAIT;
		this->donation = this->donation + donation;
	}
}

void Automata::cancel() 
{
	if ((this->state == ACCEPT) || (this->state == CHECK))
	{
		this->state = WAIT;
		this->donation = 0;
	}
}

void Automata::getMenu(int num)
{
	int index = 0;
	for (int i = 0; i < num; i++) 
	{
		index = i + 1;
		cout << index << ")" << this->menu[i] << ", price: " << this->prices[i] << endl;
	}
}

string Automata::getState()
{
	string st = " Cash= " + to_string(this->cash) + " Donation= " + to_string(this->donation) + " State= " + to_string(this->state);
	return st;
}

void Automata::choice(int num) 
{
	if (this->state == ACCEPT) 
	{
		this->state = CHECK;
		check(num);
	}
}

void Automata::check(int num) 
{
	if (this->donation >= this->prices[num - 1])
	{
		this->state = COOK;
		this->cash = this->cash + this->prices[num - 1];
		this->donation = 0;
		cook();
	}
	else 
	{
		cancel();
	}
}

void Automata::cook() 
{
	finish();
}

void Automata::finish() 
{
	this->state = WAIT;
}
