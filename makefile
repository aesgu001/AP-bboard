# Compiler
CC = g++

# Compiler flags
CFLAGS = -g -Wall -Werror

# Target executable
TARGET = AP-bboard

# Object files
OBJ = bb-main.o bb-user.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

bb-main.o: bb-user.o bb-main.h bb-main.cpp
	$(CC) $(CFLAGS) -c bb-main.cpp

bb-user.o: bb-user.h bb-user.cpp
	$(CC) $(CFLAGS) -c bb-user.cpp

clean:
	$(RM) $(TARGET) $(OBJ)
	