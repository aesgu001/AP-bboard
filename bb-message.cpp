// BBMessage class implementation

#include "bb-message.h"

// std::size_t BBMessage::_memory = 0;

BBMessage::BBMessage(std::string author, std::string body) :
    _author(author), _body(body)
{}

BBMessage::BBMessage() : BBMessage("", "")
{}

BBMessage::BBMessage(const BBMessage &rhs) : BBMessage(rhs._author, rhs._body)
{}

BBMessage& BBMessage::operator=(const BBMessage &rhs)
{
    if (this != &rhs)
    {
        this->_author = rhs._author;
        this->_body = rhs._body;
    }

    return *this;
}

/*void* BBMessage::operator new(std::size_t size)
{
    _memory += size;
    std::cout   << "Allocated: " << size << " bytes\n"
                << "Memory usage: " << _memory << " bytes\n";
    return ::operator new(size);
}*/

/*void BBMessage::operator delete(void* ptr, std::size_t size)
{
    _memory -= size;
    std::cout   << "Freed: " << size << " bytes\n"
                << "Memory usage: " << _memory << " bytes\n";
    ::operator delete(ptr);
}*/

BBMessage::~BBMessage()
{}

const std::string& BBMessage::author() const
{
    return this->_author;
}

const std::string& BBMessage::body() const
{
    return this->_body;
}
