/*!
\file
\brief Файл содержит класс DbEngine, представляющий сущность - базу данных.

 Содержит методы для добавления, удаления, отображения и поиска данных,
 а также методы чтения\записи базы в\из файл(а).  
 
*/

#ifndef DBENGINE_H
#define DBENGINE_H

#include "person.h"
#include <vector>

class DbEngine
{
public:
    DbEngine();
    void addClient();
    void showClients();
    void searchClient();
    void removeClient();
    int getClientsCount() const;
    void loadPeopleFromFile();
    void savePeopleToFile();

private:
    int _clientCount;           /// поле хранящее количество клиентов в базе
    std::vector<Person> people; /// вектор для хранения клиентов
};

#endif // DBENGINE_H
