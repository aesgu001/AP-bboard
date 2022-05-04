// BbUser class implementation

#include "bb-user.h"

BbUser::BbUser(std::string username, std::string password) : uname(username), passwd(password)
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

const std::string& BbUser::username() const
{
    return this->uname;
}

bool BbUser::match(std::string username, std::string password) const
{
    if (username.empty() || password.empty())
    {
        return false;
    }

    return (this->uname == username) && (this->passwd == password);
}

/*int main()
{
    BbUser testEmpty;   // Default

    BbUser testUser1("JSilverhand", "Samurai2077"); // Parameterized
    BbUser testUser2("V-Hero", "Cyberpunk2077");    // Parameterized

    BbUser testCopy(testUser1); // Copy

    BbUser testAssign;
    testAssign = testUser2;     // Assignment
    testAssign = testAssign;    // Self-assignment

    std::cout << "testCopy.username() = " << testCopy.username() << "\n";       // JSilverhand
    std::cout << "testAssign.username() = " << testAssign.username() << "\n\n"; // V-Hero

    std::cout   << "testCopy.match('JSilverhand', 'Samurai2077') = "
                << testCopy.match("JSilverhand", "Samurai2077") << "\n";            // 1 or true
    std::cout   << "testAssign.match('Jackie', 'Cyberpunk2077') = "
                << testAssign.match("Jackie", "Cyberpunk2077") << "\n";             // 0 or false
    std::cout   << "testAssign.match('V-Hero', 'BigLeagues2077') = "
                << testAssign.match("V-Hero", "BigLeagues2077") << "\n";            // 0 or false
    std::cout   << "testEmpty.match('', '') = " << testEmpty.match("", "") << "\n"; // 0 or false

    return 0;
}*/
