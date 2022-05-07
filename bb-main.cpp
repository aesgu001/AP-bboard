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

void drawBorderLine(char borderChar, int borderLength)
{
    for (int i = 0; i < borderLength; ++i)
    {
        std::cout << borderChar;
    }
    std::cout << '\n';
}

void displayMessages(const std::vector<BBMessage> &messages)
{
    std::cout << "DISPLAY MESSAGES\n";

    if (messages.empty())
    {
        std::cout << "There are no messages.\n\n";
        return;
    }

    for (const BBMessage &message : messages)
    {
        drawBorderLine('-', 100);
        std::cout   << "topic: " << message.subject() << '\n'
                    << message.author() << ": " << message.body();
        drawBorderLine('-', 100);
    }

    std::cout << "End of messages.\n\n";
}

void addTopic(const BBUser* &currUser, std::vector<BBMessage> &messages)
{
    std::string subject, body;
    std::cout << "ADD NEW TOPIC\n";
    
    std::cout << "Enter subject: ";
    subject = enterSubject();

    std::cout   << "Enter body.\n"
                << "Hit 'ENTER' twice to stop:\n";
    body = enterBody();

    messages.push_back(BBMessage(currUser->username(), subject, body));
    std::cout << "Added new topic \"" << subject << "\" to AP Bulletin Board.\n\n";
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

void runMessage(const BBUser* &currUser, std::vector<BBMessage> &messages)
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
        // TODO: addReply
        std::cout << "REPLY TO A MESSAGE\n\n";
    }
    else // option == 4
    {
        std::cout << "Logging " << currUser->username() << " out...\n\n";
        currUser = nullptr;
    }
}

void runBBoard()
{
    std::vector<BBUser> users;
    const BBUser* currUser = nullptr;

    std::vector<BBMessage> messages;

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

/*      DRIVER CODE     */
int main()
{
    runBBoard();
    return 0;
}
