#include <gtest/gtest.h>

#include "Automata.h"

const std::map<std::string, int> MENU = {
    {"Coffee", 50},
    {"Milk", 35},
    {"Water", 20},
    {"Lemonade", 25},
    {"Juice", 30}
};


TEST(automata, off1) {
    Automata coffee_machine;
    EXPECT_EQ(ON, coffee_machine.getState());
}

