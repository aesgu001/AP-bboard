#include "bb-main.h"

std::string readLine()
{
    std::string line;
    std::getline(std::cin, line, '\n');

    return line;
}

bool readInteger(int &stInt)
{
    std::string numStr;
    while (numStr.empty())
    {
        numStr = readLine();
    }
    
    for (char c : numStr)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }

    stInt = std::stoi(numStr);

    return true;
}

bool readSingleWordString(std::string &stString)
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
        std::cout << numLine << ".  ";
        ++numLine;

        line = readLine();
        if (!line.empty())
        {
            body += line + '\n';
        }
    }

    return body;
}

int enterOption(int numOptions)
{
    int option = 0;

    std::cout << "Enter option: ";
    while (!readInteger(option) || option <= 0 || option > numOptions)
    {
        std::cout << "ERROR! Please enter a valid option: ";
    }   
    std::cout << "\n";

    return option;
}

void login(const std::vector<BbUser> &users, const BbUser* &currUser)
{
    std::string username, password;
    std::cout << "Enter username: ";
    while (!readSingleWordString(username))
    {
        std::cout << "ERROR! Please enter a one-word username: ";
    }

    std::cout << "Enter password: ";
    while (!readSingleWordString(password))
    {
        std::cout << "ERROR! Please enter a one-word password: ";
    }

    for (const BbUser &user : users)
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

void registerUser(std::vector<BbUser> &users, const BbUser* &currUser)
{
    std::string username, password;
    std::cout << "Enter new username: ";
    while (!readSingleWordString(username))
    {
        std::cout << "ERROR! Please enter a one-word username: ";
    }

    std::cout << "Enter new password: ";
    while (!readSingleWordString(password))
    {
        std::cout << "ERROR! Please enter a one-word password: ";
    }

    for (const BbUser &user : users)
    {
        if (user.username() == username)
        {
            std::cout << "ERROR! Username " << username << " already exists!\n\n";

            return;
        }
    }

    // Set new user object at the end of the list as the current user
    users.push_back(BbUser(username, password));
    currUser = &users[users.size() - 1];
    std::cout << "Welcome, " << currUser->username() << "!\n\n";
}

void drawBorderLine(char borderChar, int borderLength)
{
    for (int i = 0; i < borderLength; ++i)
    {
        std::cout << borderChar;
    }
    std::cout << '\n';
}

void displayMessages(const std::vector<BbMessage> &messages)
{
    std::cout << "DISPLAY MESSAGES\n";

    if (messages.empty())
    {
        std::cout << "There are no messages.\n\n";
        return;
    }

    for (const BbMessage &message : messages)
    {
        drawBorderLine('-', 100);
        std::cout   << "topic: " << message.subject() << '\n'
                    << message.author() << ": " << message.body();
        drawBorderLine('-', 100);
    }

    std::cout << "End of messages.\n\n";
}

void addTopic(const BbUser* &currUser, std::vector<BbMessage> &messages)
{
    std::string subject, body;

    std::cout << "ADD NEW TOPIC\n";
    
    std::cout << "Enter subject: ";
    subject = enterSubject();

    std::cout   << "Enter body.\n"
                << "Hit 'ENTER' twice to stop:\n";
    body = enterBody();

    messages.push_back(BbMessage(currUser->username(), subject, body));
    std::cout << "Added new topic \"" << subject << "\" to AP Bulletin Board.\n\n";
}

void runLogin(bool &exitCalled, std::vector<BbUser> &users, const BbUser* &currUser)
{
    int option = 0;
    std::cout   << "LOGIN MENU\n"
                << "(1) Login\n"
                << "(2) Register\n"
                << "(3) Exit\n\n";
    option = enterOption(3);

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

void runMessage(const BbUser* &currUser, std::vector<BbMessage> &messages)
{
    int option = 0;
    std::cout   << "MESSAGE MENU\n"
                << "(1) Display Messages\n"
                << "(2) Add New Topic\n"
                << "(3) Reply to a Message\n"
                << "(4) Log Out\n\n";
    option = enterOption(4);

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
        // TODO: addReply
        std::cout << "REPLY TO A MESSAGE\n\n";
    }
    else // option == 4
    {
        std::cout << "Logging " << currUser->username() << " out...\n\n";
        currUser = nullptr;
    }
}

void runBboard()
{
    std::vector<BbUser> users;
    const BbUser* currUser = nullptr;

    std::vector<BbMessage> messages;

    bool exitCalled = false;

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
}

int main()
{
    runBboard();

    return 0;
}
