// Copyright 2020 JGMax

#ifndef LAB_4_MENU_H
#define LAB_4_MENU_H

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

    Menu(int size, char** items, double* prices) {
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

#endif // LAB_4_MENU_H
