# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Target executable
TARGET = calc.out

# Object files
OBJS = stack.o main.o getch.o getop.o

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Compile source files to object files
# Update these lines if your source filenames differ (e.g., head.c vs head_compiled.c)
stack_compiled.o: stack.c
	$(CC) $(CFLAGS) -c stack.c -o stack.o

main_compiled.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

getch_compiled.o: getch.c
	$(CC) $(CFLAGS) -c getch.c -o getch.o

getop_compiled.o: getop.c
	$(CC) $(CFLAGS) -c getop.c -o getop.o

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)   
