# Makefile pour le projet

# Variables de compilation
CXX = g++
CXXFLAGS = -std=c++98 -Wall -Wextra -pedantic # -Werror
LDFLAGS =
SRC_DIR = src
OBJ_DIR = objets
BIN_DIR = bin
TEST_DIR = src/tests

# Sources
MAIN_SRC = $(SRC_DIR)/main.cpp
MODELES_SRC = $(wildcard $(SRC_DIR)/modeles/sources/*.cpp)
OUTILS_SRC = $(wildcard $(SRC_DIR)/outils/*.cpp)
TEST_SRC = $(wildcard $(TEST_DIR)/*.cpp)

# Objets (tous dans le même dossier objets/)
MAIN_OBJ = $(OBJ_DIR)/main.o
MODELES_OBJ = $(patsubst $(SRC_DIR)/modeles/sources/%.cpp,$(OBJ_DIR)/%.o,$(MODELES_SRC))
OUTILS_OBJ = $(patsubst $(SRC_DIR)/outils/%.cpp,$(OBJ_DIR)/%.o,$(OUTILS_SRC))
TEST_OBJ = $(patsubst $(TEST_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(TEST_SRC))

ALL_OBJ = $(MAIN_OBJ) $(MODELES_OBJ) $(OUTILS_OBJ)

BIN_FILE = programme.exe
TEST_BIN_FILE = test.exe

# Dossiers
MKDIR_P = mkdir -p

# Règles
all: $(BIN_FILE)

$(BIN_FILE): $(ALL_OBJ)
	$(MKDIR_P) $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(BIN_DIR)/$@ $^

# Règle pour main.o
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(MKDIR_P) $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Règle pour les fichiers dans modeles/sources/
$(OBJ_DIR)/%.o: $(SRC_DIR)/modeles/sources/%.cpp
	$(MKDIR_P) $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Règle pour les fichiers dans outils/
$(OBJ_DIR)/%.o: $(SRC_DIR)/outils/%.cpp
	$(MKDIR_P) $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Règle pour les fichiers dans tests/
$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(MKDIR_P) $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

run: $(BIN_FILE)
	$(BIN_DIR)/$(BIN_FILE)

tests: $(TEST_BIN_FILE)
	$(BIN_DIR)/$(TEST_BIN_FILE)

$(TEST_BIN_FILE): $(TEST_OBJ)
	$(MKDIR_P) $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(BIN_DIR)/$@ $^

valgrind: $(BIN_FILE)
	@echo "Running Valgrind..."
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose $(BIN_DIR)/$(BIN_FILE)

.PHONY: all clean run tests valgrind
