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

void runLogin(bool &exitCalled, std::vector<BbUser> &users, BbUser **currUser)
{
    int option = 0;
    std::cout   << "LOGIN MENU\n"
                << "(1) Login\n"
                << "(2) Register\n"
                << "(3) Exit\n\n";
    option = enterOption(3);

    if (option == 1)
    {
        // TODO: login
        std::cout << "Login\n\n";
    }
    else if (option == 2)
    {
        // TODO: register
        std::cout << "Register\n\n";
    }
    else // option == 3
    {
        exitCalled = true;
    }
}

void runBboard()
{
    std::vector<BbUser> users;
    BbUser* currUser = nullptr;

    bool exitCalled = false;

    std::cout << "Welcome to AP Bulletin Board!\n\n";

    while (!exitCalled)
    {
        if (!currUser)
        {
            runLogin(exitCalled, users, &currUser);
        }
        else
        {
            // TODO: runMessage
        }
    }

    std::cout << "Goodbye!\n";
}

int main()
{
    runBboard();

    return 0;
}
