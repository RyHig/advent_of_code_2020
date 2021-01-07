CC = clang++

CFLAGS = -g -Wall

TARGET = day6

INCLUDE = -I../day_5/ ../day_5/function.cpp


all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) $(INCLUDE) -o $(TARGET).o $(TARGET).cpp

clean:
	$(RM) $(TARGET).o
	$(RM) a.out
