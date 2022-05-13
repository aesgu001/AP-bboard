// BBTopic class implementation

#include "bb-topic.h"

const std::string BEGIN = "<begin_BBTopic>";    // BBTopic begin string limiter.
const std::string END = "<end_BBTopic>";        // BBTopic end string limiter.

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

bool BBTopic::read(std::istream &in)
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

    // Remove newline character from buffer to read subject
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (!std::getline(in, this->_subject))
    {
        return false;
    }
    
    else if (!(in >> end) || end != END)
    {
        return false;
    }

    return true;
}

void BBTopic::write(std::ostream &out) const
{
    out << BEGIN << '\n';
    this->BBMessage::write(out);
    out << '\n'
        << this->_subject << '\n'
        << END;
}

bool BBTopic::isReply() const
{
    return false;
}
