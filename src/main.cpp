/*!
\file
\brief Основной файл содержащий функцию main
 Дополнительно содержит функции для отображения меню,
 обработки выбора пунктов меню и имитации паузы после вывода информации.
*/

#include <iostream>
#include <cstdlib>
#include "dbengine.h"

void requireEnter();
void showMenu();
void updateMenu(DbEngine& db);

/**
	\brief Точка входа в приложение (Entry point)
	
    Выполнение программы начинается здесь.
	В функции main инициализируется экземпляр базы данных класса DbEngine,
	производится загрузка записей базы из файла,
	и вызывается функция отрисовки меню приложения.
	
	\return код статуса завершения 
*/
int main()
{
    DbEngine db{};
    db.loadPeopleFromFile();
    updateMenu(db);

    return 0;
}

/**
    \brief Отображает в консоль меню приложения

    Дополнительно отображает количество записей в базе данных.
    
    \param db экземпляр класса DbEngine, переданный по ссылке
*/
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

/**
    \brief Ожидает ввода символа перевода строки(имитирует нажатие Enter)

    Необходим для создания паузы в выводе сообщений перед очисткой консоли.
*/
void requireEnter()
{
    std::cout << "Нажмите Enter для продолжения... ";
    while(std::cin.get() != '\n');
}

/**
    \brief Обрабатывает выбор пункта меню и обновляет информацию в консоли.

    В функции содержится основной цикл исполнения программы.
    Завершение цикла осуществляется вводом цифры 0.
    
    \param db экземпляр класса DbEngine, переданный по ссылке
*/
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
        
        /// \brief В этом блоке кода косвенно определяется тип операционной системы
        /// \details Очистка консоли в Unix или Windows  
        if(path.find("/home") == 0)
            system("clear");
        else
            system("cls");

    } while(choice != 0);
}

