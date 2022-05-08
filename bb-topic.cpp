// BBTopic class implementation

#include "bb-topic.h"

BBTopic::BBTopic(std::string subject, std::string author, std::string body, std::size_t id,
    const std::vector<BBMessage*> &replies) : BBMessage(author, body, id, replies), _subject(subject)
{}

BBTopic::BBTopic() : BBTopic("", "", "", 0, std::vector<BBMessage*>())
{}

BBTopic::BBTopic(const BBTopic &rhs) : BBTopic(rhs._subject, rhs.author(), rhs.body(), rhs.id(),
    rhs.replies())
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

const std::string& BBTopic::subject() const
{
    return this->_subject;
}

bool BBTopic::isReply() const
{
    return false;
}
