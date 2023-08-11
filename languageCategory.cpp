#include "languageCategory.h"
#include <iostream>

LanguageCategory::LanguageCategory(const std::unordered_map<std::string, std::string>& words) : vocabulary(words) {}

void LanguageCategory::displayWords() const {
    for (const auto& entry : vocabulary) {
        std::cout << "Polski: " << entry.first << " | Koreański: " << entry.second << std::endl;
    }
}

void LanguageCategory::testWriteWords() const {
    std::string word;
    int correctAnswers = 0;

    for (const auto& entry : vocabulary) {
        std::cout << "Napisz wyraz po koreańsku dla: " << entry.first << "." << std::endl;
        std::cin >> word;

        if (word == entry.second) {
            std::cout << "Odpowiedź prawidłowa." << std::endl;
            correctAnswers++;
        } else {
            std::cout << "Odpowiedź błędna. Prawidłowa odpowiedź to: " << entry.second << std::endl;
        }
    }

    std::cout << "Twój wynik to: " << correctAnswers << " / " << vocabulary.size() << std::endl;
}

void LanguageCategory::testClosedTask() const {
    char userChoice;
    int correctAnswers = 0;

    for (const auto& entry : vocabulary) {
        std::cout << "Wybierz poprawną odpowiedź (a, b, c, d) dla wyrazu: " << entry.first << "." << std::endl;

        char correctChoice = 'a' + rand() % 4;

        int wrongIndex = rand() % vocabulary.size();
        auto wrongIter = vocabulary.begin();
        std::advance(wrongIter, wrongIndex);

        for (char choice = 'a'; choice <= 'd'; choice++) {
            if (choice == correctChoice) {
                std::cout << choice << ") " << entry.second << " ";
            } else if (choice - 'a' == wrongIndex) {
                std::cout << choice << ") " << wrongIter->second << " ";
            } else {
                std::cout << choice << ") Inna odpowiedź ";
            }
        }

        std::cin >> userChoice;

        if (userChoice == correctChoice) {
            std::cout << "Odpowiedź prawidłowa." << std::endl;
            correctAnswers++;
        } else {
            std::cout << "Odpowiedź błędna. Prawidłowa odpowiedź to: " << correctChoice << ") " << entry.second << std::endl;
        }
    }

    std::cout << "Twój wynik to: " << correctAnswers << " / " << vocabulary.size() << std::endl;
}
