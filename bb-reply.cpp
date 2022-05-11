// BBReply class implementation

#include "bb-reply.h"

BBReply::BBReply(const std::string &author, const std::string &body, const std::size_t &id) :
    BBMessage(author, body, id)
{}

BBReply::BBReply() : BBReply("", "", 0)
{}

BBReply::BBReply(const BBReply &rhs) : BBReply(rhs.author(), rhs.body(), rhs.id())
{}

BBReply &BBReply::operator=(const BBReply &rhs)
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
