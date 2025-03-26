.PHONY: all clean

APP = Main
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -g -I.
SRC = $(APP).cpp Matrix.cpp
OBJ = $(SRC:.cpp=.o)

all: $(APP)

$(APP): $(OBJ)
	$(CXX) -o $(APP) $(OBJ) $(CXXFLAGS)

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	rm -f $(APP) $(OBJ)