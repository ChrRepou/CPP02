CC = g++

CFLAGS  = -g -Wall -Wextra -Werror -std=c++98

TARGET = main
SOURCES = main.cpp Fixed.cpp
OBJ = main.o Fixed.o

all: exec

exec: $(OBJ)
	$(CC) $(CFLAGS) -o main $(OBJ)

$(TARGET).o: $(TARGET).cpp Fixed.hpp
	$(CC) $(CFLAGS) -c $(TARGET).cpp

Fixed.o: Fixed.cpp Fixed.hpp
	$(CC) $(CFLAGS) -c Fixed.cpp

clean:
	$(RM) main $(OBJ)

fclean:
	make clean

re: fclean all