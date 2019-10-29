CC = g++
FLAGS = `libpng-config --cflags`
RUN_FLAGS =`libpng-config --ldflags`
TARGET = main
EXEC = *.cpp

default: main.o

main.o: $(EXEC)
	$(CC) -c $(TARGET).cpp $(FLAGS)
	$(CC) -o $(TARGET) $(TARGET).o $(RUN_FLAGS)

run: main.o
	./$(TARGET)
	-rm $(TARGET)
	-rm $(TARGET).o