#pragma once
// BBMessage class interface

#include <string>

class BBMessage
{
private:
    std::string _author;    // Author of the message.
    std::string _subject;   // Subject of the message.
    std::string _body;      // Message body.
public:
    // BBMessage parameterized constructor
    BBMessage(std::string, std::string, std::string);
    // BBMessage default constructor
    BBMessage();
    // BBMessage copy constructor
    BBMessage(const BBMessage&);
    // BBMessage overloaded assignment operator
    BBMessage& operator=(const BBMessage&);
    // BBMessage destructor
    ~BBMessage();
    // BBMessage author accessor
    const std::string &author() const;
    // BBMessage subject accessor
    const std::string &subject() const;
    // BBMessage body accessor
    const std::string &body() const;
};
