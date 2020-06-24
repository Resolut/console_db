#include <iostream>
#include <fstream>
#include "dbengine.h"
#include "person.h"


/**
    \brief Конструктор объекта базы данных

    Инициализирует внутренний вектор и задаёт 
    нулевое значение количеству клиентов в базе
*/
DbEngine::DbEngine()
{
    _clientCount = 0;
    people = {};
}

/**
    \brief добавляет клиента в базу данных

    Запрашивает ввод полей структуры Person у пользователя
    и сохраняет структуру в вектор 
*/
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


/**
    \brief Возвращает число клиентов в базе   
    \return количество клиентов в векторе
*/
int DbEngine::getClientsCount() const
{
    return people.size();
}

/**
    \brief Удаляет клиента по индексу из базы.   
    Производит удаление данных клиента.
    Проверяет, что введенный индекс находится в допустимом диапазоне.
    В случае если удаление невозможно, выводит диагностическое сообщение. 
*/
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

/**
    \brief Производит поиск в базе данных по имени клиента.   
    
    Отображает все поля данных клиента, если обнаружено совпадения по имени.
    В случае, если поиск не дал результатов, выводит диагностическое сообщение. 
*/
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

/**
    \brief Отображает все данные по всем клиентам в базе.   
    
    В случае, если база пуста, выводит диагностическое сообщение. 
*/
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

/**
    \brief Производит запись в файл всех добавленных клиентов в базе в текущем сеансе.   
    Создает файл, если он ещё не создан и записывает количество клиентов и все их данные.
    В случае, если запись в файл невозможна, выводит диагностическое сообщение. 
*/
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

/**
    \brief Производит чтение из файла обо всех добавленных клиентов в базе.   
    Открывает файл на чтение и построчно считывает данные о клиентах.
    В случае, если файл не найден, или данные отсутствуют, выводит диагностическое сообщение. 
*/
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

