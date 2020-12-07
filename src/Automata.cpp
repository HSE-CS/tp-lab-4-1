#include "Automata.h"

stringstream Automata::on() {
	if (state == STATES::OFF) {
		state = STATES::WAIT;
		read_menu("menu.txt");
		printMenu(getMenu());
	}
	return getState();
}

stringstream Automata::off() {
	if (state == STATES::WAIT) {
		state = STATES::OFF;
	}
	return getState();
}

stringstream Automata::getState() {
	stringstream stream;
	stream << "State: ";
	switch (state)
	{
	case STATES::OFF:
		stream << "OFF";
		break;
	case STATES::WAIT:
		stream << "WAIT";
		break;
	case STATES::ACCEPT:
		stream << "ACCEPT";
		break;
	case STATES::CHECK:
		stream << "CHECK";
		break;
	case STATES::COOK:
		stream << "COOK";
		break;
	}
	stream << endl;
	return stream;
}

void Automata::read_menu(const string dir) {
	ifstream file(dir);
	string el_menu;
	unsigned int el_prises;
	while (file) {
		file >> el_menu;
		file.ignore(1);
		file >> el_prises;
		file.ignore(1);
		menu.push_back(el_menu);
		prices.push_back(el_prises);
	}
}

pair<vector<string>, vector<unsigned int>> Automata::getMenu() {
	return { menu, prices };
}

void printMenu(pair<vector<string>, vector<unsigned int>> menu) {
	cout << "+---------------------+" << endl;
	for (size_t i{ 0 }; i < menu.first.size(); ++i) {
		cout << '|' << i + 1 << ". " << setiosflags(ios::left) << setw(12) << setfill(' ') << menu.first[i] << " - "
			<< setw(3) << setfill(' ') << menu.second[i] << '|' << endl;
	}
	cout << "+---------------------+" << endl;
}

stringstream Automata::choice(unsigned int ch_drink) {
	stringstream stream;
	if (state == STATES::ACCEPT || state == STATES::CHECK) {
		state = STATES::CHECK;
		stringstream stream;
		stream << getState().str();
		drink = ch_drink;
		drink--;
	}
	return stream;
}

stringstream Automata::cook() {
	stringstream stream;
	if (state == STATES::CHECK) {
		if (check()) {
			state = STATES::COOK;
			stream << getState().str() << '\n' << finish().str();
		}
		else {
			stream << getState().str() << '\n' << "Money is not enought" << endl;
		}
	}
	return stream;
}

stringstream Automata::coin(unsigned int get_money){
	stringstream stream;
	if (state == STATES::WAIT || state == STATES::ACCEPT || state == STATES::CHECK) {
		state = STATES::ACCEPT;
		stream << getState().str();
		unsigned int money;
		money = get_money;
		cash += money;
	}
	return stream;
}

bool Automata::check() {
	if (cash >= prices[drink]) {
		return true;
	}
	else {
		return false;
	}
}

 stringstream Automata::cancel() {
	 stringstream stream;
	 if (state == STATES::ACCEPT) {
		 state = STATES::WAIT;
		 stream << "Your change: " << cash << endl;
		 cash = 0;
	 }
	 return stream;
}

 stringstream Automata::finish() {
	 state = STATES::WAIT;
	 stringstream stream;
	 stream  << "Succesful" << '\n' <<  "Your change: " << cash - prices[drink] << '\n' << getState().str();
	 cash = 0;
	 return stream;
 }

 string Automata::sgetState() {
	 string stream;
	 stream = "State: ";
	 switch (state)
	 {
	 case STATES::OFF:
		 stream += "OFF";
		 break;
	 case STATES::WAIT:
		 stream += "WAIT";
		 break;
	 case STATES::ACCEPT:
		 stream += "ACCEPT";
		 break;
	 case STATES::CHECK:
		 stream += "CHECK";
		 break;
	 case STATES::COOK:
		 stream += "COOK";
		 break;
	 }
	 return stream;
 }
