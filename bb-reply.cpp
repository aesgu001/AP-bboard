// BBReply class implementation

#include "bb-reply.h"

const std::string BEGIN = "<begin_BBReply>";    // BBReply begin string limiter.
const std::string END = "<end_BBReply>";        // BBReply end string limiter.

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

bool BBReply::read(std::istream &in)
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
    else if (!this->BBMessage::read(in))
    {
        return false;
    }
    else if (!(in >> end) || end != END)
    {
        return false;
    }

    return true;
}

void BBReply::write(std::ostream &out) const
{
    out << BEGIN << '\n';
    this->BBMessage::write(out);
    out << '\n'
        << END;
}

bool BBReply::isReply() const
{
    return true;
}
