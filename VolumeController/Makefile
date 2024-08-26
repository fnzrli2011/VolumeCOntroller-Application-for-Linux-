CC=g++
CFLAGS=-lraylib -lGL -lm -lpthread -ldl -lrt -lX11
TARGET=volume_controller

all: $(TARGET)

$(TARGET): main.cpp
	$(CC) main.cpp -o $(TARGET) $(CFLAGS)

clean:
	rm -f $(TARGET)

