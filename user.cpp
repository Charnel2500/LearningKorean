#include "user.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>  
#include <ctime>   

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
    password = encryptMessage(password, 6);

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
                    password = decryptMessage(password, 6);
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

std::string User::encryptMessage(const std::string& message, int shift) {
    std::string encryptedMessage = "";

    for (char c : message) {
        if (isalpha(c)) {
            char base = (isupper(c)) ? 'A' : 'a';
            char encryptedChar = (c - base + shift) % 26 + base;
            encryptedMessage += encryptedChar;
        } else {
            encryptedMessage += c;
        }
    }

    return encryptedMessage;
}

std::string User::decryptMessage(const std::string& message, int shift) {
    std::string decryptedMessage = "";

    for (char c : message) {
        if (isalpha(c)) {
            char base = (isupper(c)) ? 'A' : 'a';
            char decryptedChar = (c - base + 26 - shift) % 26 + base;
            decryptedMessage += decryptedChar;
        } else {
            decryptedMessage += c;
        }
    }

    return decryptedMessage;
}


void User::displayWelcomeMessage() const {
    std::cout << "Aplikacja do nauki języka koreańskiego. Możesz się wiele nauczyć!" << std::endl;
    std::cout << "Witaj " << firstName << "! Cieszę się, że skorzystałeś z kursu języka koreańskiego. Mam nadzieję, że wiele się nauczysz!" << std::endl;
    std::cout << "Na początek potrzebuję twoich danych, żeby zapisywać twoje postępy." << std::endl;
    std::cout << "Twój wiek to: " << age << ". Dopiero zaczynasz, więc masz " << points << " punktów, ale z czasem będziesz ich mieć więcej." << std::endl;
}

void User::resetPassword() {
    std::string newPassword;
    std::cout << "Podaj nowe hasło: ";
    std::cin >> newPassword;
    password = encryptMessage(newPassword, 6);

    // Zapisz nowe hasło do pliku lub bazy danych
    std::ifstream inputFile("users.txt");
    std::ofstream outputFile("temp_users.txt");
    if (inputFile.is_open() && outputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::istringstream iss(line);
            std::string fName, sName, storedPassword;
            int fileAge;
            if (iss >> fName >> sName >> storedPassword >> fileAge) {
                if (fName == firstName && sName == surname) {
                    storedPassword = password;  // Zaktualizuj hasło
                }
                outputFile << fName << " " << sName << " " << storedPassword << " " << fileAge << "\n";
            }
        }
        inputFile.close();
        outputFile.close();

        // Zamień oryginalny plik z temp_users.txt
        std::remove("users.txt");
        std::rename("temp_users.txt", "users.txt");
        
        std::cout << "Hasło zostało zresetowane." << std::endl;
    } else {
        std::cout << "Nie udało się otworzyć plików." << std::endl;
    }
}


