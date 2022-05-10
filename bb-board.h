#pragma once
// BBoard class interface

#include "bb-reply.h"
#include "bb-topic.h"
#include "bb-user.h"

class BBoard
{
private:
    std::string _title;                 // Title of the BBoard.
    const BBUser *_currUser;            // User logged in to the BBoard.
    std::vector<BBUser> _users;         // List of registered users.
    std::vector<BBMessage*> _messages;  // List of posted messages.
public:
    // BBoard parameterized constructor
    BBoard(std::string);
    // BBoard default constructor
    BBoard();
    // BBoard copy constructor
    BBoard(const BBoard&);
    // BBoard overloaded assignment operator
    BBoard &operator=(const BBoard&);
    // BBoard destructor
    ~BBoard();
    // BBoard title accessor
    const std::string &title() const;
    // BBoard current user accessor
    const BBUser *const &currUser() const;
    // BBoard messages accessor
    const std::vector<BBMessage*> &messages() const;
    /*
    *   Assigns a registered user with the matching username and password parameters as the
    *   current user.
    *
    *   @param username entered username.
    *   @param password entered password.
    * 
    *   @return True if a user with data matching the parameters exist.
    */
    bool login(std::string, std::string);
    /*
    *   Adds a new user object to the BBoard and sets it as the current user.
    *
    *   @param username entered username.
    *   @param password entered password.
    * 
    *   @return True if the new user has a unique username ID.
    */
    bool registerUser(std::string, std::string);
    /*
    *   Adds a new topic message to the BBoard.
    *
    *   @param subject subject of the message.
    *   @param body text body of the message.
    * 
    *   @return None.
    */
    void addTopic(std::string, std::string);
    /*
    *   Adds a new reply to a message in the BBoard.
    *
    *   @param message message to reply to.
    *   @param body text body of the reply.
    * 
    *   @return None.
    */
    void addReply(BBMessage *const &message, std::string);
    /*
    *   Logs the current user out of BBoard.
    *
    *   @return None.
    */
    void logout();
};
