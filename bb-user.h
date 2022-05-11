#pragma once
// BBUser class interface

#include <string>

class BBUser
{
private:
    std::string _username;  // ID name of the user.
    std::string _password;  // Password for accessing the user.
public:
    // BBUser parameterized constructor
    BBUser(const std::string&, const std::string&);
    // BBUser default constructor
    BBUser();
    // BBUser copy constructor
    BBUser(const BBUser&);
    // BBUser overloaded assignment operator
    BBUser &operator=(const BBUser&);
    // BBUser destructor
    ~BBUser();
    // BBUser username accessor
    const std::string &username() const;
    /*
    *   Checks if the username and password parameters match those of the object that called
    *   this function.
    * 
    *   @param username the string to compare with the object's username.
    *   @param password the string to compare with the object's password.
    * 
    *   @return True if both usernames and passwords are equivalent in length and characters.
    *           False if either username or password parameter is empty.
    */
    bool match(const std::string&, const std::string&) const;
};
