CC := g++

# Final target
EXE := main

# Source and build output directories
SRC_DIR := src
OBJ_DIR := obj

# Source files
SRC := $(wildcard $(SRC_DIR)/*.cpp)

# Object files
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Compiler flags
CFLAGS   := -std=c++11 -Wall -g -fopenmp -w -O3

.PHONY: all clean

all: $(EXE)

# Prerequisites for building executable
$(EXE): $(OBJ)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir $@

clean:
	rm -f $(OBJ) $(EXE)