#ifndef LAB_4_AUTOMATA_H
#define LAB_4_AUTOMATA_H

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

class Menu {
private:
    std::vector<std::string> items;
    std::vector<double> prices;
    void changePrice(int, double);
    void checkValidMenu() const;
public:
    Menu() = default;
    Menu(std::vector <std::string> items, std::vector<double> prices) {
        for (int i = 0; i < items.size(), i < prices.size(); i++) {
            addItem(items[i], prices[i]);
        }
    }

    Menu(int size, std::string* items, double* prices) {
        for (int i = 0; i < size; i++) {
            addItem(items[i], prices[i]);
        }
    }

    Menu(int size, const char** items, double* prices) {
        for (int i = 0; i < size; i++) {
            addItem(items[i], prices[i]);
        }
    }

    Menu(Menu &menu) {
        menu.checkValidMenu();
        for (int i = 0; i < menu.items.size(), i < menu.prices.size(); i++) {
            addItem(menu.items[i], menu.prices[i]);
        }
    }

    void addItem(std::string item, double price);

    void removeItem(std::string item);
    void removeItem(int index);

    double getPrice(std::string item) const;
    double getPrice(int index) const;

    void changeItem(std::string item, double price);
    void changeItem(int index, double price);

    bool isValidItem(std::string item) const;

    Menu operator+(Menu& menu);
    Menu& operator+=(Menu& menu);
    Menu& operator=(const Menu& menu);
    bool operator==(const Menu& menu);
    bool operator!=(const Menu& menu);

    int getItemIndex(std::string item) const;

    std::vector<std::string> getItems() const;
    int getSize() const;
    void clear();
};

enum States {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

class Automata {
 private:
    std::string adminPassword = "1234";
    std::string rememberedItem;
    double cash;
    double inputCash = 0;
    Menu menu;
    Menu incorrectMenu;
    States state;
    std::ostream* outputStream;
    bool check(std::string);
    void cook(std::string);
    double getChange(std::string);
    void finish();
 public:
    Automata() {
        outputStream = &(std::cout);
        state = OFF;
        cash = 0;
    }
    Automata(std::ostream* oStream) {
        outputStream = oStream;
        state = OFF;
        cash = 0;
    }

    Automata(std::ostream* oStream, std::string adminPassword, const Menu& menu) {
        if (adminPassword == this->adminPassword)
            this->menu = menu;
        outputStream = oStream;
        state = OFF;
        cash = 0;
    }

    Automata(std::ostream* oStream, std::string adminPassword, const double cash) {
        if (adminPassword == this->adminPassword)
            this->cash = cash;
        else
            this->cash = 0;
        outputStream = oStream;
        state = OFF;
    }

    Automata(std::ostream* oStream, std::string adminPassword, const Menu& menu,  const double cash) {
        if (adminPassword == this->adminPassword) {
            this->cash = cash;
            this->menu = menu;
        } else {
            this->cash = 0;
        }
        outputStream = oStream;
        state = OFF;
    }

    bool changeAdminPassword(std::string adminPassword, std::string newAdminPassword);
    Menu getMenu(bool show = true);
    Menu& getMenu(std::string adminPassword);

    void on();
    void off();
    void coin(double cash);
    double getChange();
    void cook();
    void choice(std::string item);
    States getState();
    double cancel();

    double getCash(std::string adminPassword);
};

#endif
