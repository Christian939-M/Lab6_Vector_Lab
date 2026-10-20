CC=gcc
CFLAGS=-c -Wall
SOURCES= lab5.c vectadd.c vectsub.c vector_product.c vect_operation.c vect_io.c find_or_creat_vector.c find_vect.c scalar.c vect_cross.c
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