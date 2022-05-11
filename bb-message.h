#pragma once
// BBMessage class interface

#include <string>
#include <vector>
// #include <iostream> // std::cout, DEBUG

class BBMessage
{
private:
    // static std::size_t _memory;      // Keeps track of currently allocated memory
    std::string _author;                // Author of the message.
    std::string _body;                  // Message text body.
    std::size_t _id;                    // ID number of the message.
    std::vector<BBMessage*> _replies;   // Replies to the message. 
public:
    // BBMessage parameterized constructor
    BBMessage(const std::string&, const std::string&, const std::size_t&);
    // BBMessage default constructor
    BBMessage();
    // BBMessage copy constructor
    BBMessage(const BBMessage&);
    // BBMessage overloaded assignment operator
    BBMessage &operator=(const BBMessage&);
    // BBMessage overloaded new operator
    // void *operator new(std::size_t);
    // BBMessage overloaded delete operator
    // void operator delete(void*, std::size_t);
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
