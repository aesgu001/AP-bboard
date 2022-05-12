#pragma once
// BBUser class interface

#include <iostream> // std::istream, std::ostream, std::string

class BBUser
{
private:
    std::string _username;  // ID name of the user.
    std::string _password;  // Password for accessing the user.
    /*
    *   Reads BBUser data from input stream.
    *
    *   @param in the input stream.
    * 
    *   @return True if the data being read is in proper format.
    */
    bool read(std::istream&);
    /*
    *   Writes BBUser data to output stream.
    *
    *   @param out the output stream.
    * 
    *   @return None.
    */
    void write(std::ostream&) const;
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
    // BBUser overloaded istream operator
    friend std::istream &operator>>(std::istream&, BBUser&);
    // BBUser overloaded ostream operator
    friend std::ostream &operator<<(std::ostream&, const BBUser&);
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
