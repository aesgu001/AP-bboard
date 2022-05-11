// BBTopic class implementation

#include "bb-topic.h"

BBTopic::BBTopic(const std::string &subject, const std::string &author, const std::string &body,
    const std::size_t &id) : BBMessage(author, body, id), _subject(subject)
{}

BBTopic::BBTopic() : BBTopic("", "", "", 0)
{}

BBTopic::BBTopic(const BBTopic &rhs) : BBTopic(rhs._subject, rhs.author(), rhs.body(), rhs.id())
{}

BBTopic& BBTopic::operator=(const BBTopic &rhs)
{
    if (this != &rhs)
    {
        this->BBMessage::operator=(rhs);
        this->_subject = rhs._subject;
    }

    return *this;
}

BBTopic::~BBTopic()
{}

const std::string &BBTopic::subject() const
{
    return this->_subject;
}

bool BBTopic::isReply() const
{
    return false;
}
