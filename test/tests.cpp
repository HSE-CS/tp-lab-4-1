#include <gtest/gtest.h>
#include "Automata.h"

TEST(task, test1){
    Automata *a = new Automata();
    EXPECT_EQ(a->off(), "Чтобы выключить автомат нажмите cancel() и off()");
}

TEST(task, test2){
    Automata *a = new Automata();
    EXPECT_EQ(a->on(), "Автомат включен\nВнесите деньги и выберите напиток");
}

TEST(task, test3){
    Automata *a = new Automata();
    a->on();
    a->coin(10.0);
    EXPECT_EQ(a->coin(12.01), "Вы внесли 12.010000. Всего: 22.010000");
}

TEST(task, test4){
    Automata *a = new Automata();
    a->on();
    EXPECT_EQ(a->choice("coffee"), "Вернитесь к прошлому шагу");
}

TEST(task, test5){
    Automata *a = new Automata();
    a->on();
    a->coin(0.0);
    EXPECT_EQ(a->choice("cofe"), "Такого напитка нет в списке:(");
}

TEST(task, test6){
    Automata *a = new Automata();
    a->on();
    a->coin(1.0);
    EXPECT_EQ(a->choice("black_tea"), "Внесенной суммы не хватает");
}

TEST(task, test7){
    Automata *a = new Automata();
    a->on();
    a->coin(100.156);
    EXPECT_EQ(a->choice("green_tea"), "Вы выбрали green_tea");
}

TEST(task, test8){
    Automata *a = new Automata();
    a->on();
    a->coin(12123.3);
    a->choice("green_tea");
    EXPECT_EQ(a->cancel(), "Вы вышли в главное меню\nВаша сдача: 12123.300000");
}

TEST(task, test9){
    Automata *a = new Automata();
    a->on();
    a->coin(100.0);
    a->choice("black_tea");
    EXPECT_EQ(a->cook(), "Напиток готов. У вас осталось: 84.500000");
}

TEST(task, test10){
    Automata *a = new Automata();
    EXPECT_EQ(a->cancel(), "Автомат уже выключен");
}