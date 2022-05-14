// BBoard class implementation

#include "bb-board.h"

BBoard::BBoard(const std::string &title) : _title(title), _currUser(nullptr),
    _users(std::vector<BBUser>()), _messages(std::vector<BBMessage*>())
{}

BBoard::BBoard() : BBoard("BBoard")
{}

BBoard::BBoard(const BBoard &rhs) : BBoard(rhs._title)
{}

BBoard &BBoard::operator=(const BBoard &rhs)
{
    if (this != &rhs)
    {
        this->_title = rhs._title;
    }

    return *this;
}

BBoard::~BBoard()
{
    for (BBMessage* &message : this->_messages)
    {
        if (message)
        {
            delete message;
            message = nullptr;
        }
    }

    // Clear vector to prevent re-access
    this->_messages.clear();
}

const std::string &BBoard::title() const
{
    return this->_title;
}

const BBUser *const &BBoard::currUser() const
{
    return this->_currUser;
}

const std::vector<BBUser> &BBoard::users() const
{
    return this->_users;
}

const std::vector<BBMessage*> &BBoard::messages() const
{
    return this->_messages;
}

bool BBoard::loadUser(const BBUser &obj)
{
    // Check if user already exists in BBoard
    for (const BBUser &user : this->_users)
    {
        if (obj.username() == user.username())
        {
            return false;
        }
    }

    // Add user to BBoard
    this->_users.push_back(obj);
    return true;
}

bool BBoard::loadTopic(const BBTopic &obj)
{
    // Expand vector size to match object id
    if (obj.id() > this->_messages.size())
    {
        this->_messages.resize(this->_messages.size() + obj.id(), nullptr);

        // Allocate memory for topic message
        this->_messages[obj.id() - 1] = new BBTopic(obj);
        return true;
    }
    // Check if message at index is NULL
    else if (!this->_messages[obj.id() - 1])
    {
        this->_messages[obj.id() - 1] = new BBTopic(obj);
        return true;
    }

    return false;
}

bool BBoard::loadReply(const BBReply &obj, const std::size_t &rcpID)
{
    // Message recipient must have a lesser ID# (rcp ID)
    if (rcpID >= obj.id())
    {
        return false;
    }
    // rcp ID < vector size
    else if (rcpID > this->_messages.size())
    {
        return false;
    }
    // Message at rcp ID must not be NULL
    else if (!this->_messages[rcpID - 1])
    {
        return false;
    }
    // Expand vector size to match object id
    else if (obj.id() > this->_messages.size())
    {
        this->_messages.resize(this->_messages.size() + obj.id(), nullptr);

        // Allocate memory for reply message
        this->_messages[obj.id() - 1] = new BBReply(obj);

        // Add reply to message recipient
        this->_messages[rcpID - 1]->addReply(this->_messages[obj.id() - 1]);
        return true;
    }
    // Check if message at index is NULL
    else if (!this->_messages[obj.id() - 1])
    {
        // Allocate memory for reply message
        this->_messages[obj.id() - 1] = new BBReply(obj);

        // Add reply to message recipient
        this->_messages[rcpID - 1]->addReply(this->_messages[obj.id() - 1]);
        return true;
    }

    return false;
}

bool BBoard::login(const std::string &username, const std::string &password)
{
    for (const BBUser &user : this->_users)
    {
        if (user.match(username, password))
        {
            this->_currUser = &user;
            return true;
        }
    }

    return false;
}

bool BBoard::registerUser(const std::string &username, const std::string &password)
{
    for (const BBUser &user : this->_users)
    {
        if (user.username() == username)
        {
            return false;
        }
    }

    // Set new user at the end of the list as current user
    this->_users.push_back(BBUser(username, password));
    this->_currUser = &this->_users[this->_users.size() - 1];
    return true;
}

void BBoard::addTopic(const std::string &subject, const std::string &body)
{
    if (this->_currUser)
    {
        BBMessage *topic = new BBTopic(subject, this->_currUser->username(), body,
            this->_messages.size() + 1);
        this->_messages.push_back(topic);
    }
}

void BBoard::addReply(BBMessage *const &message, const std::string &body)
{
    if (this->_currUser)
    {
        // Check if the target message is in this BBoard first
        for (BBMessage *const &msg : this->_messages)
        {
            if (msg == message)
            {
                BBMessage *reply = new BBReply(this->_currUser->username(), body,
                    this->_messages.size() + 1);
                this->_messages.push_back(reply);
                message->addReply(reply);
                return;
            }
        }
    }
}

void BBoard::logout()
{
    this->_currUser = nullptr;
}
