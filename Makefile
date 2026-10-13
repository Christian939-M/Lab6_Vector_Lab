CC=gcc
CFLAGS=-c -Wall
SOURCES= lab5.c vectadd.c vectsub.c vectassignval.c vect_operation.c vect_io.c find_or_create_vector.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=lab7

all: $(SOURCES) $(EXECUTABLE)

# pull in dependency info for "existing" .o files
-include $(OBJECTS:.o=.d)

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)

.c.o:
	$(CC) $(CFLAGS) $< -o $@
	$(CC) -MM $< > $*.d

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) *.d