#pragma once
// BBTopic class interface

#include "bb-message.h"

class BBTopic : public BBMessage
{
private:
    std::string _subject;   // Subject of the message.
public:
    // BBTopic parameterized constructor
    BBTopic(std::string, std::string, std::string, std::size_t, const std::vector<BBMessage*>&);
    // BBTopic default constructor
    BBTopic();
    // BBTopic copy constructor
    BBTopic(const BBTopic&);
    // BBMessage overloaded assignment operator
    BBTopic &operator=(const BBTopic&);
    // BBTopic destructor
    ~BBTopic();
    // BBMessage subject accessor
    const std::string &subject() const;
    /*
    *   Checks if the message is a reply.
    *
    *   @return False.
    */
    bool isReply() const override;
};
