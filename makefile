CC = g++
FLAGS = `libpng-config --cflags`
RUN_FLAGS =`libpng-config --ldflags`
COMP_NUMBER = 2
TARGET = main
EXEC = *.cpp

default: main.o

main.o: $(EXEC)
	$(CC) -c $(TARGET).cpp $(FLAGS)
	$(CC) -o $(TARGET) $(TARGET).o $(RUN_FLAGS)

run: main.o
	./$(TARGET) $(COMP_NUMBER)
	-rm $(TARGET)
	-rm $(TARGET).o