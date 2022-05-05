#pragma once
// BbMessage class interface

#include <string>

class BbMessage
{
private:
    std::string authr;  // Author of the message.
    std::string subj;   // Subject of the message.
    std::string bdy;    // Message body.
public:
    // BbMessage parameterized constructor
    BbMessage(std::string, std::string, std::string);
    // BbMessage default constructor
    BbMessage();
    // BbMessage copy constructor
    BbMessage(const BbMessage&);
    // BbMessage overloaded assignment operator
    BbMessage& operator=(const BbMessage&);
    // BbMessage destructor
    ~BbMessage();
    // BbMessage author accessor
    const std::string &author() const;
    // BbMessage subject accessor
    const std::string &subject() const;
    // BbMessage body accessor
    const std::string &body() const;
};
