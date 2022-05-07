#pragma once

#include "bb-user.h"
#include "bb-message.h"

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
*   Stores a one-word string from standard input.
*
*   @param stString variable to store the string.
*
*   @return True if the string does not contain a whitespace, tab, or newline character.
*/
bool readString(std::string&);

/*
*   Reads a number option from standard input.
*
*   @param numOptions the number of options starting from 1.
*
*   @return A valid number option.
*/
int enterOption(int);

/*
*   Reads a subject string from standard input.
*
*   @return A non-empty string.
*/
std::string enterSubject();

/*
*   Reads a body string from standard input. After entering at least 1 non-empty string line, hit
*   'ENTER' two consecutive times to stop.
*
*   @return A non-empty string with 1 or more lines.
*/
std::string enterBody();

/*
*   Assigns a registered user with the matching username and password inputs as the Bboard's
*   current user.
*
*   @return None.
*/
void login(const std::vector<BBUser>&, const BBUser*&);

/*
*   Adds a new user object to the Bboard and sets it as the current user.
*
*   @return None.
*/
void registerUser(std::vector<BBUser>&, const BBUser*&);

/*
*   Writes a border line of characters to standard output.
*
*   @param borderChar the character to display.
*   @param borderLength the length of the line.
*
*   @return None.
*/
void drawBorderLine(char, int);

/*
*   Display all of Bboard's messages to standard output. Each topic is separated by a line border.
*
*   @return None.
*/
void displayMessages(const std::vector<BBMessage>&);

/*
*   Adds a new topic to the Bboard.
*
*   @return None.
*/
void addTopic(const BBUser*&, std::vector<BBMessage>&);

/*
*   Opens a menu prompt with the following options: Login, Register, and Exit.
*
*   @param exitCalled flag to exit the program.
*
*   @return None.
*/
void runLogin(bool&, std::vector<BBUser>&, const BBUser*&);

/*
*   Opens a menu prompt with the following options: Display Messages, Add New Topic, Reply to a Message,
*   and Log Out.
*
*   @return None.
*/
void runMessage(const BBUser*&, std::vector<BBMessage>&);

/*
*   Launches the bulletin board, enabling user login/registration and posting messages.
*
*   @return None.
*/
void runBBoard();
