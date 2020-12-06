#include <iostream>
#include <string>
#include "Automata.h"
int main()
{
    Automata a1;
    a1.on();
	std::cout << a1.getState() << std::endl;
    std::string* str = a1.getMenu();
    int price = 0; 
    for(int i = 0; i < 3; i++)
    {
        std :: cout << i+1 << ". " << str[i] << std::endl;
    }
    int num = 0;
    std :: cin >> num;
    num--;
    a1.choice(num);
    while(!a1.check())
    {
        std :: cin >> price;
        a1.coin(price);
    }
    a1.cook();
    int change = a1.finish();
    std :: cout << "End"<<std::endl;
    a1.off();

    
}