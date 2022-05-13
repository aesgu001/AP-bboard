// BBMessage class implementation

#include "bb-message.h"

const std::string BEGIN = "<begin_BBMessage>";          // BBMessage begin string limiter.
const std::string BODY_BEGIN = "<begin_std::string>";   // BBMessage body begin string limiter.
const std::string END = "<end_BBMessage>";              // BBMessage end string limiter.
const std::string BODY_END = "<end_std::string>";       // BBMessage body end string limiter.

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

bool BBMessage::read(std::istream &in)
{
    std::string begin, end;
    std::string bodyBegin, bodyNext;

    if (!(in >> begin) || begin != BEGIN)
    {
        return false;
    }
    else if (!(in >> this->_author))
    {
        return false;
    }
    else if (!(in >> bodyBegin) || bodyBegin != BODY_BEGIN)
    {
        return false;
    }

    // Remove newline character from buffer to read body text
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // Overwrite body text
    this->_body = "";
    while (std::getline(in, bodyNext) && bodyNext != BODY_END)
    {
        this->_body += bodyNext + '\n';
    }

    if (this->_body.empty() || bodyNext != BODY_END)
    {
        return false;
    }
    else if (!(in >> this->_id))
    {
        return false;
    }
    // TODO: this->_replies
    if (!(in >> end) || end != END)
    {
        return false;
    }

    return true;
}

void BBMessage::write(std::ostream &out) const
{
    out << BEGIN << '\n'
        << this->_author << '\n'
        << BODY_BEGIN << '\n'
        << this->_body
        << BODY_END << '\n'
        << this->_id << '\n'
        // TODO: this->_replies
        << END;
}

std::istream &operator>>(std::istream &in, BBMessage &obj)
{
    if (!obj.read(in))
    {
        // Get buffer error state
        std::istream::iostate state = in.rdstate();

        // Set fail state to 1 and end-of-file state to 0
        state |= std::istream::failbit;
        state &= ~std::istream::eofbit;

        // Modify state
        in.clear(state);
    }

    return in;
}

std::ostream &operator<<(std::ostream &out, const BBMessage &obj)
{
    obj.write(out);
    return out;
}

void BBMessage::addReply(BBMessage* const &reply)
{
    this->_replies.push_back(reply);
}
