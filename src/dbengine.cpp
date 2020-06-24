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

void DbEngine::searchClient()
{
    std::string target;
    std::cout << "Введите имя клиента для поиска: ";
    (std::cin >> target).get();

    if (getClientsCount() > 0)
    {
        bool founded = false;
        for (int i = 0; i < getClientsCount(); i++)
        {
            if (target == people[i].name)
            {
                std::cout << "ID клиента: " << (i+1) << std::endl;
                std::cout << "Имя: " << people[i].name << std::endl;
                std::cout << "Фамилия: " << people[i].surname << std::endl;
                std::cout << "Возраст: " << people[i].age << std::endl;
                std::cout << "Телефон: " << people[i].phone << std::endl << std::endl;
                founded = true;
            }
        }
        if (!founded)
            std::cout << "Не найден клиент с таким именем." << std::endl;
    }
    else
        std::cout << "База данных пустая." << std::endl;
}
