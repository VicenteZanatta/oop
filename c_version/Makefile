# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -Iinclude -ggdb3 -std=c11 -O0

# Flags de linkagem
LDFLAGS = -lm

# Arquivos fonte
SRC = src/main.c src/commitment.c src/class.c src/file_input_output.c src/linked_list.c src/orientation.c

# Objetos gerados
OBJ = $(SRC:.c=.o)

# Nome do executável final
TARGET = scheduler

# Regra padrão (executável)
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)
	rm -f $(OBJ)

# Regra genérica para compilar cada .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpar arquivos gerados
clean: 
	rm -f $(OBJ) $(TARGET)
