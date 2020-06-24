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

void DbEngine::showClients()
{
    if(getClientsCount() > 0)
    {
        for (int i = 0; i < getClientsCount(); i++)
        {
            std::cout << "ID Клиента:\t" << (i+1) << std::endl;
            std::cout << "Имя:\t\t" << people[i].name << std::endl;
            std::cout << "Фамилия:\t" << people[i].surname << std::endl;
            std::cout << "Возраст:\t" << people[i].age << std::endl;
            std::cout << "Телефон:\t" << people[i].phone << std::endl << std::endl;
        }
    }
    else
        std::cout << "Нет записей в базе."  << std::endl;
}

void DbEngine::savePeopleToFile()
{
    std::ofstream file("database.txt");

    if (file.is_open())
    {
        file << getClientsCount() << std::endl;

        for (int i = 0; i < getClientsCount(); i++)
        {
            file << people[i].name << std::endl;
            file << people[i].surname << std::endl;
            file << people[i].age << std::endl;
            file << people[i].phone << std::endl;
        }
        std::cout << "Данные успешно записаны в файл." << std::endl;
        file.close();
    }
    else
        std::cout << "Ошибка сохранения в файл." << std::endl;

}

void DbEngine::loadPeopleFromFile()
{
    std::ifstream file("database.txt");

    if (file.is_open())
    {
        file >> _clientCount;
        people.resize(_clientCount);
        if (getClientsCount() > 0)
        {
            int i = 0;
            do
            {
                file >> people[i].name;
                file >> people[i].surname;
                file >> people[i].age;
                file >> people[i].phone;

                i++;
            } while(!file.eof());

            std::cout << "Список клиентов успешно загружен. " << std::endl;
        }
        else
            std::cout << "База данных пустая" << std::endl;
    }
    else
        std::cout << "Файл database.txt не существует." << std::endl;
}

