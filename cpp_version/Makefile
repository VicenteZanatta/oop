# Compilador
CC = g++

# Arquivo Input
ARGS = "exemplo01/agenda.txt"

# Flags de compilação
CFLAGS = -Wall -Wextra -Iinc -ggdb3 -O0

# Flags de linkagem
LDFLAGS = -lm

# Arquivos fonte
SRC = src/main.cpp \
      src/classes/commitment.cpp \
      src/classes/lesson.cpp \
      src/classes/ppCommitment.cpp \
      src/classes/orientation.cpp \
      src/classes/dept_meeting.cpp \
      src/classes/event.cpp \
      src/classes/personal.cpp \
      src/util/merge_sort.cpp \
      src/util/linked_list.cpp \
      src/util/file_input.cpp \
      src/util/filter.cpp

# Objetos gerados
OBJ = $(SRC:.cpp=.o)

# Nome do executável final
TARGET = scheduler

# Regra padrão (gera o executável)
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

# Regra genérica para compilar cada .cpp em .o
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Executar o programa
run: $(TARGET)
	./$(TARGET) $(ARGS)

# Limpar arquivos gerados
clean:
	rm -f $(OBJ) $(TARGET)