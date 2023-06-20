# Compiler
CXX := g++
# Compiler flags
CXXFLAGS := -std=c++17 -Wall -Wextra
# SFML libraries
LIBS := -lsfml-graphics -lsfml-window -lsfml-system
# Source files
SOURCES := $(wildcard *.cpp)
# Object files
OBJECTS := $(SOURCES:.cpp=.o)
# Output binary
TARGET := sfml-app

# Build rule
all: $(TARGET)

# Linking rule
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LIBS)

# Compilation rule
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJECTS) $(TARGET)