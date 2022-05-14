#pragma once

#include "bb-board.h"

#include <fstream>  // std::ifstream
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
*   Reads BBUser data from file to BBoard.
*
*   @param board the board to store data into.
*   @param userFile the text file to load from.
*
*   @return None.
*/
void loadUserData(BBoard&, const char *const&);

/*
*   Reads BBMessage data from file to BBoard.
*
*   @param board the board to store data into.
*   @param msgFile the text file to load from.
*
*   @return None.
*/
void loadMessageData(BBoard&, const char *const&);

/*
*   Reads a number option from standard input.
*
*   @param numOptions the number of options starting from 1.
*
*   @return A valid number option.
*/
int enterOption(const int&);

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
*   Assigns a registered user with the matching username and password inputs as the current user.
*
*   @param board the board to access user data from.
*
*   @return None.
*/
void login(BBoard&);

/*
*   Adds a new user object to the BBoard and sets it as the current user.
*
*   @param board the board to access user data from.
*
*   @return None.
*/
void registerUser(BBoard&);

/*
*   Writes a border line of characters to standard output.
*
*   @param borderChar the character to display.
*   @param borderLength the length of the line.
*
*   @return None.
*/
void drawBorderLine(const char&, const std::size_t&);

/*
*   Displays all of a message's replies, and their replies, to standard output.
*
*   @param replies the message's replies.
*   @param indentLength the length of whitespaces preceding the messages.
*
*   @return None.
*/
void displayReplies(const std::vector<BBMessage*>&, const std::size_t&);

/*
*   Display all of BBoard's messages to standard output. Each topic is separated by a line border.
*
*   @param board the board to access message data from.
*
*   @return None.
*/
void displayMessages(const BBoard&);

/*
*   Adds a new topic to the BBoard.
*
*   @param board the board to access message data from.
*
*   @return None.
*/
void addTopic(BBoard&);

/*
*   Adds a reply to a message in the BBoard
*
*   @param board board to access message data from.
*
*   @return None.
*/
void addReply(BBoard&);

/*
*   Opens a menu prompt with the following options: Login, Register, and Exit.
*
*   @param board the board to access user data from.
*   @param exitCalled flag to exit the program.
*
*   @return None.
*/
void runLogin(BBoard&, bool&);

/*
*   Opens a menu prompt with the following options: Display Messages, Add New Topic, Reply to a Message,
*   and Log Out.
*
*   @param board the board to access message data from.
*
*   @return None.
*/
void runMessage(BBoard&);

/*
*   Writes user data to file.
*
*   @param userFile text file to write to.
*
*   @return None.
*/
void writeUserData(BBoard&, const char *const&);

/*
*   Writes 0 or more reply data to output stream.
*
*   @param out output stream.
*   @param rcpID message recipient ID.
*   @param replies message replies.
*
*   @return None.
*/
void writeReplyData(std::ostream&, const std::size_t&, const std::vector<BBMessage*>&);

/*
*   Writes message data to file.
*
*   @param messageFile text file to write to.
*
*   @return None.
*/
void writeMessageData(BBoard&, const char *const&);

/*
*   Writes bboard data to user and message files.
*
*   @param board board to record.
*
*   @return None.
*/
void writeBBoardData(BBoard&);

/*
*   Launches the bulletin board (BBoard), enabling user login/registration and posting messages.
*
*   @param board the board to use.
*
*   @return None.
*/
void runBBoard(BBoard&);
