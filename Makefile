CC=g++
ifeq ($(OS),Windows_NT)
	CFLAGS=-c -std=c++11 -Wall -pedantic -g -Wl,-subsystem,windows
	LDFLAGS= -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
else
	CFLAGS=-c -std=c++11 -Wall -pedantic -g
	LDFLAGS= -lSDL2 -lSDL2_image
endif
SOURCES=main.cpp Renderer.cpp Texture.cpp
OBJECTS=$(addprefix obj/,$(SOURCES:.cpp=.o))
EXECUTABLE=mineguy2

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

#.cpp.o:
$(OBJECTS): obj/%.o : %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS)

# falešné cíle
.PHONY: