
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Iinclude -g -Isrc 
SRC = src/main.cpp src/glad.c src/graphics/Graphics.cpp src/ecs/components/renderobject.cpp src/engine/engine.cpp src/graphics/shaders.cpp src/ecs/spawner/spawner.cpp src/ecs/spawner/entities/* src/shape/shape.cpp
LIBS = -lglfw -ldl
OUT = app

all:
	$(CXX) $(CXXFLAGS) $(SRC) $(LIBS) -o $(OUT)

clean:
	rm -f $(OUT)

