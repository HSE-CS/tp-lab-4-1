#include <gtest/gtest.h>
#include "Automata.h"

#include <iostream>
#include <vector>
#include <string>

TEST(MenuTest, test_constructor1) {
    const char* items[] = {"apple", "book", "drink"};
    double prices[] = {12.4, 124.6, 10.8};
    Menu menu(3, items, prices);
    EXPECT_EQ(12.4, menu.getPrice("apple"));
    EXPECT_EQ(124.6, menu.getPrice("book"));
    EXPECT_EQ(10.8, menu.getPrice("drink"));
}

TEST(MenuTest, test_constructor2) {
    std::vector<std::string> items;
    std::vector<double> prices;
    items.emplace_back("apple");
    prices.push_back(12.4);
    Menu menu(items, prices);
    EXPECT_EQ(12.4, menu.getPrice("apple"));
}

TEST(MenuTest, test_constructor3) {
    std::vector<std::string> items;
    std::vector<double> prices;
    items.emplace_back("apple");
    prices.push_back(12.4);
    Menu menu(items, prices);
    Menu menu1(menu);
    EXPECT_EQ(12.4, menu1.getPrice("apple"));
}

TEST(MenuTest, test_addItem1) {
    Menu menu;
    menu.addItem("apple", 13.4);
    EXPECT_EQ(13.4, menu.getPrice("apple"));
}

TEST(MenuTest, test_addItem2) {
    Menu menu;
    menu.addItem("apple", 13.4);
    menu.addItem("pineapple", 14.3);
    EXPECT_EQ(14.3, menu.getPrice("pineapple"));
    EXPECT_EQ(13.4, menu.getPrice("apple"));
}

TEST(MenuTest, test_removeItem1) {
    Menu menu;
    menu.addItem("apple", 13.4);
    menu.addItem("pineapple", 14.3);
    menu.removeItem("apple");
    EXPECT_EQ(14.3, menu.getPrice("pineapple"));
    EXPECT_EQ(1, menu.getSize());
}

TEST(MenuTest, test_removeItem2) {
    Menu menu;
    menu.addItem("apple", 13.4);
    menu.addItem("pineapple", 14.3);
    menu.removeItem("apple");
    menu.removeItem("pineapple");
    EXPECT_EQ(0, menu.getSize());
}

TEST(MenuTest, test_changeItem1) {
    Menu menu;
    menu.addItem("apple", 13.4);
    menu.changeItem("apple", 14.3);
    EXPECT_EQ(14.3, menu.getPrice("apple"));
}

TEST(MenuTest, test_changeItem2) {
    Menu menu;
    menu.addItem("apple", 13.4);
    menu.addItem("pineapple", 14.3);
    menu.changeItem("pineapple", 10.5);
    EXPECT_EQ(10.5, menu.getPrice("pineapple"));
    EXPECT_EQ(13.4, menu.getPrice("apple"));
}

TEST(MenuTest, test_isValidItem1) {
    Menu menu;
    menu.addItem("apple", 13.4);
    menu.addItem("pineapple", 14.3);
    EXPECT_EQ(1, menu.isValidItem("pineapple"));
    EXPECT_EQ(0, menu.isValidItem("not_apple"));
}

TEST(MenuTest, test_operator1) {
    Menu menu;
    menu.addItem("apple", 13.4);
    menu.addItem("pineapple", 14.3);
    Menu menu1;
    menu1.addItem("cherry", 10.2);
    menu1 += menu;
    EXPECT_EQ(3, menu1.getSize());
    EXPECT_EQ(13.4, menu1.getPrice("apple"));
    EXPECT_EQ(14.3, menu1.getPrice("pineapple"));
    EXPECT_EQ(10.2, menu1.getPrice("cherry"));
}

TEST(MenuTest, test_operator2) {
    Menu menu;
    menu.addItem("apple", 13.4);
    menu.addItem("pineapple", 14.3);
    Menu menu1 = menu;
    EXPECT_EQ(2, menu1.getSize());
    EXPECT_EQ(13.4, menu1.getPrice("apple"));
    EXPECT_EQ(14.3, menu1.getPrice("pineapple"));
}

TEST(MenuTest, test_operator3) {
    Menu menu;
    menu.addItem("apple", 13.4);
    menu.addItem("pineapple", 14.3);
    Menu menu1 = menu;
    EXPECT_EQ(1, (menu1 == menu));
    EXPECT_EQ(0, (menu1 != menu));
}

TEST(MenuTest, test_getItemIndex1) {
    Menu menu;
    menu.addItem("apple", 13.4);
    menu.addItem("pineapple", 14.3);
    EXPECT_EQ(0, menu.getItemIndex("apple"));
    EXPECT_EQ(1, menu.getItemIndex("pineapple"));
}

