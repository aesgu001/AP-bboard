# AP-bboard
A simple [Bulletin Board System (BBS)](https://www.techtarget.com/whatis/definition/bulletin-board-system-BBS/) that utilizes the command prompt to register or log in 
users, as well as add or respond to message posts. This program can either launch a fresh, new bulletin board or load it with users and messages by reading data from 
two files. While running, *AP-bboard* opens a list of actions users can specify through the menu interface.

![](https://github.com/aesgu001/AP-bboard/blob/main/img/cover.jpeg)
## Login/Registration
Only those registered to *AP-bboard* are authorized to use the messaging system. Registration simply requires two things for authentication: a username and a password. 
Users that have been granted access can log back in using those credentials. Demo link [here](https://github.com/aesgu001/AP-bboard/blob/main/docs/Login.md).
## View/Post Messages with Structured Formatting
After giving access to the messaging system, *AP-bboard* allows users to post new topics, reply to topics, and even reply to replies. The display feature implemented 
in the program follows a formatting style similar to *Reddit* posts for easy viewing. Message posts also show their ID#'s that can be used to specify which post to 
respond to. Demo link [here](https://github.com/aesgu001/AP-bboard/blob/main/docs/Message.md).
## Data Saving and Loading
*AP-bboard* can store user and message data by writing them into a text file. It can also read from the same file to restore them after restarting the application.
Demo link [here](https://github.com/aesgu001/AP-bboard/blob/main/docs/Data.md).
## Build and Usage
**Note**: The GNU C++ compiler package must be installed in order to generate the application.

Building takes 4 steps using the Linux terminal:
```
git clone https://github.com/aesgu001/AP-bboard.git
cd AP-bboard
git checkout v1.0.0
make
```
There are 3 possible ways to run the application; example user and message text files are also provided in the repository:
```
# Without loading data
./AP-bboard

# Loading user data
./AP-bboard <user-data>.txt

# Loading user and message data
./AP-bboard <user-data>.txt <messages-data>.txt
```
