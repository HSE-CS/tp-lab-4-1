//
// Created by Данил on 06.12.2020.
//

#include "Automata.h"

signed main() {
    Automata BlueOysterBar;

    BlueOysterBar.on();
    BlueOysterBar.coin(150);
    BlueOysterBar.coin(50);
    BlueOysterBar.choice(5);
    if (BlueOysterBar.check())
        BlueOysterBar.cook();
    BlueOysterBar.finish();
    BlueOysterBar.coin(240);
    BlueOysterBar.choice(4);
    if (BlueOysterBar.check())
        BlueOysterBar.cook();
    BlueOysterBar.finish();
    BlueOysterBar.off();

    return 0;
}
