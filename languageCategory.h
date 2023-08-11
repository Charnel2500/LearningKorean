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
    void testWriteWords() const;
    void testClosedTask() const;
};

#endif // LANGUAGECATEGORY_H

