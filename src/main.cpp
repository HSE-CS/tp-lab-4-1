//
// Created by Kostin Andrej on 2020.
//
#include "Automata.h"
#include <Windows.h>

int main() {
    int timer=0;
    while(true){
        system("cls");
        cout<<timer<<"%";
        Sleep(570);
        if (timer!=100){
            timer++;
        }
        else{
            cout<<"End";
            break;
        }
    }


    Automata automata1;
    cout << "State: "<< automata1.getState() << endl << endl;

    automata1.on();
    cout << "State: "<< automata1.getState() << endl << endl;

    automata1.coin(999);
    cout << "State: "<< automata1.getState() << endl << endl;

    auto* menu = new string [8];
    menu = automata1.getMenu();
    cout << "State: "<< automata1.getState() << endl << endl;



    automata1.choice(1);

    /*automata1.coin(3);
    automata1.choice(2);
    cout << automata1.getCash() << endl << endl;*/

    cout << endl << "Final State: "<< automata1.getState() << endl << endl;



    if (automata1.getState() == WAIT){
        cout << "SUCCESS" << endl;
    }






    delete[] menu;

    return 0;





}