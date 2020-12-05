#include "gtest/gtest.h"
#include "Automata.h"
#include <iostream>
using namespace std;

TEST(task, test1){
    Automata *a = new Automata();
    str s = a->off();
    EXPECT_EQ(s, "Чтобы выключить автомат нажмите cancel() и off()");
}

TEST(task, test2){
    Automata *a = new Automata();
    str s = a->on();
    EXPECT_EQ(s, "Автомат включен\nВнесите деньги и выберите напиток");
}

TEST(task, test3){
    Automata *a = new Automata();
    a->on();
    a->coin(10.0)
    str s = a->coin(12.01);
    EXPECT_EQ(s, "Вы внесли 12.010000. Всего: 22.010000");
}

TEST(task, test4){
    Automata *a = new Automata();
    a->on();
    str s = a->choice("coffee");
    EXPECT_EQ(s, "Вернитесь к прошлому шагу");
}

TEST(task, test5){
    Automata *a = new Automata();
    a->on();
    a->coin(0.0);
    str s = a->choice("cofe");
    EXPECT_EQ("Такого напитка нет в списке:(");
}

TEST(task, test6){
    Automata *a = new Automata();
    a->on();
    a->coin(1.0);
    str s = a->choice("black_tea");
    EXPECT_EQ(s, "Внесенной суммы не хватает");
}

TEST(task, test7){
    Automata *a = new Automata();
    a->on();
    a->coin(100.156);
    str s = a->choice("green_tea");
    EXPECT_EQ(s, "Вы выбрали green_tea");
}

TEST(task, test8){
    Automata *a = new Automata();
    a->on()
    a->coin(12123.3);
    a->choice("green_tea");
    str s = a->cancel();
    EXPECT_EQ(s, "Вы вышли в главное меню\nВаша сдача: 12123.300000");
}

TEST(task, test9){
    Automata *a = new Automata();
    a->on();
    a->coin(100.0);
    a->choice("black_tea");
    str s = a->cook();
    EXPECT_EQ(s, "Напиток готов. У вас осталось: 84.500000")
}

TEST(task, test10){
    Automata *a = new Automata();
    str s = a->cancel();
    EXPECT_EQ(s, "Автомат уже выключен");
}