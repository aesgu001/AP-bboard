#pragma once
// BBReply class interface

#include "bb-message.h"

class BBReply : public BBMessage
{
protected:
    /*
    *   Reads BBReply data from input stream.
    *
    *   @param in the input stream.
    * 
    *   @return True if the data being read is in proper format.
    */
    bool read(std::istream&) override;
    /*
    *   Writes BBReply data to output stream.
    *
    *   @param out the output stream.
    * 
    *   @return None.
    */
    void write(std::ostream&) const override;
public:
    // BBReply parameterized constructor
    BBReply(const std::string&, const std::string&, const std::size_t&);
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
