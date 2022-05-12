// BBMessage class implementation

#include "bb-message.h"

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
