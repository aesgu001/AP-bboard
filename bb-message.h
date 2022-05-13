#pragma once
// BBMessage class interface

#include <iostream> // std::istream, std::ostream, std::string
#include <limits>   // std::numeric_limits
#include <vector>   // std::vector

class BBMessage
{
private:
    std::string _author;                // Author of the message.
    std::string _body;                  // Message text body.
    std::size_t _id;                    // ID number of the message.
    std::vector<BBMessage*> _replies;   // Replies to the message.
protected:
    /*
    *   Reads BBMessage data from input stream.
    *
    *   @param in the input stream.
    * 
    *   @return True if the data being read is in proper format.
    */
    virtual bool read(std::istream&);
    /*
    *   Writes BBMessage data to output stream.
    *
    *   @param out the output stream.
    * 
    *   @return None.
    */
    virtual void write(std::ostream&) const;
public:
    // BBMessage parameterized constructor
    BBMessage(const std::string&, const std::string&, const std::size_t&);
    // BBMessage default constructor
    BBMessage();
    // BBMessage copy constructor
    BBMessage(const BBMessage&);
    // BBMessage overloaded assignment operator
    BBMessage &operator=(const BBMessage&);
    // BBMessage destructor
    virtual ~BBMessage();
    // BBMessage author accessor
    const std::string &author() const;
    // BBMessage body accessor
    const std::string &body() const;
    // BBMessage ID accessor
    const std::size_t &id() const;
    // BBMessage replies accessor
    const std::vector<BBMessage*> &replies() const;
    // BBMessage overloaded istream operator
    friend std::istream &operator>>(std::istream&, BBMessage&);
    // BBMessage overloaded ostream operator
    friend std::ostream &operator<<(std::ostream&, const BBMessage&);
    /*
    *   Checks if the message is a reply.
    *
    *   @return True if the caller is an instance of Reply.
    */
    virtual bool isReply() const = 0;
    /*
    *   Adds a reply to the message. This method, however, does not dynamically allocate memory for
    *   BBMessage. 
    *
    *   @param reply the message responding to the caller.
    * 
    *   @return None.
    */
    void addReply(BBMessage* const&);
};
