#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_map<std::string, std::string> family = {
        {"dziadek", "할아버지"},
        {"babcia", "할머니"},
        {"matka", "어머니"},
        {"ojciec", "아버지"},
        {"żona", "아내"},
        {"mąż", "남편"},
        {"córka", "딸"},
        {"son", "아들"}
    };
    
    
    std::unordered_map<std::string, std::string> seasons = {
        {"wiosna", "봄"},
        {"lato", "여름"},
        {"jesień", "가을"},
        {"zima", "겨울"}
    };
    
    std::unordered_map<std::string, std::string> bodyPart = {
        {"głowa", "머리"},
        {"ręka", "손"},
        {"noga", "다리"},
        {"twarz", "얼굴"},
        {"oko", "눈"},
        {"ucho", "귀"}
    };
    
    
    std::cout << "Aplikacja do nauki jezyka koreanskiego." << std::endl;
    std::cout << "Wybierz kategorie do nauki (1 - rodzina, 2 - pory roku, 3 - czesci ciala." << std::endl;
    int wybor=0;
    std::cin >> wybor;
    if (wybor == 1)
    {
        std::cout << "Wybrales kategorie 1 - rodzina" << std::endl;
        for (const auto& entry : family) {
            std::cout << "Polski: " << entry.first << " | Koreański: " << entry.second << std::endl;
        }
    }
    if (wybor == 2)
    {
        std::cout << "Wybrales kategorie 2 - pory roku" << std::endl;
        for (const auto& entry : seasons) {
            std::cout << "Polski: " << entry.first << " | Koreański: " << entry.second << std::endl;
        }
    }
    if (wybor == 3)
    {
        std::cout << "Wybrales kategorie 3 - czesci ciala" << std::endl;
        for (const auto& entry : bodyPart) {
            std::cout << "Polski: " << entry.first << " | Koreański: " << entry.second << std::endl;
        }
    }
    return 0;
}
