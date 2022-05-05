#include "bb-user.h"
// #include "bb-user.cpp"

#include <iostream> // std::cin/cout
#include <vector>   // std::vector

/*
*   Reads a string line from standard input.
*
*   @return A string of zero or more words.
*/
std::string readLine();

/*
*   Stores an integer converted from string input.
*
*   @param stInt variable to store the integer value.
*
*   @return True if the function converts the string successfully.
*/
bool readInteger(int&);

/*
*   Reads a number option from standard input.
*
*   @param numOptions the number of valid options starting from 1.
*
*   @return A valid number option.
*/
int enterOption(int);

/*
*   Opens a menu prompt with the following options: Login, Register, and Exit.
*
*   @param exitCalled flag to exit the program.
*
*   @return None.
*/
void runLogin(bool&, std::vector<BbUser>&, BbUser**);

/*
*   Launches the bulletin board, enabling user login/registration and posting messages.
*
*   @return None.
*/
void runBboard();
