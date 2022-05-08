// BBMessage class implementation

#include "bb-message.h"

// std::size_t BBMessage::_memory = 0;

BBMessage::BBMessage(std::string author, std::string body, std::size_t id,
    const std::vector<BBMessage*> &replies) : _author(author), _body(body), _id(id), _replies(replies)
{}

BBMessage::BBMessage() : BBMessage("", "", 0, std::vector<BBMessage*>())
{}

BBMessage::BBMessage(const BBMessage &rhs) : BBMessage(rhs._author, rhs._body, rhs._id, rhs._replies)
{}

BBMessage& BBMessage::operator=(const BBMessage &rhs)
{
    if (this != &rhs)
    {
        this->_author = rhs._author;
        this->_body = rhs._body;
        this->_id = rhs._id;
        this->_replies = rhs._replies;
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

const std::size_t& BBMessage::id() const
{
    return this->_id;
}

const std::vector<BBMessage*>& BBMessage::replies() const
{
    return this->_replies;
}

void BBMessage::addReply(BBMessage* const &reply)
{
    this->_replies.push_back(reply);
}
