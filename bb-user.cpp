// BbUser class implementation

#include "bb-user.h"

BbUser::BbUser(std::string name, std::string password) : uname(name), passwd(password)
{}

BbUser::BbUser() : BbUser("", "")
{}

BbUser::BbUser(const BbUser &rhs) : BbUser(rhs.uname, rhs.passwd)
{}

BbUser::~BbUser()
{}

BbUser& BbUser::operator=(const BbUser &rhs)
{
    if (this != &rhs)
    {
        this->uname = rhs.uname;
        this->passwd = rhs.passwd;
    }

    return *this;
}

/*int main()
{
    BbUser testEmpty;   // Default
    BbUser testUser("JohnnySilverhand", "Samurai2077"); // Parameterized
    BbUser testCopy(testUser);  // Copy

    BbUser testAssign;
    testAssign = testUser;  // Assignment
    testAssign = testAssign;    // Self-assignment

    return 0;
}*/
