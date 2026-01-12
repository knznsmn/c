CC = cc
CFLAGS = $(shell pkg-config --cflags sdl3)
LIBS = $(shell pkg-config --libs sdl3)

TARGET = main
SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: clean
