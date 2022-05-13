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

void loadUserData(BBoard &board, const char *const &userFile)
{
    std::ifstream in;
    BBUser user;

    std::cout << "Loading user data... ";
    in.open(userFile);
    if (!in.is_open())
    {
        std::cout << "ERROR! Failed to open " << userFile << "!\n";
        return;
    }

    while (in >> user)
    {
        board.loadUser(user);
    }

    in.close();
    if (!in.eof())
    {
        std::cout << "WARNING! Failed to load all users!\n";
    }
    else
    {
        std::cout << "Success!\n";
    }
}

void loadMessageData(BBoard &board, const char *const &msgFile)
{
    std::string messageType;
    std::ifstream in;
    BBTopic topic;
    BBReply reply;

    std::cout << "Loading message data... ";
    in.open(msgFile);
    if (!in.is_open())
    {
        std::cout << "ERROR! Failed to open " << msgFile << "!\n";
        return;
    }

    while (in >> messageType)
    {
        if (messageType == "Topic:")
        {
            if (!(in >> topic))
            {
                break;
            }

            board.loadTopic(topic);
        }
        else if (messageType == "Reply:")
        {
            if (!(in >> reply))
            {
                break;
            }

            board.loadReply(reply);
        }
    }

    in.close();
    if (!in.eof())
    {
        std::cout << "WARNING! Failed to load all messages!\n";
    }
    else
    {
        std::cout << "Success!\n";
    }
}

int enterOption(const int &numOptions)
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

void login(BBoard &board)
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

    if (board.login(username, password))
    {
        std::cout << "Welcome back, " << board.currUser()->username() << "!\n\n";
    }
    else
    {
        std::cout << "Incorrect username or password!\n\n";
    }
}

void registerUser(BBoard &board)
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

    if (board.registerUser(username, password))
    {
        std::cout << "Welcome, " << board.currUser()->username() << "!\n\n";
    }
    else
    {
        std::cout << "ERROR! Username " << username << " already exists!\n\n";
    }
}

void drawBorderLine(const char &borderChar, const std::size_t &borderLength)
{
    for (std::size_t i = 0; i < borderLength; ++i)
    {
        std::cout << borderChar;
    }
    std::cout << '\n';
}

void displayReplies(const std::vector<BBMessage*> &replies, const std::size_t &indentLength)
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

        if (!reply->replies().empty())
        {
            displayReplies(reply->replies(), indentLength + 1);
        }
    }
}

void displayMessages(const BBoard &board)
{
    std::cout << "DISPLAY MESSAGES\n";

    if (board.messages().empty())
    {
        std::cout << "There are no messages.\n\n";
        return;
    }

    for (BBMessage* const &message : board.messages())
    {
        if (!message->isReply())
        {          
            drawBorderLine('-', 100);
            std::cout   << "topic: " << dynamic_cast<BBTopic* const>(message)->subject() << '\n'
                        << '#' << message->id() << " "
                        << message->author() << ": " << message->body();
            if (!message->replies().empty())
            {
                std::cout << "\nreplies:";
                displayReplies(message->replies(), 0);
            }
            drawBorderLine('-', 100);
        }
        
    }

    std::cout << "End of messages.\n\n";
}

void addTopic(BBoard &board)
{
    std::string subject, body;
    std::cout << "ADD NEW TOPIC\n";
    
    std::cout << "Enter subject: ";
    subject = enterSubject();

    std::cout   << "Enter body.\n"
                << "Hit 'ENTER' twice to stop:\n";
    body = enterBody();

    board.addTopic(subject, body);
    std::cout << "Added new topic \"" << subject << "\" to " << board.title() << ".\n\n";
}

void addReply(BBoard &board)
{
    int msgID = 0;
    std::string body;
    BBMessage *message = nullptr;

    std::cout << "REPLY TO A MESSAGE\n";

    if (board.messages().empty())
    {
        std::cout << "There are no messages.\n\n";
        return;
    }

    std::cout << "Enter message ID# (0 to cancel): ";
    while (!readInteger(msgID) || static_cast<std::size_t>(msgID) > board.messages().size())
    {
        std::cout << "ERROR! Please enter an existing message ID#: ";
    }

    if (msgID <= 0)
    {
        std::cout << '\n';
        return;
    }
    message = board.messages()[msgID - 1];

    drawBorderLine('-', 100);
    std::cout   << "message #" << msgID << '\n'
                << message->author() << ": " << message->body();
    drawBorderLine('-', 100);

    std::cout   << "Enter body.\n"
                << "Hit 'ENTER' twice to stop:\n";
    body = enterBody();

    board.addReply(message, body);
    std::cout << "Added reply to message #" << msgID << ".\n\n";
}

void runLogin(BBoard &board, bool &exitCalled)
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
        login(board);
    }
    else if (option == 2)
    {
        registerUser(board);
    }
    else // option == 3
    {
        exitCalled = true;
    }
}

void runMessage(BBoard &board)
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
        displayMessages(board);
    }
    else if (option == 2)
    {
        addTopic(board);
    }
    else if (option == 3)
    {
        addReply(board);
    }
    else // option == 4
    {
        std::cout << "Logging " << board.currUser()->username() << " out...\n\n";
        board.logout();
    }
}

void runBBoard(BBoard &board)
{
    bool exitCalled = false;
    std::cout << "Welcome to " << board.title() << "!\n\n";

    while (!exitCalled)
    {
        if (!board.currUser())
        {
            runLogin(board, exitCalled);
        }
        else
        {
            runMessage(board);
        }
    }

    // TODO: saveBBoardData(board);
    std::cout << "Goodbye!\n";
}

/*      DRIVER CODE     */
int main(int argc, char **argv)
{
    BBoard board("AP Bulletin Board");
    if (argc == 2)
    {
        loadUserData(board, argv[1]);
        std::cout << '\n';
    }
    else if (argc == 3)
    {
        std::cout   << "ERROR! Invalid call! Program usage:\n\n"
                    << argv[0] << "\n\n"
                    << argv[0] << " <user data>.txt\n\n"
                    << argv[0] << " <user data>.txt <message data>.txt <message table>.txt\n\n";
        return 1; 
    }
    else if (argc == 4)
    {
        loadUserData(board, argv[1]);
        loadMessageData(board, argv[2]);
        // TODO: loadMessageTable(board, argv[3]);
        std::cout << '\n';
    }
    runBBoard(board);
    return 0;
}
