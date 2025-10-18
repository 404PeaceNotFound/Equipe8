# ======================================
#   Makefile multiplataforma - Raylib
# ======================================

# Nome do executável
TARGET = jogo

# Diretório com o código-fonte
SRC_DIR = src
SRC = $(wildcard $(SRC_DIR)/*.c)

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -std=c99

# Detecta sistema operacional
ifeq ($(OS),Windows_NT)
    # --- CONFIGURAÇÃO WINDOWS ---
    RM = del /Q
    EXEC = $(TARGET).exe
    LIBS = -lraylib -lopengl32 -lgdi32 -lwinmm
    CONSOLE_FLAG = -Wl,--subsystem,console
else
    # --- CONFIGURAÇÃO LINUX ---
    RM = rm -f
    EXEC = $(TARGET)
    LIBS = -lraylib -lm -lpthread -ldl -lrt -lGL -lX11
    CONSOLE_FLAG =
endif

# Regra padrão: compilar
all: $(EXEC)

$(EXEC): $(SRC)
	@echo Compilando fontes...
	$(CC) $(SRC) -o $(EXEC) $(CFLAGS) $(LIBS) $(CONSOLE_FLAG)
	@echo Build concluído com sucesso!

# Rodar o jogo
run: all
	@echo Executando $(EXEC)...
	cd $(dir $(EXEC)) && ./$(notdir $(EXEC))

# Limpar builds antigos
clean:
	@echo Limpando...
	$(RM) $(EXEC)
	@echo Limpo!
