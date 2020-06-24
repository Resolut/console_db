#include <iostream>
#include <fstream>
#include "dbengine.h"
#include "Person.h"

DbEngine::DbEngine()
{
    _clientCount = 0;
    people = {};
}

void DbEngine::addClient()
{
        std::string _name;
        std::string _surname;
        short _age;
        std::string _phone;

        std::cout << "Введите Имя: ";
        std::cin >> _name;

        std::cout << "Введите Фамилию: ";
        std::cin >> _surname;

        std::cout << "Введите возраст: ";
        std::cin >> _age;

        std::cout << "Введите номер телефона: ";
        std::cin >> _phone;

        people.push_back({_name, _surname, _age, _phone});
        _clientCount++;
}

int DbEngine::getClientsCount() const
{
    return people.size();
}
