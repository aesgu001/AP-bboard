// BbUser class interface

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
};
