#include <iostream>
#include <unordered_map>
#include <string>
#include "user.h"
#include "languageCategory.h"

int main() {
    User user;
    LanguageCategory family({
        {"dziadek", "할아버지"},
        {"babcia", "할머니"},
        {"matka", "어머니"},
        {"ojciec", "아버지"},
        {"żona", "아내"},
        {"mąż", "남편"},
        {"córka", "딸"},
        {"syn", "아들"}
    });

    LanguageCategory seasons({
        {"wiosna", "봄"},
        {"lato", "여름"},
        {"jesień", "가을"},
        {"zima", "겨울"}
    });

    LanguageCategory bodyPart({
        {"głowa", "머리"},
        {"ręka", "손"},
        {"noga", "다리"},
        {"twarz", "얼굴"},
        {"oko", "눈"},
        {"ucho", "귀"}
    });

    std::string firstName, surname;
    int age;

    std::cout << "Podaj swoje imię: ";
    std::cin >> firstName;
    user.setFirstName(firstName);

    std::cout << "Podaj swoje nazwisko: ";
    std::cin >> surname;
    user.setSurname(surname);

    std::cout << "Podaj swój wiek: ";
    std::cin >> age;
    user.setAge(age);

    user.displayWelcomeMessage();

    std::cout << "Wybierz kategorię do nauki (1 - rodzina, 2 - pory roku, 3 - części ciała): ";
    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            family.displayWords();
            break;
        case 2:
            seasons.displayWords();
            break;
        case 3:
            bodyPart.displayWords();
            break;
        default:
            std::cout << "Niepoprawny wybór." << std::endl;
            return 1;
    }
    std::cout << "Czy jesteś gotów/gotowa do testu wyboru? (1 - tak, 0 - nie): ";
    std::cin >> choice;

    if (choice == 1) {
        switch (choice) {
            case 1:
                family.testClosedTask();
                break;
            case 2:
                seasons.testClosedTask();
                break;
            case 3:
                bodyPart.testClosedTask();
                break;
        }
    } else {
        std::cout << "Dziękuję za skorzystanie z aplikacji." << std::endl;
    }

    std::cout << "Czy jesteś gotów/gotowa do testu? (1 - tak, 0 - nie): ";
    std::cin >> choice;

    if (choice == 1) {
        switch (choice) {
            case 1:
                family.testWriteWords();
                break;
            case 2:
                seasons.testWriteWords();
                break;
            case 3:
                bodyPart.testWriteWords();
                break;
        }
    } else {
        std::cout << "Dziękuję za skorzystanie z aplikacji." << std::endl;
    }

    return 0;
}
