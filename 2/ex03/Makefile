CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3
TARGET = a.out
SRC = main.cpp
SRC += Fixed.cpp
SRC += Point.cpp
SRC += bsp.cpp
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all