# Nome do compilador
CC = gcc

# Diretórios de origem e destino
SRC_DIR = src
BUILD_DIR = build

# Arquivos fonte e executável
SRC = $(SRC_DIR)/lista.c
EXEC = $(BUILD_DIR)/lista

# Flags de compilação (opcional)
CFLAGS = -Wall

# Regra padrão de compilação
all: $(EXEC)

$(EXEC): $(SRC)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC)

# Limpar arquivos de compilação
clean:
	rm -rf $(BUILD_DIR)

# Executar o programa
run: all
	./$(EXEC)
