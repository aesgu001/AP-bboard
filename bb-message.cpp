// BBMessage class implementation

#include "bb-message.h"

BBMessage::BBMessage(std::string author, std::string subject, std::string body) :
_author(author), _subject(subject), _body(body)
{}

BBMessage::BBMessage() : BBMessage("", "", "")
{}

BBMessage::BBMessage(const BBMessage &rhs) : BBMessage(rhs._author, rhs._subject, rhs._body)
{}

BBMessage& BBMessage::operator=(const BBMessage &rhs)
{
    if (this != &rhs)
    {
        this->_author = rhs._author;
        this->_subject = rhs._subject;
        this->_body = rhs._body;
    }

    return *this;
}

BBMessage::~BBMessage()
{}

const std::string& BBMessage::author() const
{
    return this->_author;
}

const std::string& BBMessage::subject() const
{
    return this->_subject;
}

const std::string& BBMessage::body() const
{
    return this->_body;
}
