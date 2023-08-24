#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

class User {
private:
    std::string firstName;
    std::string surname;
    std::string password;
    int age;
    int points;

public:
    User();
    User(const std::string& fName, const std::string& sName, const std::string& userPassword, int userAge, int userPoints);
    void setFirstName(const std::string& fName);
    void setSurname(const std::string& sName);
    void setPassword(const std::string& userPassword);
    void setAge(int userAge);
    void updatePoints(int newPoints);
    void registerUser();
    bool loginUser();
    std::string encryptMessage(const std::string& message, int shift);
    std::string decryptMessage(const std::string& message, int shift);
    void displayWelcomeMessage() const;
    void resetPassword();
    bool compareByPoints(const User& user1, const User& user2);
    void displayTopUsers(const std::vector<User>& users, int count) const;
};

#endif // USER_H



