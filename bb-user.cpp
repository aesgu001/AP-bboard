// BBUser class implementation

#include "bb-user.h"

BBUser::BBUser(const std::string &username, const std::string &password) : _username(username),
    _password(password)
{}

BBUser::BBUser() : BBUser("", "")
{}

BBUser::BBUser(const BBUser &rhs) : BBUser(rhs._username, rhs._password)
{}

BBUser &BBUser::operator=(const BBUser &rhs)
{
    if (this != &rhs)
    {
        this->_username = rhs._username;
        this->_password = rhs._password;
    }
    
    return *this;
}

BBUser::~BBUser()
{}

const std::string &BBUser::username() const
{
    return this->_username;
}

bool BBUser::match(const std::string &username, const std::string &password) const
{
    if (username.empty() || password.empty())
    {
        return false;
    }

    return this->_username == username && this->_password == password;
}
