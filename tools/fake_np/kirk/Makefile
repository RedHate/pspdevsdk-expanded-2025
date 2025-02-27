
CC = gcc
CFLAGS = -Wall -g

TARGET = libkirk.a
OBJS = kirk_engine.o cmac.o

$(TARGET): $(OBJS)
	ar rcs $@ $(OBJS)

clean:
	rm -f *.o $(TARGET)

