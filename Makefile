
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Iinclude -g -Isrc
SRC = src/main.cpp src/glad.c src/graphics/renderer.cpp src/graphics/renderobject.cpp src/engine/engine_loop.cpp
LIBS = -lglfw -ldl
OUT = app

all:
	$(CXX) $(CXXFLAGS) $(SRC) $(LIBS) -o $(OUT)

clean:
	rm -f $(OUT)

