// BBMessage class implementation

#include "bb-message.h"

// std::size_t BBMessage::_memory = 0;

BBMessage::BBMessage(const std::string &author, const std::string &body, const std::size_t &id) :
    _author(author), _body(body), _id(id), _replies(std::vector<BBMessage*>())
{}

BBMessage::BBMessage() : BBMessage("", "", 0)
{}

BBMessage::BBMessage(const BBMessage &rhs) : BBMessage(rhs._author, rhs._body, rhs._id)
{}

BBMessage& BBMessage::operator=(const BBMessage &rhs)
{
    if (this != &rhs)
    {
        this->_author = rhs._author;
        this->_body = rhs._body;
        this->_id = rhs._id;
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

const std::string &BBMessage::author() const
{
    return this->_author;
}

const std::string &BBMessage::body() const
{
    return this->_body;
}

const std::size_t &BBMessage::id() const
{
    return this->_id;
}

const std::vector<BBMessage*> &BBMessage::replies() const
{
    return this->_replies;
}

void BBMessage::addReply(BBMessage* const &reply)
{
    this->_replies.push_back(reply);
}
