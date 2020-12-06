#include <gtest/gtest.h>
#include "Automata.h"

TEST(lab, on_off) {
	Automata probe = Automata();
	EXPECT_EQ(11, probe.on());
	EXPECT_EQ(11, probe.off());
}

TEST(lab, cash_money) {
	Automata probe_machine1 = Automata();
	probe_machine1.on();	
	probe_machine1.coin(10);
	probe_machine1.coin(15);
	EXPECT_EQ(25, probe_machine1.getCash());
}

TEST(lab, choice) {
	Automata probe_machine2 = Automata();
	probe_machine2.on();
	probe_machine2.coin(5);
	EXPECT_EQ(3, probe_machine2.choice(6));

	Automata probe_machine3 = Automata();
	probe_machine3.on();
	probe_machine3.coin(70);
	EXPECT_EQ(11, probe_machine3.choice(2));
}

TEST(lab4, check) {	
	Automata probe_machine4 = Automata();	
	probe_machine4.on();
	probe_machine4.coin(5);
	probe_machine4.choice(1);
	EXPECT_EQ(5, probe_machine4.check());

	Automata probe_machine5 = Automata();
	probe_machine5.on();
	probe_machine5.coin(40);
	probe_machine5.choice(1);
	EXPECT_EQ(11, probe_machine5.check());
}

TEST(lab4, cook) {
	Automata probe_machine6 = Automata();
	probe_machine6.on();
	EXPECT_EQ(4, probe_machine6.cook());
	probe_machine6.coin(200);
	probe_machine6.choice(1);
	probe_machine6.check();
	EXPECT_EQ(11, probe_machine6.cook());
}
