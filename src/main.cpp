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

