# Compiler
CC = g++

# Compiler flags
CFLAGS = -g -Wall -Werror

# Target executable
TARGET = AP-bboard

# Object files
OBJ = bb-main.o bb-user.o bb-message.o bb-topic.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

bb-main.o: bb-user.o bb-topic.o bb-main.h bb-main.cpp
	$(CC) $(CFLAGS) -c bb-main.cpp

bb-user.o: bb-user.h bb-user.cpp
	$(CC) $(CFLAGS) -c bb-user.cpp

bb-topic.o: bb-message.o bb-topic.h bb-topic.cpp
	$(CC) $(CFLAGS) -c bb-topic.cpp

bb-message.o: bb-message.h bb-message.cpp
	$(CC) $(CFLAGS) -c bb-message.cpp

clean:
	$(RM) $(TARGET) $(OBJ)
	