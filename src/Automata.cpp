#include <Automata.h>

int menu_len = 4;
string drinks[4] = {"coffee", "black_tea", "green_tea", "white_tea"};
double prices[4] = {20.9,    15.5,           25.3,        30.6};

Automata::Automata() {
    for (int i = 0; i < menu_len; ++i) {
        this->menu.insert(pair<string, double>(drinks[i], prices[i]));
    }
}

void Automata::setMenuFromFile(string menu_file_name) {
    string tmp;
    string name;
    string price;
    ifstream file(menu_file_name);
    if (file.is_open()){
        while (getline(file, tmp)){
            name = tmp.substr(0, tmp.find(' '));
            price = tmp.substr(tmp.find(' ') + 1, tmp.size());
            this->menu.insert(pair<string, double>(name, atof(price.c_str())));

        }
    } else {
        cout << "FILE WAS NOT OPENED";
        exit(-100);
    }
    file.close();
}

Automata::Automata(string menu_file_name) {
    setMenuFromFile(menu_file_name);
}

void Automata::printMenuToConsole(){
    cout << endl << "Меню:" << endl;
    for (auto & i : this->menu) {
        cout << i.first << ": " << i.second << endl;
    }
    cout << endl;
}

string Automata::on(){
    if (this->state == STATES::OFF) {
        this->state = STATES::WAIT;
        return "Автомат включен\nВнесите деньги и выберите напиток";
    } else{
        return "Автомат уже включен";
    }
}
string Automata::off(){
    if (this->state == STATES::WAIT) {
        this->state = STATES::OFF;
        return "Автомат выключен";
    } else if (this->state == STATES::OFF){
        return "Автомат уже выключен";
    } else {
        return "Чтобы выключить автомат нажмите cancel() и off()";
    }
}

map<string, double> Automata::getMenu(){
    return this->menu;
}

STATES Automata::getState(){
    return this->state;
}

string Automata::coin(double sum){
    if (this->state == STATES::WAIT || this->state == STATES::ACCEPT) {
        this->cash += sum;
        this->state = STATES::ACCEPT;
        return "Вы внесли " + to_string(sum) + ". Всего: " + to_string(this->cash);
    } else {
        return "Вернитесь на предыдущий шаг, чтобы внести деньги";
    }
}

string Automata::choice(string product){
    if (this->state != STATES::ACCEPT && this->state != STATES::WAIT){
        return "Вернитесь к прошлому шагу";
    }
    if (this->menu.count(product) == 0) {
        return "Такого напитка нет в списке:(";
    }
    this->chosen_product = product;
    if (!check()){
        this->state = STATES::ACCEPT;
        return "Внесенной суммы не хватает";
    }
    return "Вы выбрали " + product;
}
bool Automata::check(){
    return this->cash >= menu[this->chosen_product];
}
string Automata::cancel(){
    if (this->state == STATES::OFF){
        return "Автомат уже выключен";
    }
    double tmp_cash = this->cash;
    this->cash = 0.0;
    this->state = STATES::WAIT;
    return "Вы вышли в главное меню\nВаша сдача: " + to_string(tmp_cash);
}
string Automata::cook(){
    const int t = 100;
    cout << this->chosen_product << " готовится" << endl;
    cout << "1% ";
    //_sleep(t);
    cout << "14% ";
    //_sleep(t);
    cout << "26% ";
    //_sleep(t);
    cout << "49% ";
    //_sleep(t);
    cout << "84% ";
    //_sleep(t);
    cout << "99% ";
    //_sleep(t);
    cout << "100%" << endl;
    this->cash -= menu[this->chosen_product];
    this->state = STATES::WAIT;
    return "Напиток готов. У вас осталось: " + to_string(this->cash);
}
