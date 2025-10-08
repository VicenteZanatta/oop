CC = gcc 

# Nome do compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -Iinclude

# Arquivos fonte
SRC = src/main.c src/commitment.c src/class.c

# Objetos gerados
OBJ = $(SRC:.c=.o)

# Nome do executável final
TARGET = scheduler

# Regra padrão (executável)
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Regra genérica para compilar cada .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpar os arquivos gerados
clean:
	rm -f $(OBJ) $(TARGET)
