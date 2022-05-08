// BBReply class implementation

#include "bb-reply.h"

BBReply::BBReply(std::string author, std::string body, std::size_t id,
    const std::vector<BBMessage*> &replies) : BBMessage(author, body, id, replies)
{}

BBReply::BBReply() : BBReply("", "", 0, std::vector<BBMessage*>())
{}

BBReply::BBReply(const BBReply &rhs) : BBReply(rhs.author(), rhs.body(), rhs.id(), rhs.replies())
{}

BBReply& BBReply::operator=(const BBReply &rhs)
{
    if (this != &rhs)
    {
        this->BBMessage::operator=(rhs);
    }

    return *this;
}

BBReply::~BBReply()
{}

bool BBReply::isReply() const
{
    return true;
}
