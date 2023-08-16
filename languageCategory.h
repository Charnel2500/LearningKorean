#ifndef LANGUAGECATEGORY_H
#define LANGUAGECATEGORY_H

#include <unordered_map>
#include <string>

class LanguageCategory {
private:
    std::unordered_map<std::string, std::string> vocabulary;

public:
    LanguageCategory(const std::unordered_map<std::string, std::string>& words);

    void displayWords() const;
    void testWriteWordsKorean() const;
    void testWriteWordsPolish() const;
    void testClosedTask() const;
    void gramatics() const;
    void playSound(const std::string& word) const;
    void learnCategoryWithSound() const;
};

#endif // LANGUAGECATEGORY_H

