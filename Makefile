# Variables
CXX = clang++
CXXFLAGS = -std=c++11 -I ./includes
EXEC = pong

SRC =	src/main.cpp \
		src/Ball/Ball.cpp src/Paddle/Paddle.cpp src/Paddle/CpuPaddle.cpp \
		src/run_game.cpp

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
    LDFLAGS = -lm -lpthread -ldl -lrt -lX11
	LIBS = lib/libraylib_linux.a
else ifeq ($(UNAME_S), Darwin)
    LDFLAGS = -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
	LIBS = lib/libraylib_macos.a
else ifeq ($(OS), Windows_NT)
    LDFLAGS = -lraylib -lopengl32 -lgdi32 -lwinmm
endif

all: $(EXEC)

$(EXEC): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(EXEC) $(LDFLAGS) $(LIBS)

clean:
	rm -f $(EXEC)

re: clean all

run: all
	./$(EXEC)

.PHONY: all clean run
