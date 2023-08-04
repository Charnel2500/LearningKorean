#include <iostream>
#include <unordered_map>
#include <string>

class User {
private:
    std::string firstName;
    std::string surname;
    int age;
    int points;

public:
    User() : firstName(""), surname(""), age(0), points(0) {}

    void setFirstName(const std::string& fName) {
        firstName = fName;
    }

    void setSurname(const std::string& sName) {
        surname = sName;
    }

    void setAge(int userAge) {
        age = userAge;
    }

    void updatePoints(int newPoints) {
        points += newPoints;
    }

    void displayWelcomeMessage() const {
        std::cout << "Aplikacja do nauki języka koreańskiego. Możesz się wiele nauczyć!" << std::endl;
        std::cout << "Witaj " << firstName << "! Cieszę się, że skorzystałeś z kursu języka koreańskiego. Mam nadzieję, że wiele się nauczysz!" << std::endl;
        std::cout << "Na początek potrzebuję twoich danych, żeby zapisywać twoje postępy." << std::endl;
        std::cout << "Twój wiek to: " << age << ". Dopiero zaczynasz, więc masz " << points << " punktów, ale z czasem będziesz ich mieć więcej." << std::endl;
    }
};

class LanguageCategory {
private:
    std::unordered_map<std::string, std::string> vocabulary;

public:
    LanguageCategory(const std::unordered_map<std::string, std::string>& words) : vocabulary(words) {}

    void displayWords() const {
        for (const auto& entry : vocabulary) {
            std::cout << "Polski: " << entry.first << " | Koreański: " << entry.second << std::endl;
        }
    }

    void testCategory() const {
        std::string word;
        int correctAnswers = 0;

        for (const auto& entry : vocabulary) {
            std::cout << "Napisz wyraz po koreańsku dla: " << entry.first << " | Polski: " << std::endl;
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
};

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

    std::cout << "Czy jesteś gotów/gotowa do testu? (1 - tak, 0 - nie): ";
    std::cin >> choice;

    if (choice == 1) {
        switch (choice) {
            case 1:
                family.testCategory();
                break;
            case 2:
                seasons.testCategory();
                break;
            case 3:
                bodyPart.testCategory();
                break;
        }
    } else {
        std::cout << "Dziękuję za skorzystanie z aplikacji." << std::endl;
    }

    return 0;
}
