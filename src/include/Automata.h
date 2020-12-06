#include <string>
#include <vector>


enum STATES
{
	OFF,
	WAIT,
	ACCEPT,
	CHECK,
	READY,
	COOK
};

class Automata
{
public:
	Automata();
	void on();
	void off();
	void coin(const unsigned int amount);
	int getBalance() const;
	std::vector<std::pair<std::string, int>> getMenu() const;
	STATES getState();
	void choice(const size_t item);
	size_t getCurrentChoice() const;
	bool check();
	void cancel();
	void cook();
	void finish();

private:
	double cash;
	std::vector<std::string> menu;
	std::vector<int> prices;
	STATES state;
	size_t currentChoice;
};
