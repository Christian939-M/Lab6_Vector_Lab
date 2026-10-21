CC=gcc
CFLAGS=-c -Wall
SOURCES= lab5.c vect.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=lab7

all: $(SOURCES) $(EXECUTABLE)

-include $(OBJECTS:.o=.d)

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)

.c.o:
	$(CC) $(CFLAGS) $< -o $@
	$(CC) -MM $< > $*.d

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) *.d