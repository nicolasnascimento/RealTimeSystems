# Declaration of variables
CC = g++
CC_FLAGS = -std=c++11 -Wall
LD_FLAGS = -lm

# File names
EXEC = run
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

# Main Target
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) $(CC_FLAGS) -o $(EXEC) $(LD_FLAGS)

# To obtain object files
%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@

# To remove generated files
clean: 
	rm -f $(EXEC) $(OBJECTS)
