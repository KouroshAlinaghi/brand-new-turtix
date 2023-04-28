C_FLAGS=-std=c++11 -Wall -Wextra
L_FLAGS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lstdc++fs
SRCS=$(wildcard src/*.cpp)
HEADERS=$(wildcard src/*.hpp)
OBJS=$(subst .cpp,.o,$(SRCS))

all: turtix run

run:
	bin/turtix

turtix: $(OBJS)
	g++ $(OBJS) -o bin/turtix $(L_FLAGS) 

%.o: %.cpp $(HEADERS)
	g++ $(C_FLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJS)
