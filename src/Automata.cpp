#include "Automata.h"

bool Automata::changeAdminPassword(std::string oldAdminPassword, std::string newAdminPassword) {
    if (state != WAIT) {
        *outputStream << "Incorrect state\n\r";
        return false;
    }
    if (oldAdminPassword == adminPassword) {
        adminPassword = newAdminPassword;
        *outputStream << "Password changed\n\r";
        return true;
    } else {
        *outputStream << "Incorrect password\n\r";
        return false;
    }
}

Menu Automata::getMenu(bool show) {
    if (state != OFF) {
        if (show) {
            *outputStream << "Menu:\n\r";
            for (int i = 0; i < menu.getSize(); i++) {
                *outputStream << "<\t" << i << "\t>\t" << menu.getItems()[i] << "\t-\t" << menu.getPrice(i) << "\n\r";
            }
        }
        return menu;
    } else {
        *outputStream << "Incorrect state\n\r";
        return incorrectMenu;
    }
}

Menu &Automata::getMenu(std::string adminPassword) {
    if (state != OFF) {
        if (this->adminPassword == adminPassword)
            return menu;
        *outputStream << "Incorrect password\n\r";
        return incorrectMenu;
    } else {
        *outputStream << "Incorrect state\n\r";
        return incorrectMenu;
    }
}

void Automata::on() {
    if (state == OFF) {
        state = WAIT;
        *outputStream << "Automata is on\n\r";
    } else {
        *outputStream << "Incorrect state\n\r";
    }
}

void Automata::off() {
    if (state == WAIT) {
        state = OFF;
        *outputStream << "Automata is off\n\r";
    } else {
        *outputStream << "Incorrect state\n\r";
    }
}

void Automata::coin(double cash) {
    if (state == WAIT || state == ACCEPT) {
        state = ACCEPT;
        inputCash += cash;
        *outputStream << cash << " is taken\n\r";
        *outputStream << "Cash:\t" << inputCash << "\n\r";
    } else {
        *outputStream << "Incorrect state\n\r";
    }
}

void Automata::choice(std::string item) {
    if (state == ACCEPT) {
        if (menu.isValidItem(item)) {
            if (check(item)) {
                state = CHECK;
                rememberedItem = item;
                *outputStream << "Your change:\n\r" << getChange(item) << "\n\r";
                if (getChange(item) > cash) {
                    *outputStream << "Can not return change\n\r";
                    *outputStream << "{ cook() - to cook the item; cancel() - to cancel }\n\r";
                } else {
                    cook(item);
                }
            } else {
                *outputStream << "Input more money\n\r";
                state = ACCEPT;
            }
        } else {
            *outputStream << "Choose another item\n\r";
            getMenu();
            state = ACCEPT;
        }
    } else {
        *outputStream << "Incorrect state\n\r";
    }
}

bool Automata::check(std::string item) {
    return inputCash >= menu.getPrice(item);
}

void Automata::cook(std::string item) {
    if (state == CHECK) {
        if (!item.empty()) {
            state = COOK;
            srand(time(0));
            unsigned int time = rand() % 120;
            *outputStream << "Cooking " << item << " for " << time << " seconds\n\r";
            *outputStream << item << " is ready\n\r";
        } else {
            *outputStream << "Something went wrong\n\r";
        }
    } else {
        *outputStream << "Incorrect state\n\r";
    }
}

void Automata::cook() {
    if (state == CHECK) {
        cash += getChange(rememberedItem);
        inputCash = menu.getPrice(rememberedItem);
        cook(rememberedItem);
    } else {
        *outputStream << "Incorrect state\n\r";
    }
}

double Automata::getChange() {
    if (state == COOK) {
        double change = getChange(rememberedItem);
        cash -= change;
        finish();
        return change;
    } else {
        *outputStream << "Incorrect state\n\r";
        return 0;
    }
}

double Automata::getChange(std::string item) {
    if (state == COOK || state == CHECK)
        return inputCash - menu.getPrice(item);
    *outputStream << "Incorrect state\n\r";
    return 0;
}

void Automata::finish() {
    if (state == COOK) {
        cash += inputCash;
        rememberedItem.clear();
        inputCash = 0;
        state = WAIT;
    } else {
        *outputStream << "Incorrect state\n\r";
    }
}

double Automata::cancel() {
    double iCash = 0;
    switch (state) {
        case CHECK:
            *outputStream << "Choice cancelled\n\rMoney input enabled\n\r";
            state = ACCEPT;
            rememberedItem.clear();
            break;
        case ACCEPT:
            *outputStream << "Money is refunded\n\rMoney input cancelled\n\rWaiting enabled\n\r";
            state = WAIT;
            iCash = inputCash;
            inputCash = 0;
            break;
        default:
            *outputStream << "Con not leave state";
    }
    return iCash;
}

States Automata::getState() {
    *outputStream << "Automata is ";
    switch (state) {
        case OFF:
            *outputStream << "off";
            break;
        case WAIT:
            *outputStream << "waiting";
            break;
        case ACCEPT:
            *outputStream << "accepting money";
            break;
        case CHECK:
            *outputStream << "checking money";
            break;
        case COOK:
            *outputStream << "cooking";
            break;
    }
    *outputStream << "\n\r";
    return state;
}

double Automata::getCash(std::string adminPassword) {
    if (state == WAIT) {
        if (adminPassword == this->adminPassword)
            return cash;
        else
            *outputStream << "Incorrect password";
    } else {
        *outputStream << "Incorrect state";
    }
    return 0;
}

// Menu

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
