CC = g++
CFLAGS = -std=c++20 -Wall

SRCDIR = src
LIBDIR = $(SRCDIR)/lib

SOURCES = $(wildcard $(SRCDIR)/*.cpp) $(wildcard $(LIBDIR)/**/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = my_program

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
