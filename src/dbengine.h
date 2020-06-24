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
    int _clientCount;
    std::vector<Person> people;
};

#endif // DBENGINE_H
