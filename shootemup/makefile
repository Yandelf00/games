# Compiler
CXX = g++

# Directories
SRC_DIR = src
INCLUDE_DIR = $(SRC_DIR)/Include
LIB_DIR = $(SRC_DIR)/lib

# Source files
SRCS = main.cpp Game.cpp TextureManager.cpp GameObject.cpp Player.cpp Enemy.cpp SDLGameObject.cpp

# Output executable
TARGET = main

# Compiler flags
CXXFLAGS = -I$(INCLUDE_DIR) -L$(LIB_DIR)

# Libraries
LIBS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

# Default target
all: $(TARGET)

# Rule to build the target
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS) $(LIBS)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean up build files
clean:
	rm -f $(TARGET)

.PHONY: all run clean

# all:
# 	g++ -Isrc/Include -Lsrc/lib -o main main.cpp Game.cpp TextureManager.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

# run:
# 	./main