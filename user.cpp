#include "user.h"
#include <iostream>
#include <fstream>
#include <sstream>

User::User() : firstName(""), surname(""), password(""), age(0), points(0) {}

void User::setFirstName(const std::string& fName) {
    firstName = fName;
}

void User::setSurname(const std::string& sName) {
    surname = sName;
}

void User::setPassword(const std::string& userPassword) {
    password = userPassword;
}

void User::setAge(int userAge) {
    age = userAge;
}

void User::updatePoints(int newPoints) {
    points += newPoints;
}

void User::registerUser() {
    std::cout << "Podaj swoje imię: ";
    std::cin >> firstName;

    std::cout << "Podaj swoje nazwisko: ";
    std::cin >> surname;
    
    std::cout << "Podaj swoje hasło: ";
    std::cin >> password;

    std::cout << "Podaj swój wiek: ";
    std::cin >> age;

    std::ofstream userFile("users.txt", std::ios::app);
    if (userFile.is_open()) {
        userFile << firstName << " " << surname << " " << password << " " << age << "\n";
        userFile.close();
        std::cout << "Użytkownik zarejestrowany i dane zapisane do pliku." << std::endl;
    } else {
        std::cout << "Nie udało się otworzyć pliku." << std::endl;
    }
}

bool User::loginUser() {
    std::string enteredFirstName, enteredSurname;
    std::string enteredPassword;
    
    std::cout << "Podaj swoje imię: ";
    std::cin >> enteredFirstName;

    std::cout << "Podaj swoje nazwisko: ";
    std::cin >> enteredSurname;

    std::ifstream userFile("users.txt");
    if (userFile.is_open()) {
        std::string line;
        while (std::getline(userFile, line)) {
            std::istringstream iss(line);
            std::string fName, sName, password;
            int fileAge;
            if (iss >> fName >> sName >> password >> fileAge) {
                if (fName == enteredFirstName && sName == enteredSurname) {
                    userFile.close();
                    std::cout << "Użytkownik znaleziony. Podaj hasło: ";
                    std::cin >> enteredPassword;
                    if (enteredPassword == password) {
                        firstName = fName;
                        surname = sName;
                        age = fileAge;
                        points = 0;
                        return true;
                    } else {
                        std::cout << "Niepoprawne hasło." << std::endl;
                        return false;
                    }
                }
            }
        }
        userFile.close();
    } else {
        std::cout << "Nie udało się otworzyć pliku." << std::endl;
    }

    std::cout << "Nie znaleziono użytkownika o podanych danych." << std::endl;
    std::cout << "Czy chcesz spróbować ponownie? (tak/nie): ";
    std::string retryChoice;
    std::cin >> retryChoice;
    if (retryChoice == "tak") {
        return loginUser(); // Rekursywnie próbuj ponownie
    } else {
        std::cout << "Czy chcesz się zarejestrować? (tak/nie): ";
        std::string registerChoice;
        std::cin >> registerChoice;
        if (registerChoice == "tak") {
            registerUser();
            return loginUser();
        } else {
            return false;
        }
    }
}



void User::displayWelcomeMessage() const {
    std::cout << "Aplikacja do nauki języka koreańskiego. Możesz się wiele nauczyć!" << std::endl;
    std::cout << "Witaj " << firstName << "! Cieszę się, że skorzystałeś z kursu języka koreańskiego. Mam nadzieję, że wiele się nauczysz!" << std::endl;
    std::cout << "Na początek potrzebuję twoich danych, żeby zapisywać twoje postępy." << std::endl;
    std::cout << "Twój wiek to: " << age << ". Dopiero zaczynasz, więc masz " << points << " punktów, ale z czasem będziesz ich mieć więcej." << std::endl;
}



