CC = nasm
CFLAGS = -f elf64
OBJ = calculator.o
TARGET = calculator

all: $(TARGET)

$(TARGET): $(OBJ)
	ld -o $(TARGET) $(OBJ)

$(OBJ): src/calculator.asm
	$(CC) $(CFLAGS) src/calculator.asm -o $(OBJ)

clean:
	rm -f $(OBJ) $(TARGET)