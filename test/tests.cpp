#include<gtest/gtest.h>
#include"Automata.h"

TEST(task, test_1) {

  Automata autmat;
  EXPECT_EQ(OFF, autmat.getState());

}

TEST(task, test_2) {

  Automata autmat;
  autmat.on();
  autmat.coin(90);
  EXPECT_EQ(90, autmat.gcash());

}

TEST(task, test_3) {

  Automata autmat;
  autmat.on();
  autmat.coin(69);
  autmat.choice("hot chocolate");
  EXPECT_FALSE(autmat.check());

}

TEST(task, test_4) {

  Automata autmat;
  autmat.on();
  autmat.coin(1);
  autmat.coin(79);
  EXPECT_EQ(80, autmat.gcash());

}

TEST(task, test_5) {

  Automata autmat;
  autmat.on();
  autmat.coin(90);
  autmat.choice("hot chocolate");
  autmat.cancel();
  EXPECT_EQ(WAIT, autmat.getState());

}

TEST(task, test_6) {

  Automata autmat;
  autmat.on();
  autmat.off();
  EXPECT_EQ(OFF, autmat.getState());

}

TEST(task, test_7) {

  Automata autmat;
  autmat.on();
  autmat.choice("lemonade");
  EXPECT_EQ(1, autmat.gchoice());

}

TEST(task, test_8) {

  Automata autmat;
  autmat.on();
  autmat.coin(30);
  autmat.choice("lemonade");
  EXPECT_TRUE(autmat.check());

}

TEST(task, test_9) {

  Automata autmat;
  autmat.on();
  autmat.coin(90);
  autmat.choice("hot chocolate");
  if (autmat.check() == 1 ) {
  autmat.cook();
  autmat.finish();
  }
  EXPECT_EQ(WAIT, autmat.getState());

}
