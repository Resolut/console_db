#include <iostream>
#include <cstdlib>
#include "dbengine.h"

void requireEnter();
void showMenu();
void updateMenu(DbEngine& db);

int main()
{
    return 0;
}

void showMenu(DbEngine& db)
{
    std::cout << "Количество клиентов в базе: " << db.getClientsCount() << std::endl;
    std::cout << "МЕНЮ: " << std::endl;

    std::cout << "0. Завершить программу" << std::endl;
    std::cout << "1. Добавить Клиента" << std::endl;
    std::cout << "2. Отобразить список всех клиентов" << std::endl;
    std::cout << "3. Сохранить клиентов в файл" << std::endl;
    std::cout << "4. Загрузить из файла" << std::endl;
    std::cout << "5. Поиск клиента" << std::endl;
    std::cout << "6. Удалить клиента из базы" << std::endl;

    std::cout << ">>> ";
}

void requireEnter()
{
    std::cout << "Нажмите Enter для продолжения... ";
    while(std::cin.get() != '\n');
}

void updateMenu(DbEngine& db)
{
    std::string path(getenv("HOME"));
    int choice;
    do
    {
        showMenu(db);

        (std::cin >> choice).get();

        switch(choice)
        {
            case 1:
                db.addClient();
                break;
            case 2:
                db.showClients();
                break;
            case 3:
                db.savePeopleToFile();
                break;
            case 4:
                db.loadPeopleFromFile();
                break;
            case 5:
                db.searchClient();
                break;
            case 6:
                db.removeClient();
                break;
        }

        requireEnter();

        if(path.find("/home") == 0)
            system("clear");
        else
            system("cls");

    } while(choice != 0);
}
