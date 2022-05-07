#pragma once
// BBMessage class interface

#include <string>
// #include <iostream> // std::cout, DEBUG

class BBMessage
{
private:
    // static std::size_t _memory;  // Keeps track of currently allocated memory
    std::string _author;            // Author of the message.
    std::string _body;              // Message body.
public:
    // BBMessage parameterized constructor
    BBMessage(std::string, std::string);
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
    /*
    *   Checks if the message is a reply.
    *
    *   @return True if the caller is an instance of Reply.
    */
    virtual bool isReply() const = 0;
};
