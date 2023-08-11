#include "user.h"
#include <iostream>

User::User() : firstName(""), surname(""), age(0), points(0) {}

void User::setFirstName(const std::string& fName) {
    firstName = fName;
}

void User::setSurname(const std::string& sName) {
    surname = sName;
}

void User::setAge(int userAge) {
    age = userAge;
}

void User::updatePoints(int newPoints) {
    points += newPoints;
}

void User::displayWelcomeMessage() const {
    std::cout << "Aplikacja do nauki języka koreańskiego. Możesz się wiele nauczyć!" << std::endl;
    std::cout << "Witaj " << firstName << "! Cieszę się, że skorzystałeś z kursu języka koreańskiego. Mam nadzieję, że wiele się nauczysz!" << std::endl;
    std::cout << "Na początek potrzebuję twoich danych, żeby zapisywać twoje postępy." << std::endl;
    std::cout << "Twój wiek to: " << age << ". Dopiero zaczynasz, więc masz " << points << " punktów, ale z czasem będziesz ich mieć więcej." << std::endl;
}
