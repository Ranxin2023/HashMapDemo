CC=gcc
CFLAGS=-Wall -Werror
DEPS=StringCountHashMap.h IntCountHashMap.h
SRCS=main.c StringCountHashMap.c IntCountHashMap.c
OBJECTS=$(SRCS:.c=.o)
TARGET=hash_demo

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	if exist *.o del *.o
	if exist $(TARGET).exe del $(TARGET).exe