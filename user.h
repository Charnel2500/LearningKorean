#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string firstName;
    std::string surname;
    int age;
    int points;

public:
    User();

    void setFirstName(const std::string& fName);
    void setSurname(const std::string& sName);
    void setAge(int userAge);
    void updatePoints(int newPoints);
    void displayWelcomeMessage() const;
};

#endif // USER_H

