#pragma once
// BbUser class interface

// #include <iostream> // std::cout
#include <string>

class BbUser
{
private:
    std::string uname;  // ID name of the user.
    std::string passwd; // Password for accessing the user.
public:
    // BbUser parameterized constructor
    BbUser(std::string, std::string);
    // BbUser default constructor
    BbUser();
    // BbUser copy constructor
    BbUser(const BbUser&);
    // BbUser overloaded assignment operator
    BbUser& operator=(const BbUser&);
    // BbUser destructor
    ~BbUser();
    // BbUser username accessor
    const std::string &username() const;
    /*
    *   Checks if the username and password parameters match those of the object that called
    *   this function.
    * 
    *   @param username the string to compare with the object's username.
    *   @param password the string to compare with the object's password.
    * 
    *   @return True if both usernames and passwords are equivalent in length and characters.
    *           False if either username or string parameter is empty.
    */
    bool match(std::string, std::string) const;
};
