CC = clang++

CFLAGS = -g -Wall

TARGET = day2

INCLUDE = -I../day_1/

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) $(INCLUDE) -o $(TARGET).o $(TARGET).cpp

clean:
	$(RM) $(TARGET).o
