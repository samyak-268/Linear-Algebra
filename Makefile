CC = g++
CFLAGS = -c -Wall

SOURCES = matrix.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE = lin-alg

all: $(SOURCES) $(EXECUTABLE) clean-obj

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

$(OBJECTS): %.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean-obj:
	rm  *.o

clean:
	rm  $(EXECUTABLE)
