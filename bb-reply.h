#pragma once
// BBReply class interface

#include "bb-message.h"

class BBReply : public BBMessage
{
public:
    // BBReply parameterized constructor
    BBReply(std::string, std::string, std::size_t, const std::vector<BBMessage*>&);
    // BBReply default constructor
    BBReply();
    // BBReply copy constructor
    BBReply(const BBReply&);
    // BBReply overloaded assignment operator
    BBReply &operator=(const BBReply&);
    // BBReply destructor
    ~BBReply();
    /*
    *   Checks if the message is a reply.
    *
    *   @return True.
    */
    bool isReply() const override;
};