TEST(AutomataTest, test_changeAdminPassword1) {
    Automata automata;
    EXPECT_EQ(1, automata.changeAdminPassword("1234", "4321"));
}

TEST(AutomataTest, test_changeAdminPassword2) {
    Automata automata;
    EXPECT_EQ(0, automata.changeAdminPassword("1", "4321"));
}

TEST(AutomataTest, test_getMenu1) {
    Menu menu;
    menu.addItem("Cola", 12.4);
    Automata automata(&(std::cout), "1234", menu);
    automata.on();
    EXPECT_EQ(1, automata.getMenu(false) == menu);
}

TEST(AutomataTest, test_getMenu2) {
    Menu menu;
    menu.addItem("Cola", 12.4);
    Automata automata(&(std::cout), "1234", menu);
    automata.on();
    automata.getMenu("1234").changeItem("Cola", 10);
    EXPECT_EQ(0, automata.getMenu(false) == menu);
}

TEST(AutomataTest, test_state1) {
    Menu menu;
    menu.addItem("Cola", 12.4);
    Automata automata(&(std::cout), "1234", menu);
    EXPECT_EQ(0, automata.getState());
}

TEST(AutomataTest, test_state2) {
    Menu menu;
    menu.addItem("Cola", 12.4);
    Automata automata(&(std::cout), "1234", menu);
    automata.on();
    EXPECT_EQ(1, automata.getState());
}

TEST(AutomataTest, test_state3) {
    Menu menu;
    menu.addItem("Cola", 12.4);
    Automata automata(&(std::cout), "1234", menu);
    automata.on();
    automata.coin(10);
    EXPECT_EQ(2, automata.getState());
}

TEST(AutomataTest, test_state4) {
    Menu menu;
    menu.addItem("Cola", 12.4);
    Automata automata(&(std::cout), "1234", menu);
    automata.on();
    automata.coin(14);
    EXPECT_EQ(14, automata.cancel());
    EXPECT_EQ(1, automata.getState());
}

TEST(AutomataTest, test_state5) {
    Menu menu;
    menu.addItem("Cola", 12.4);
    Automata automata(&(std::cout), "1234", menu);
    automata.on();
    automata.coin(10);
    automata.choice("Cola");
    EXPECT_EQ(2, automata.getState());
}
TEST(AutomataTest, test_state6) {
    Menu menu;
    menu.addItem("Cola", 12.4);
    Automata automata(&(std::cout), "1234", menu);
    automata.on();
    automata.coin(14);
    automata.choice("Cola");
    EXPECT_EQ(3, automata.getState());
}

TEST(AutomataTest, test_state7) {
    Menu menu;
    menu.addItem("Cola", 12.4);
    Automata automata(&(std::cout), "1234", menu);
    automata.on();
    automata.coin(14);
    automata.choice("Cola");
    EXPECT_EQ(0, automata.cancel());
    EXPECT_EQ(2, automata.getState());
}

TEST(AutomataTest, test_state8) {
    Menu menu;
    menu.addItem("Cola", 12.4);
    Automata automata(&(std::cout), "1234", menu);
    automata.on();
    automata.coin(14);
    automata.choice("Cola");
    automata.cook();
    EXPECT_EQ(4, automata.getState());
}

TEST(AutomataTest, test_state9) {
    Menu menu;
    menu.addItem("Cola", 12.4);
    Automata automata(&(std::cout), "1234", menu);
    automata.on();
    automata.coin(14);
    automata.choice("Cola");
    automata.cook();
    EXPECT_EQ(0, automata.getChange());
    EXPECT_EQ(1, automata.getState());
}

TEST(AutomataTest, test_state10) {
    Menu menu;
    menu.addItem("Cola", 12.4);
    Automata automata(&(std::cout), "1234", menu);
    automata.on();
    automata.coin(14);
    automata.choice("Cola");
    automata.cook();
    EXPECT_EQ(0, automata.getChange());
    automata.off();
    EXPECT_EQ(0, automata.getState());
}

TEST(AutomataTest, test_getChange) {
    Menu menu;
    menu.addItem("Cola", 12.4);
    Automata automata(&(std::cout), "1234", menu);
    automata.on();
    automata.coin(14);
    automata.choice("Cola");
    automata.cook();
    EXPECT_EQ(1.6, automata.getChange());
}

TEST(AutomataTest, test_getCash) {
    Menu menu;
    menu.addItem("Cola", 12.4);
    Automata automata(&(std::cout), "1234", menu, 12);
    automata.on();
    automata.coin(14);
    automata.choice("Cola");
    automata.cook();
    EXPECT_EQ(1.6, automata.getChange());
    EXPECT_EQ(24.4, automata.getCash("1234"));
}
