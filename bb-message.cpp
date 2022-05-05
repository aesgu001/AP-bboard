// BbMessage class implementation

#include "bb-message.h"

// #include <iostream>

BbMessage::BbMessage(std::string author, std::string subject, std::string body) :
authr(author), subj(subject), bdy(body)
{}

BbMessage::BbMessage() : BbMessage("", "", "")
{}

BbMessage::BbMessage(const BbMessage &rhs) : BbMessage(rhs.authr, rhs.subj, rhs.bdy)
{}

BbMessage& BbMessage::operator=(const BbMessage &rhs)
{
    if (this != &rhs)
    {
        this->authr = rhs.authr;
        this->subj = rhs.subj;
        this->bdy = rhs.bdy;
    }

    return *this;
}

BbMessage::~BbMessage()
{}

const std::string& BbMessage::author() const
{
    return this->authr;
}

const std::string& BbMessage::subject() const
{
    return this->subj;
}

const std::string& BbMessage::body() const
{
    return this->bdy;
}

/*void displayMessage(const BbMessage& message)
{
    std::cout   << "Subject: " << message.subject() << "\n\n"
                << message.author() << ": "
                << message.body() << "\n\n";
}*/

/*int main()
{
    BbMessage emptyMessage;

    BbMessage paramMessage1("LIT", "New Music Video", "Check out our new music video coming this week!");
    BbMessage paramMessage2("pirateking", "RE: New Music Video", "Rockin'! Easily top of the charts ^_^");

    BbMessage copyMessage(paramMessage1);

    BbMessage assignMessage;
    assignMessage = paramMessage2;
    assignMessage = assignMessage;

    displayMessage(copyMessage);
    displayMessage(assignMessage);

    return 0;
}*/
