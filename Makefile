# ----------------------------------------------------------------------------
# VARIABLES DE COMPILATION
# ----------------------------------------------------------------------------

# CXX : compilateur C++ utilisé (g++ = GNU C++ Compiler)
CXX = g++

# CXXFLAGS : options de compilation passées au compilateur
# -std=c++11  : utilise le standard C++11
# -Wall       : active tous les warnings standards
# -Wextra     : active des warnings supplémentaires
# -pedantic   : respecte strictement le standard (rejette les extensions)
# -Werror     : (commenté) transformerait les warnings en erreurs
# -ansi       : conforme à la norme ANSI C++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -ansi # -Werror

# LDFLAGS : options de linkage (vide ici, mais pourrait contenir -lpthread, -lm, etc.)
LDFLAGS =

# ----------------------------------------------------------------------------
# VARIABLES DE DOSSIERS
# ----------------------------------------------------------------------------

# SRC_DIR : dossier contenant tous les fichiers sources .cpp
SRC_DIR = src

# OBJ_DIR : dossier où seront stockés les fichiers objets .o compilés
OBJ_DIR = objets

# BIN_DIR : dossier où sera placé l'exécutable final
BIN_DIR = bin

# TEST_DIR : dossier contenant les fichiers de tests unitaires
TEST_DIR = src/tests

# ----------------------------------------------------------------------------
# FICHIERS SOURCES
# ----------------------------------------------------------------------------

# MAIN_SRC : fichier source principal du programme
MAIN_SRC = $(SRC_DIR)/main.cpp

