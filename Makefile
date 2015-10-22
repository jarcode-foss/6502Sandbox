CFLAGS = -D -O2
LDFLAGS = -fPIC -I"$(JAVA_HOME)/include" -I"$(JAVA_HOME)/include/linux" -I"target/include" -shared

SOURCES := $(wildcard *.c)
OBJECTS := $(notdir $(SOURCES:.c=.o))
LIBRARY_NAME = 6502sandbox
LIBRARY_PATH = lib$(LIBRARY_NAME).so

.PHONY: all
all: $(LIBRARY_PATH)

$(LIBRARY_PATH): $(OBJECTS)
	$(CC) ${LDFLAGS} -o $@ $^

$(SOURCES:.c=.d):%.d:%.c
	$(CC) $(CFLAGS) -MM $< >$@

include $(SOURCS:.c=.d)