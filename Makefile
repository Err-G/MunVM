CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c99
SRC_DIR=src
EXECUTABLE=vm

HEADERS=$(wildcard $(SRC_DIR)/*.h)
SOURCES=$(wildcard $(SRC_DIR)/*.c)
OBJECTS=$(patsubst $(SRC_DIR)/%.c,%.o,$(SOURCES))

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJECTS) $(EXECUTABLE)
