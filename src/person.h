/*!
\file
\brief файл содержит структуру Person, представляющую клиента. 
 
*/

#ifndef PERSON_H
#define PERSON_H

#include <iostream>

struct Person
{
  std::string name;     /// Имя клиента
  std::string surname;  /// Фамилия клиента
  short age;            /// Возраст
  std::string phone;    /// Контактный номер телефона
};

#endif // PERSON_H

