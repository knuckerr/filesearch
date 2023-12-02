CC = gcc

CFLAGS =  -D_DEFAULT_SOURCE \
-O2 -Wall -Wformat=2 -Wconversion -Wtrampolines -Wimplicit-fallthrough \
-U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=3 \
-D_GLIBCXX_ASSERTIONS \
-fstack-clash-protection -fstack-protector-strong \
-Wl,-z,nodlopen -Wl,-z,noexecstack \
-Wl,-z,relro -Wl,-z,now

LDFLAGS = -lm  # You may need to adjust this based on your needs

SOURCES = main.c queue.c bf_search.c kmp.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = file_search

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)

rebuild: clean all
