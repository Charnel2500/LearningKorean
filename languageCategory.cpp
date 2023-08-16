#include "languageCategory.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <filesystem>
#include <SFML/Audio.hpp>

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

void LanguageCategory::gramatics() const {
    std::string word;
    int correctAnswers = 0;

    for (const auto& entry : vocabulary) {
        std::cout << "Napisz odpowiedni czasownik 이에요/예요: " << entry.first << "." << std::endl;
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

void LanguageCategory::playSound(const std::string& word) const {
    std::string soundFilePath = "sounds/" + word + ".wav";

    sf::SoundBuffer soundBuffer;
    if (!soundBuffer.loadFromFile(soundFilePath)) {
        std::cout << "Nie udało się załadować pliku dźwiękowego." << std::endl;
        return;
    }

    sf::Sound sound;
    sound.setBuffer(soundBuffer);
    sound.play();

    while (sound.getStatus() == sf::Sound::Playing) {
    }
}

void LanguageCategory::learnCategoryWithSound() const {
    std::string soundChoice;
    std::cout << "Czy chcesz odsłuchać dźwięk? (tak/nie): ";
    std::cin >> soundChoice;
    if (soundChoice == "tak") {
        std::string word;
        std::cout << "Podaj słowo, dla którego chcesz odsłuchać dźwięk: ";
        std::cin >> word;
        playSound(word);
    }
}
