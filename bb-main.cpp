#include "bb-main.h"

std::string readLine()
{
    std::string line;
    std::getline(std::cin, line, '\n');
    return line;
}

bool readInteger(int &stInt)
{
    std::string intStr;
    while (intStr.empty())
    {
        intStr = readLine();
    }
    
    for (std::size_t i = 0; i < intStr.length(); ++i)
    {
        // Allow negative integer values
        if (i <= 0 && (intStr[i] == '-' || intStr[i] == '+'))
        {
            continue;
        }

        if (!isdigit(static_cast<int>(intStr[i])))
        {
            return false;
        }
    }

    stInt = std::stoi(intStr);
    return true;
}

bool readString(std::string &stString)
{
    std::string str;
    while (str.empty())
    {
        str = readLine();
    }

    for (char c : str)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            return false;
        }
    }

    stString = str;
    return true;
}

int enterOption(int numOptions)
{
    int option = 0;
    std::cout << "Enter option: ";
    while (!readInteger(option) || option <= 0 || option > numOptions)
    {
        std::cout << "ERROR! Please enter a valid option: ";
    }

    return option;
}

std::string enterSubject()
{
    std::string subject;
    while (subject.empty())
    {
        subject = readLine();
    }

    return subject;
}

std::string enterBody()
{
    int numLine = 1;
    std::string body, line;

    while (body.empty() || !line.empty())
    {
        std::cout << numLine++ << ".  ";
        line = readLine();
        if (!line.empty())
        {
            body += line + '\n';
        }
    }

    return body;
}

void login(const std::vector<BBUser> &users, const BBUser* &currUser)
{
    std::string username, password;
    std::cout << "Enter username: ";
    while (!readString(username))
    {
        std::cout << "ERROR! Please enter a one-word username: ";
    }

    std::cout << "Enter password: ";
    while (!readString(password))
    {
        std::cout << "ERROR! Please enter a one-word password: ";
    }

    for (const BBUser &user : users)
    {
        if (user.match(username, password))
        {
            currUser = &user;
            std::cout << "Welcome back, " << currUser->username() << "!\n\n";
            return;
        }
    }

    std::cout << "Incorrect username or password!\n\n";
}

void registerUser(std::vector<BBUser> &users, const BBUser* &currUser)
{
    std::string username, password;
    std::cout << "Enter new username: ";
    while (!readString(username))
    {
        std::cout << "ERROR! Please enter a one-word username: ";
    }

    std::cout << "Enter new password: ";
    while (!readString(password))
    {
        std::cout << "ERROR! Please enter a one-word password: ";
    }

    for (const BBUser &user : users)
    {
        if (user.username() == username)
        {
            std::cout << "ERROR! Username " << username << " already exists!\n\n";
            return;
        }
    }

    // Set new user at the end of the list as current user
    users.push_back(BBUser(username, password));
    currUser = &users[users.size() - 1];
    std::cout << "Welcome, " << currUser->username() << "!\n\n";
}

void drawBorderLine(char borderChar, std::size_t borderLength)
{
    for (std::size_t i = 0; i < borderLength; ++i)
    {
        std::cout << borderChar;
    }
    std::cout << '\n';
}

void displayReplies(const std::vector<BBMessage*> &replies, std::size_t indentLength)
{
    std::string indent;
    for (std::size_t i = 0; i < indentLength; ++i)
    {
        indent += "  ";
    }

    for (BBMessage* const &reply : replies)
    {
        std::string body = reply->body();
        std::size_t bodyLength = body.length();
        std::vector<BBMessage*> subReplies = reply->replies();

        std::cout   << '\n' << indent << '#' << reply->id() << " "
                    << reply->author() << ": ";
        for (std::size_t i = 0; i < bodyLength; ++i)
        {
            char c = body[i];
            std::cout << c;
            // No indent after the last newline character
            if (c == '\n' && i + 1 < bodyLength)
            {
                std::cout << indent;
            }
        }

        if (!subReplies.empty())
        {
            displayReplies(subReplies, indentLength + 1);
        }
    }
}

