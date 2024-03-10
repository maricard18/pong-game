# Variables
CXX = clang++
CXXFLAGS = -std=c++11 -I ./includes
LDFLAGS = -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
LIBS = lib/libraylib.a
EXEC = pong

SRC =	src/main.cpp \
		src/Ball/Ball.cpp src/Paddle/Paddle.cpp src/Paddle/CpuPaddle.cpp \
		src/run_game.cpp

all: $(EXEC)

$(EXEC): $(SRC)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(LIBS) $^ -o $@

clean:
	rm -f $(EXEC)

re: clean all

run: all
	./$(EXEC)

.PHONY: all clean run