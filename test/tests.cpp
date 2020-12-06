#include <gtest/gtest.h>
#include "Automata.h"

TEST(lab, on_off) {
	Automata probe = Automata();
	EXPECT_EQ(11, probe.on());
	EXPECT_EQ(11, probe.off());
}

TEST(lab, cash_money) {
	Automata probe_machine = Automata();
	probe_machine.on();	
	probe_machine.coin(10);
	probe_machine.coin(15);
	EXPECT_EQ(25, probe_machine.getCash());
}

TEST(lab, choice) {
	Automata probe_machine = Automata();
	probe_machine.on();
	probe_machine.coin(5);
	EXPECT_EQ(3, probe_machine.choice(6));

	Automata probe_machine = Automata();
	probe_machine.on();
	probe_machine.coin(70);
	EXPECT_EQ(11, probe_machine.choice(2));
}

TEST(lab4, check) {	
	Automata probe_machine = Automata();	
	probe_machine.on();
	probe_machine.coin(5);
	probe_machine.choice(1);
	EXPECT_EQ(5, probe_machine.check());

	Automata probe_machine = Automata();
	probe_machine.on();
	probe_machine.coin(40);
	probe_machine.choice(1);
	EXPECT_EQ(11, probe_machine.check());
}

TEST(lab4, cook) {
	Automata probe_machine = Automata();
	probe_machine.on();
	EXPECT_EQ(4, probe_machine.cook());
	probe_machine.coin(200);
	probe_machine.choice(1);
	probe_machine.check();
	EXPECT_EQ(11, probe_machine.cook());
}