# MODELES_SRC : tous les .cpp dans modeles/sources/
# $(wildcard ...) : fonction Make qui trouve tous les fichiers correspondant au pattern
MODELES_SRC = $(wildcard $(SRC_DIR)/modeles/sources/*.cpp)

# OUTILS_SRC : tous les .cpp dans outils/
OUTILS_SRC = $(wildcard $(SRC_DIR)/outils/*.cpp)

# TEST_SRC : tous les .cpp dans tests/
TEST_SRC = $(wildcard $(TEST_DIR)/*.cpp)

# ----------------------------------------------------------------------------
# FICHIERS OBJETS (.o)
# ----------------------------------------------------------------------------

# MAIN_OBJ : fichier objet de main.cpp → objets/main.o
MAIN_OBJ = $(OBJ_DIR)/main.o

# MODELES_OBJ : transforme src/modeles/sources/Foo.cpp → objets/Foo.o
# $(patsubst pattern,replacement,text) : remplace le pattern dans text
MODELES_OBJ = $(patsubst $(SRC_DIR)/modeles/sources/%.cpp,$(OBJ_DIR)/%.o,$(MODELES_SRC))

# OUTILS_OBJ : transforme src/outils/Bar.cpp → objets/Bar.o
OUTILS_OBJ = $(patsubst $(SRC_DIR)/outils/%.cpp,$(OBJ_DIR)/%.o,$(OUTILS_SRC))

# TEST_OBJ : transforme src/tests/Test.cpp → objets/Test.o
TEST_OBJ = $(patsubst $(TEST_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(TEST_SRC))

# ALL_OBJ : liste de TOUS les objets nécessaires pour le programme principal
# (exclut TEST_OBJ qui sert uniquement pour l'exécutable de tests)
ALL_OBJ = $(MAIN_OBJ) $(MODELES_OBJ) $(OUTILS_OBJ)

# ----------------------------------------------------------------------------
# NOMS DES EXÉCUTABLES
# ----------------------------------------------------------------------------

# BIN_FILE : nom de l'exécutable principal
BIN_FILE = programme.exe

# TEST_BIN_FILE : nom de l'exécutable des tests
TEST_BIN_FILE = test.exe

# ----------------------------------------------------------------------------
# COMMANDES SYSTÈME
# ----------------------------------------------------------------------------

# MKDIR_P : commande pour créer des dossiers (avec parents si nécessaire)
# -p : crée les dossiers parents si ils n'existent pas, pas d'erreur si existe déjà
MKDIR_P = mkdir -p

# ============================================================================
# RÈGLES DE COMPILATION
# ============================================================================

# ----------------------------------------------------------------------------
# RÈGLE PAR DÉFAUT (all)
# ----------------------------------------------------------------------------

# all : cible par défaut exécutée quand on tape juste "make"
# Dépend de $(BIN_FILE), donc va compiler le programme principal
all: $(BIN_FILE)

# ----------------------------------------------------------------------------
# RÈGLE DE LINKAGE PRINCIPAL
# ----------------------------------------------------------------------------

# $(BIN_FILE) : création de l'exécutable principal
# Dépend de $(ALL_OBJ), donc tous les .o doivent être compilés avant
$(BIN_FILE): $(ALL_OBJ)
    # Crée le dossier bin/ si il n'existe pas
	$(MKDIR_P) $(BIN_DIR)
    # Lie tous les fichiers objets pour créer l'exécutable
    # $@ : nom de la cible (programme.exe)
    # $^ : toutes les dépendances (tous les .o)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(BIN_DIR)/$@ $^

# ----------------------------------------------------------------------------
# RÈGLES DE COMPILATION DES FICHIERS OBJETS
# ----------------------------------------------------------------------------

# Règle pour compiler main.cpp → objets/main.o
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
    # Crée le dossier objets/ si il n'existe pas
	$(MKDIR_P) $(OBJ_DIR)
    # Compile main.cpp en main.o
    # -c : compile sans linker (crée juste le .o)
    # $< : première dépendance (main.cpp)
    # $@ : nom de la cible (objets/main.o)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Règle pattern pour compiler src/modeles/sources/*.cpp → objets/*.o
# % : wildcard qui matche n'importe quel nom de fichier
$(OBJ_DIR)/%.o: $(SRC_DIR)/modeles/sources/%.cpp
    # Crée le dossier objets/ si il n'existe pas
	$(MKDIR_P) $(OBJ_DIR)
    # Compile le .cpp correspondant en .o
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Règle pattern pour compiler src/outils/*.cpp → objets/*.o
$(OBJ_DIR)/%.o: $(SRC_DIR)/outils/%.cpp
    # Crée le dossier objets/ si il n'existe pas
	$(MKDIR_P) $(OBJ_DIR)
    # Compile le .cpp correspondant en .o
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Règle pattern pour compiler src/tests/*.cpp → objets/*.o
$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp
    # Crée le dossier objets/ si il n'existe pas
	$(MKDIR_P) $(OBJ_DIR)
    # Compile le .cpp correspondant en .o
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ============================================================================
# RÈGLES DE BUILD AVEC DEBUG (TRACES)
# ============================================================================

# ----------------------------------------------------------------------------
# BUILD DEBUG (avec macro -DMAP pour activer les traces)
# ----------------------------------------------------------------------------

# debug : compile avec la macro MAP définie
# CXXFLAGS += -DMAP : ajoute -DMAP aux flags de compilation
# Cette macro active les blocs #ifdef MAP dans le code source
# clean : force la recompilation de tous les fichiers avec le nouveau flag
debug: CXXFLAGS += -DMAP
debug: clean $(BIN_FILE)

# ----------------------------------------------------------------------------
# RUN DEBUG (compile avec -DMAP puis exécute)
# ----------------------------------------------------------------------------

# run-debug : compile en mode debug puis exécute le programme
# Les traces de constructeurs/destructeurs seront affichées à l'exécution
run-debug: CXXFLAGS += -DMAP
run-debug: clean $(BIN_FILE)
    # Exécute l'exécutable qui vient d'être compilé avec -DMAP
	$(BIN_DIR)/$(BIN_FILE)

# ============================================================================
# RÈGLES D'EXÉCUTION
# ============================================================================

# ----------------------------------------------------------------------------
# RUN NORMAL (compile si nécessaire puis exécute)
# ----------------------------------------------------------------------------

# run : cible pour exécuter le programme principal
# Dépend de $(BIN_FILE), donc compile d'abord si les sources ont changé
# Si l'exécutable est à jour, passe directement à l'exécution
run: $(BIN_FILE)
    # Lance l'exécutable
	$(BIN_DIR)/$(BIN_FILE)

# ----------------------------------------------------------------------------
# TESTS (compile et exécute les tests unitaires)
# ----------------------------------------------------------------------------

# tests : cible pour compiler et exécuter les tests unitaires
# Dépend de $(TEST_BIN_FILE), donc compile l'exécutable de tests d'abord
tests: $(TEST_BIN_FILE)
    # Lance l'exécutable de tests
	$(BIN_DIR)/$(TEST_BIN_FILE)

# $(TEST_BIN_FILE) : création de l'exécutable de tests
# Dépend uniquement de $(TEST_OBJ), pas des autres objets du projet
$(TEST_BIN_FILE): $(TEST_OBJ)
    # Crée le dossier bin/ si il n'existe pas
	$(MKDIR_P) $(BIN_DIR)
    # Lie tous les fichiers objets de tests pour créer l'exécutable
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(BIN_DIR)/$@ $^

# ============================================================================
# RÈGLES D'ANALYSE ET NETTOYAGE
# ============================================================================

# ----------------------------------------------------------------------------
# VALGRIND (détection de fuites mémoire)
# ----------------------------------------------------------------------------

# valgrind : lance le programme avec Valgrind pour détecter les fuites mémoire
# Dépend de $(BIN_FILE), donc compile d'abord si nécessaire
valgrind: $(BIN_FILE)
    # @ : n'affiche pas la commande elle-même, juste le résultat
    # echo : affiche un message
	@echo "Running Valgrind..."
    # Options Valgrind :
    # --leak-check=full        : recherche détaillée des fuites
    # --show-leak-kinds=all    : montre tous les types de fuites
    # --track-origins=yes      : trace l'origine des valeurs non initialisées
    # --verbose                : mode verbeux
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose $(BIN_DIR)/$(BIN_FILE)

# ----------------------------------------------------------------------------
# CLEAN (supprime tous les fichiers générés)
# ----------------------------------------------------------------------------

# clean : supprime tous les fichiers compilés pour repartir de zéro
# Utile quand on veut forcer une recompilation complète
clean:
    # rm : commande de suppression
    # -r : récursif (supprime les dossiers et leur contenu)
    # -f : force (pas d'erreur si les fichiers n'existent pas)
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# ============================================================================
# DÉCLARATION DES CIBLES PHONY
# ============================================================================

# .PHONY : déclare les cibles qui ne correspondent PAS à des fichiers réels
# Cela évite les conflits si un fichier porte le même nom qu'une cible
# Par exemple, si un fichier "clean" existait, make serait confus
.PHONY: all clean run debug run-debug tests valgrind
