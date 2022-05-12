// BBUser class implementation

#include "bb-user.h"

const std::string BEGIN = "<begin_BBUser>";  // BBUser begin string limiter.
const std::string END = "<end_BBUser>";      // BBUser end string limiter.

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

bool BBUser::read(std::istream &in)
{
    std::string begin, end;
    if (!(in >> begin))
    {
        // End-of-file is still a successful read
        if (in.eof())
        {
            return true;
        }

        return false;
    }
    else if (begin != BEGIN)
    {
        return false;
    }
    else if (!(in >> this->_username) || !(in >> this->_password))
    {
        return false;
    }
    else if (!(in >> end) || end != END)
    {
        return false;
    }

    return true;
}

void BBUser::write(std::ostream &out) const
{
    out << BEGIN << '\n'
        << this->_username << '\n'
        << this->_password << '\n'
        << END;
}

std::istream &operator>>(std::istream &in, BBUser &obj)
{
    if (!obj.read(in))
    {
        // Get buffer error state
        std::istream::iostate state = in.rdstate();

        // Set fail state to 1 and end-of-file state to 0
        state |= std::istream::failbit;
        state &= ~std::istream::eofbit;

        // Modify state
        in.clear(state);
    }

    return in;
}

std::ostream &operator<<(std::ostream &out, const BBUser &obj)
{
    obj.write(out);
    return out;
}

bool BBUser::match(const std::string &username, const std::string &password) const
{
    if (username.empty() || password.empty())
    {
        return false;
    }

    return this->_username == username && this->_password == password;
}
