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


void DbEngine::removeClient()
{
    if (getClientsCount() > 0)
    {
        short index;
        std::cout << "Клиента с каким номером вы желаете удалить? Введите ID: " << std::endl;
        std::cin >> index;

        if (getClientsCount() >= index && index >= 0)
        {
            people.erase(people.begin() + index);
            _clientCount--;
            savePeopleToFile();
        }
        else
            std::cout << "Отсутствует клиент с таким ID" << std::endl;
    }
    else
        std::cout << "Нет данных для удаления" << std::endl;
}


