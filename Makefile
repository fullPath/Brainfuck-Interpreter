EXEC=tdbfi

CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=$(wildcard *.cpp)
OBJS=$(SOURCES:.cpp=.o)

all: $(SOURCES) $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXEC)
