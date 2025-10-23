
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: football temperature

football: football.c
	$(CC) $(CFLAGS) -o football football.c

temperature: temperature.c
	$(CC) $(CFLAGS) -o temperature temperature.c

clean:
	rm -f football temperature