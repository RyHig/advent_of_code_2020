CC = clang++

CFLAGS = -g -Wall

TARGET = day5

INCLUDE = function

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) $(INCLUDE).cpp -o $(TARGET).o $(TARGET).cpp

clean:
	$(RM) $(TARGET).o
	$(RM) a.out
