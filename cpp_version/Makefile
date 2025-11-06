# Compilador
CC = g++

# Flags de compilação
CFLAGS = -Wall -Wextra -Iinc -ggdb3 -O0

# Flags de linkagem
LDFLAGS = -lm

# Arquivos fonte
SRC = src/main.cpp \
      src/classes/commitment.cpp \
      src/classes/lesson.cpp \
	  src/util/linked_list.cpp \
	  src/util/file_input_output.cpp\
	  
# Objetos gerados
OBJ = $(SRC:.cpp=.o)

# Nome do executável final
TARGET = scheduler

# Regra padrão (executável)
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)
	rm -f $(OBJ)

# Regra genérica para compilar cada .c em .o
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Limpar arquivos gerados
clean: 
	rm -f $(OBJ) $(TARGET)
