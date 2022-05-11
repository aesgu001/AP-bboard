#pragma once
// BBTopic class interface

#include "bb-message.h"

class BBTopic : public BBMessage
{
private:
    std::string _subject;   // Subject of the message.
public:
    // BBTopic parameterized constructor
    BBTopic(const std::string&, const std::string&, const std::string&, const std::size_t&);
    // BBTopic default constructor
    BBTopic();
    // BBTopic copy constructor
    BBTopic(const BBTopic&);
    // BBTopic overloaded assignment operator
    BBTopic &operator=(const BBTopic&);
    // BBTopic destructor
    ~BBTopic();
    // BBTopic subject accessor
    const std::string &subject() const;
    /*
    *   Checks if the message is a reply.
    *
    *   @return False.
    */
    bool isReply() const override;
};
