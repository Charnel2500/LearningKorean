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
    
    LanguageCategory presentTense({
        {"저는 중국 사람", "이에요"},
        {"제 직업은 가수", "예요"},
        {"저는 학생.", "이에요"},
        {"여기가 집", "이에요"},
        {"강아지가 귀엽", "이에요"},
        {"나는 선생님", "이에요"},
        {"나는 의사", "예요"}
    }); 

    std::string firstName, surname, password;
    int age, choiceLogin;
    std::cout << "Chcesz się zalogować to wybierz 1, jeśli chcesz się zarejestrować to wybierz 2. Możesz też zresetować hasło wybierając opcję 3." << std::endl;
    std::cin >> choiceLogin;
    if (choiceLogin == 1)
    {
        user.loginUser();
    }
    else if (choiceLogin == 2)
    {
        user.registerUser();
    }
    else if (choiceLogin == 3)
    {
        user.resetPassword();
    }    
    else
    {
        std::cout << "Niepoprawna opcja, spróbuj ponownie. Jeśli chcesz się zalogować to wybierz 1, jeśli chcesz się zarejestrować to wybierz 2" << std::endl;
    }

    user.displayWelcomeMessage();
    
    int mainChoice = 0;

    while (mainChoice != 7) {
        std::cout << "Wybierz co chcesz zrobić (1 - nauczyć się, 2 - test jednokrotnego wyboru, 3 - test pisania słów po koreańsku, 4 - test tłumaczenia na polski, 5 - gramatyka, 6 - odsłuchanie nagrań, 7 - wyjście): ";
        std::cin >> mainChoice;

        switch (mainChoice) {
            case 1:
            {
                int categoryChoice;
                std::cout << "Wybierz kategorię do nauki (1 - rodzina, 2 - pory roku, 3 - części ciała): ";
                std::cin >> categoryChoice;
                switch (categoryChoice) {
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
                }
                break;
            }
            case 2:
            {
                int categoryChoice;
                std::cout << "Wybierz kategorię do testu wyboru (1 - rodzina, 2 - pory roku, 3 - części ciała): ";
                std::cin >> categoryChoice;
                switch (categoryChoice) {
                    case 1:
                        family.testClosedTask();
                        break;
                    case 2:
                        seasons.testClosedTask();
                        break;
                    case 3:
                        bodyPart.testClosedTask();
                        break;
                    default:
                        std::cout << "Niepoprawny wybór." << std::endl;
                }
                break;
            }
            case 3:
            {
                int categoryChoice;
                std::cout << "Wybierz kategorię do testu pisania słów po koreańsku (1 - rodzina, 2 - pory roku, 3 - części ciała): ";
                std::cin >> categoryChoice;
                switch (categoryChoice) {
                    case 1:
                        family.testWriteWordsKorean();
                        break;
                    case 2:
                        seasons.testWriteWordsKorean();
                        break;
                    case 3:
                        bodyPart.testWriteWordsKorean();
                        break;
                    default:
                        std::cout << "Niepoprawny wybór." << std::endl;
                }
                break;
            }
            case 4:
            {
                int categoryChoice;
                std::cout << "Wybierz kategorię do testu pisania słów po polsku (1 - rodzina, 2 - pory roku, 3 - części ciała): ";
                std::cin >> categoryChoice;
                switch (categoryChoice) {
                    case 1:
                    {
                        family.testWriteWordsPolish();
                        
                        break;
                    }
                    case 2:
                    {
                        seasons.testWriteWordsPolish();
                        break;
                    }
                    case 3:
                    {
                        bodyPart.testWriteWordsPolish();
                        break;
                    }
                    default:
                        std::cout << "Niepoprawny wybór." << std::endl;
                }
                break;
            }
            case 5:
            {
                int categoryChoice;
                std::cout << "Wybierz kategorię do nauki gramatyki (1 - czas teraźniejszy): ";
                std::cin >> categoryChoice;
                switch (categoryChoice) {
                    case 1:
                        presentTense.gramatics();
                        break;
                    default:
                        std::cout << "Niepoprawny wybór." << std::endl;
                }
                break;
            }
            case 6:
            {
                int categoryChoice;
                std::cout << "Wybierz kategorię do odsłuchania słów po koreańsku (1 - rodzina, 2 - pory roku, 3 - części ciała): ";
                std::cin >> categoryChoice;
                switch (categoryChoice) {
                    case 1:
                    {
                        family.displayWords();
                        family.learnCategoryWithSound();
                        break;
                    }
                    case 2:
                    {
                        seasons.displayWords();
                        seasons.learnCategoryWithSound();
                        break;
                    }
                    case 3:
                    {
                        bodyPart.displayWords();
                        bodyPart.learnCategoryWithSound();
                    }
                        break;
                    default:
                        std::cout << "Niepoprawny wybór." << std::endl;
                }
                break;
            }
            case 7:
                std::cout << "Dziękuję za skorzystanie z aplikacji." << std::endl;
                break;
            default:
                std::cout << "Niepoprawny wybór." << std::endl;
        }
    }


    return 0;
}
