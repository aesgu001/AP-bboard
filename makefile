# Compiler
CC = g++

# Compiler flags
CFLAGS = -g -Wall -Werror

# Target executable
TARGET = AP-bboard

# Object files
OBJ = bb-main.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

bb-main.o: bb-main.h bb-main.cpp
	$(CC) $(CFLAGS) -c bb-main.cpp

clean:
	$(RM) $(TARGET) $(OBJ)