CC = gcc
 
SOURCES = ./src/virgil.c
OBJECTS = $(SOURCES:.c=.o)
 
EXECUTABLE = virgil
 
CFLAGS += `pkg-config --cflags gtk+-3.0 webkit2gtk-4.1`
LDFLAGS += `pkg-config --libs gtk+-3.0 webkit2gtk-4.1`
 
all: 
	$(SOURCES) $(EXECUTABLE)
	$(EXECUTABLE): $(OBJECTS)
	$(CC)	$(OBJECTS)	-o 	@	$(LDFLAGS)
