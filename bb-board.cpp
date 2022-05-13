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
        delete message;
        message = nullptr;
    }
}

const std::string &BBoard::title() const
{
    return this->_title;
}

const BBUser *const &BBoard::currUser() const
{
    return this->_currUser;
}

const std::vector<BBMessage*> &BBoard::messages() const
{
    return this->_messages;
}

void BBoard::loadUser(const BBUser &obj)
{
    this->_users.push_back(obj);
}

void BBoard::loadTopic(const BBTopic &obj)
{
    BBMessage *message = new BBTopic(obj.subject(), obj.author(), obj.body(), obj.id());
    this->_messages.push_back(message);
}

void BBoard::loadReply(const BBReply &obj)
{
    BBMessage *message = new BBReply(obj.author(), obj.body(), obj.id());
    this->_messages.push_back(message);
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
