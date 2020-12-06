// Copyright 2020 JGMax

#include "Menu.h"

void Menu::addItem(std::string item, double price) {
    checkValidMenu();
    int i = getItemIndex(item);
    if (i == items.size()) {
        items.emplace_back(item);
        prices.push_back(price);
    } else {
        changePrice(i, price);
    }
}

void Menu::changeItem(std::string item, double price) {
    checkValidMenu();
    int i = getItemIndex(item);
    if (i == items.size()){
        throw "unknown item";
    } else {
        changeItem(i, price);
    }
}

void Menu::changeItem(int index, double price) {
    checkValidMenu();
    if (index >= 0 && index < items.size()) {
        changePrice(index, price);
    } else {
        throw "invalid index";
    }
}

void Menu::removeItem(std::string item) {
    checkValidMenu();
    int i = getItemIndex(item);
    if (i == items.size()) {
        throw "unknown item";
    } else {
        removeItem(i);
    }
}

void Menu::removeItem(int index) {
    checkValidMenu();
    if (index >= 0 && index < items.size()) {
        items.erase(items.begin() + index);
        prices.erase(prices.begin() + index);
    } else {
        throw "unknown index";
    }
}

double Menu::getPrice(std::string item) const {
    checkValidMenu();
    int i = getItemIndex(item);
    if (i == items.size()) {
        throw "unknown item";
    } else {
        return getPrice(i);
    }
}

double Menu::getPrice(int index) const {
    checkValidMenu();
    if (index >= 0 && index < items.size()) {
        return prices[index];
    } else {
        throw "unknown index";
    }
}

bool Menu::isValidItem(std::string item) const {
    return getItemIndex(item) != items.size();
}

int Menu::getItemIndex(std::string item) const {
    int i = 0;
    for (; i < items.size(); i++)
        if (items[i] == item)
            break;
    return i;
}

int Menu::getSize() const {
    checkValidMenu();
    return items.size();
}

void Menu::checkValidMenu() const {
    if (items.size() != prices.size())
        throw "menu is invalid";
}

void Menu::clear() {
    prices.clear();
    items.clear();
}

std::vector<std::string> Menu::getItems() const {
    return items;
}

void Menu::changePrice(int i, double price) {
    if (price >= 0)
        prices[i] = price;
    else
        throw "invalid price";
}

Menu Menu::operator+(Menu &menu) {
    Menu menu1(menu);
    for (int i = 0; i < items.size(); i++) {
        menu1.addItem(items[i], prices[i]);
    }
    return menu1;
}

Menu &Menu::operator=(const Menu &menu) {
    items = menu.items;
    prices = menu.prices;
    return *this;
}

bool Menu::operator==(const Menu &menu) {
    return (items == menu.items) && (prices == menu.prices);
}

bool Menu::operator!=(const Menu &menu) {
    return !((items == menu.items) && (prices == menu.prices));
}

Menu &Menu::operator+=(Menu &menu) {
    *this = *this + menu;
    return *this;
}
