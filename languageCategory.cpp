#include "languageCategory.h"
#include <iostream>
#include <algorithm>
#include <vector>

LanguageCategory::LanguageCategory(const std::unordered_map<std::string, std::string>& words) : vocabulary(words) {}

void LanguageCategory::displayWords() const {
    for (const auto& entry : vocabulary) {
        std::cout << "Polski: " << entry.first << " | Koreański: " << entry.second << std::endl;
    }
}

void LanguageCategory::testWriteWordsKorean() const {
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

void LanguageCategory::testWriteWordsPolish() const {
    std::string word;
    int correctAnswers = 0;

    for (const auto& entry : vocabulary) {
        std::cout << "Napisz wyraz po polsku dla: " << entry.second << "." << std::endl;
        std::cin >> word;

        if (word == entry.first) {
            std::cout << "Odpowiedź prawidłowa." << std::endl;
            correctAnswers++;
        } else {
            std::cout << "Odpowiedź błędna. Prawidłowa odpowiedź to: " << entry.first << std::endl;
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

        std::vector<int> wrongIndices;
        for (int i = 0; i < 4; ++i) {
            if (i != (correctChoice - 'a')) {
                wrongIndices.push_back(i);
            }
        }
        std::random_shuffle(wrongIndices.begin(), wrongIndices.end());

        for (char choice = 'a'; choice <= 'd'; choice++) {
            if (choice == correctChoice) {
                std::cout << choice << ") " << entry.second << " ";
            } else {
                auto wrongIter = vocabulary.begin();
                std::advance(wrongIter, wrongIndices.back());
                wrongIndices.pop_back();
                std::cout << choice << ") " << wrongIter->second << " ";
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