void displayMessages(const std::vector<BBMessage*> &messages)
{
    std::cout << "DISPLAY MESSAGES\n";

    if (messages.empty())
    {
        std::cout << "There are no messages.\n\n";
        return;
    }

    for (BBMessage* const &message : messages)
    {
        if (!message->isReply())
        {
            std::vector<BBMessage*> replies = message->replies();

            drawBorderLine('-', 100);
            std::cout   << "topic: " << dynamic_cast<BBTopic* const>(message)->subject() << '\n'
                        << '#' << message->id() << " "
                        << message->author() << ": " << message->body();
            if (!replies.empty())
            {
                std::cout << "\nreplies:";
                displayReplies(replies, 0);
            }
            drawBorderLine('-', 100);
        }
        
    }

    std::cout << "End of messages.\n\n";
}

void addTopic(const BBUser* &currUser, std::vector<BBMessage*> &messages)
{
    std::string subject, body;
    BBMessage *topic = nullptr;

    std::cout << "ADD NEW TOPIC\n";
    
    std::cout << "Enter subject: ";
    subject = enterSubject();

    std::cout   << "Enter body.\n"
                << "Hit 'ENTER' twice to stop:\n";
    body = enterBody();

    topic = new BBTopic(subject, currUser->username(), body, messages.size() + 1,
        std::vector<BBMessage*>());
    messages.push_back(topic);
    std::cout << "Added new topic \"" << subject << "\" to AP Bulletin Board.\n\n";
}

void addReply(const BBUser* &currUser, std::vector<BBMessage*> &messages)
{
    int msgID = 0;
    std::string body;
    BBMessage *message = nullptr;
    BBMessage *reply = nullptr;

    std::cout << "REPLY TO A MESSAGE\n";

    if (messages.empty())
    {
        std::cout << "There are no messages.\n\n";
        return;
    }

    std::cout << "Enter message ID# (0 to cancel): ";
    while (!readInteger(msgID) || static_cast<std::size_t>(msgID) > messages.size())
    {
        std::cout << "ERROR! Please enter an existing message ID#: ";
    }

    if (msgID <= 0)
    {
        std::cout << '\n';
        return;
    }
    message = messages[msgID - 1];

    drawBorderLine('-', 100);
    std::cout   << "message #" << msgID << '\n'
                << message->author() << ": " << message->body();
    drawBorderLine('-', 100);

    std::cout   << "Enter body.\n"
                << "Hit 'ENTER' twice to stop:\n";
    body = enterBody();

    reply = new BBReply(currUser->username(), body, messages.size() + 1, std::vector<BBMessage*>());
    messages.push_back(reply);
    message->addReply(reply);
    std::cout << "Added reply to message #" << msgID << ".\n\n";
}

void runLogin(bool &exitCalled, std::vector<BBUser> &users, const BBUser* &currUser)
{
    int option = 0;
    std::cout   << "LOGIN MENU\n"
                << "(1) Login\n"
                << "(2) Register\n"
                << "(3) Exit\n\n";
    option = enterOption(3);
    std::cout << '\n';

    if (option == 1)
    {
        login(users, currUser);
    }
    else if (option == 2)
    {
        registerUser(users, currUser);
    }
    else // option == 3
    {
        exitCalled = true;
    }
}

void runMessage(const BBUser* &currUser, std::vector<BBMessage*> &messages)
{
    int option = 0;
    std::cout   << "MESSAGE MENU\n"
                << "(1) Display Messages\n"
                << "(2) Add New Topic\n"
                << "(3) Reply to a Message\n"
                << "(4) Log Out\n\n";
    option = enterOption(4);
    std::cout << '\n';

    if (option == 1)
    {
        displayMessages(messages);
    }
    else if (option == 2)
    {
        addTopic(currUser, messages);
    }
    else if (option == 3)
    {
        addReply(currUser, messages);
    }
    else // option == 4
    {
        std::cout << "Logging " << currUser->username() << " out...\n\n";
        currUser = nullptr;
    }
}

void runBBoard()
{
    bool exitCalled = false;
    const BBUser* currUser = nullptr;
    std::vector<BBUser> users;
    std::vector<BBMessage*> messages; 

    std::cout << "Welcome to AP Bulletin Board!\n\n";

    while (!exitCalled)
    {
        if (!currUser)
        {
            runLogin(exitCalled, users, currUser);
        }
        else
        {
            runMessage(currUser, messages);
        }
    }

    std::cout << "Goodbye!\n";

    for (BBMessage* &message : messages)
    {
        delete message;
        message = nullptr;
    }
}

/*      DRIVER CODE     */
int main()
{
    runBBoard();
    return 0;
}
