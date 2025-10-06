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

# Ajout des répertoires d'include du projet
# -I modeles/include pour le code de prod
# -I tests/include pour le code de test
# Remarque : l'expansion des variables dans make est paresseuse (lazy),
# donc on peut référencer SRC_DIR/TEST_INC_DIR avant leur définition.
CXXFLAGS += -I$(SRC_DIR)/modeles/include -I$(TEST_INC_DIR)

# ----------------------------------------------------------------------------
# VARIABLES DE DOSSIERS
# ----------------------------------------------------------------------------

# SRC_DIR : racine du code source
SRC_DIR  = src

# OBJ_DIR : dossier où seront stockés les fichiers objets .o compilés
OBJ_DIR  = objets

# BIN_DIR : dossier où sera placé l'exécutable final
BIN_DIR  = bin

# Modèles (prod) : dossiers include & sources
MODELES_SRC_DIR = $(SRC_DIR)/modeles/sources
MODELES_INC_DIR = $(SRC_DIR)/modeles/include

# Outils (prod)
OUTILS_SRC_DIR  = $(SRC_DIR)/outils

# Tests : dossier racine, et sous-dossiers include & sources
# On laissera lancementTests.cpp à la racine de $(TEST_DIR)
TEST_DIR     = $(SRC_DIR)/tests
TEST_INC_DIR = $(TEST_DIR)/include
TEST_SRC_DIR = $(TEST_DIR)/sources

# ----------------------------------------------------------------------------
# FICHIERS SOURCES
# ----------------------------------------------------------------------------

# MAIN_SRC : fichier source principal du programme
MAIN_SRC      = $(SRC_DIR)/main.cpp

# MODELES_SRC : tous les .cpp dans modeles/sources/
MODELES_SRC   = $(wildcard $(MODELES_SRC_DIR)/*.cpp)

# OUTILS_SRC : tous les .cpp dans outils/
OUTILS_SRC    = $(wildcard $(OUTILS_SRC_DIR)/*.cpp)

# TEST_SOURCES : tous les .cpp dans tests/sources/
TEST_SOURCES      = $(wildcard $(TEST_SRC_DIR)/*.cpp)

# TEST_LAUNCHER_SRC : le lanceur de tests resté à la racine du dossier tests
TEST_LAUNCHER_SRC = $(TEST_DIR)/lancementTests.cpp

# ----------------------------------------------------------------------------
# FICHIERS OBJETS (.o)
# ----------------------------------------------------------------------------

# MAIN_OBJ : fichier objet dérivé de main.cpp
MAIN_OBJ     = $(OBJ_DIR)/main.o

# MODELES_OBJ : transformation src/modeles/sources/Foo.cpp → objets/Foo.o
MODELES_OBJ  = $(patsubst $(MODELES_SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(MODELES_SRC))

# OUTILS_OBJ : transformation src/outils/Bar.cpp → objets/Bar.o
OUTILS_OBJ   = $(patsubst $(OUTILS_SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(OUTILS_SRC))

# Objets de tests :
# - On préfixe par "test_" pour éviter toute collision de nom d'objet.
# - TEST_OBJ_SRC : objets issus de tests/sources/*.cpp
# - TEST_LAUNCH_OBJ : objet issu de tests/lancementTests.cpp (à la racine)
TEST_OBJ_SRC    = $(patsubst $(TEST_SRC_DIR)/%.cpp,$(OBJ_DIR)/test_%.o,$(TEST_SOURCES))
TEST_LAUNCH_OBJ = $(patsubst $(TEST_DIR)/%.cpp,$(OBJ_DIR)/test_%.o,$(TEST_LAUNCHER_SRC))
TEST_OBJ        = $(TEST_OBJ_SRC) $(TEST_LAUNCH_OBJ)

# ALL_OBJ : liste de TOUS les objets nécessaires pour le programme principal
# (exclut TEST_OBJ qui sert uniquement pour l'exécutable de tests)
ALL_OBJ = $(MAIN_OBJ) $(MODELES_OBJ) $(OUTILS_OBJ)

# ----------------------------------------------------------------------------
# NOMS DES EXÉCUTABLES
# ----------------------------------------------------------------------------

# BIN_FILE : nom de l'exécutable principal
BIN_FILE      = programme.exe

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
# RÈGLES DE LINKAGE DES EXÉCUTABLES
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

# $(TEST_BIN_FILE) : création de l'exécutable de tests
# On linke : objets de tests + objets prod (modèles/outils). Surtout PAS main.o.
$(TEST_BIN_FILE): $(TEST_OBJ) $(MODELES_OBJ) $(OUTILS_OBJ)
	# Crée le dossier bin/ si il n'existe pas
	$(MKDIR_P) $(BIN_DIR)
	# Lie les objets de test avec les objets de prod pour créer l'exécutable de tests
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(BIN_DIR)/$@ $^

# ----------------------------------------------------------------------------
# RÈGLES DE COMPILATION DES FICHIERS OBJETS (PROD)
# ----------------------------------------------------------------------------

# main.cpp → objets/main.o
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	# Crée le dossier objets/ si il n'existe pas
	$(MKDIR_P) $(OBJ_DIR)
	# Compile main.cpp en main.o
	# -c : compile sans linker (crée juste le .o)
	# $< : première dépendance (main.cpp)
	# $@ : nom de la cible (objets/main.o)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# src/modeles/sources/*.cpp → objets/*.o
# % : wildcard qui matche n'importe quel nom de fichier
$(OBJ_DIR)/%.o: $(MODELES_SRC_DIR)/%.cpp
	# Crée le dossier objets/ si il n'existe pas
	$(MKDIR_P) $(OBJ_DIR)
	# Compile le .cpp correspondant en .o
	$(CXX) $(CXXFLAGS) -c $< -o $@

# src/outils/*.cpp → objets/*.o
$(OBJ_DIR)/%.o: $(OUTILS_SRC_DIR)/%.cpp
	# Crée le dossier objets/ si il n'existe pas
	$(MKDIR_P) $(OBJ_DIR)
	# Compile le .cpp correspondant en .o
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ----------------------------------------------------------------------------
# RÈGLES DE COMPILATION DES FICHIERS OBJETS (TESTS)
# ----------------------------------------------------------------------------

# src/tests/sources/*.cpp → objets/test_*.o
$(OBJ_DIR)/test_%.o: $(TEST_SRC_DIR)/%.cpp
	# Crée le dossier objets/ si il n'existe pas
	$(MKDIR_P) $(OBJ_DIR)
	# Compile le .cpp de test en .o préfixé test_
	$(CXX) $(CXXFLAGS) -c $< -o $@

# src/tests/lancementTests.cpp (à la racine du dossier tests) → objets/test_lancementTests.o
$(OBJ_DIR)/test_%.o: $(TEST_DIR)/%.cpp
	# Crée le dossier objets/ si il n'existe pas
	$(MKDIR_P) $(OBJ_DIR)
	# Compile le lanceur de tests en .o préfixé test_
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ============================================================================
# RÈGLES DE BUILD AVEC DEBUG (TRACES)
# ============================================================================

# debug : compile avec la macro MAP définie
# CXXFLAGS += -DMAP : ajoute -DMAP aux flags de compilation
# Cette macro active les blocs #ifdef MAP dans le code source
# clean : force la recompilation de tous les fichiers avec le nouveau flag
debug: CXXFLAGS += -DMAP
debug: clean $(BIN_FILE)

# run-debug : compile en mode debug puis exécute le programme
# Les traces de constructeurs/destructeurs seront affichées à l'exécution
run-debug: CXXFLAGS += -DMAP
run-debug: clean $(BIN_FILE)
	# Exécute l'exécutable qui vient d'être compilé avec -DMAP
	$(BIN_DIR)/$(BIN_FILE)

# ============================================================================
# RÈGLES D'EXÉCUTION
# ============================================================================

# run : cible pour exécuter le programme principal
# Dépend de $(BIN_FILE), donc compile d'abord si les sources ont changé
# Si l'exécutable est à jour, passe directement à l'exécution
run: $(BIN_FILE)
	# Lance l'exécutable
	$(BIN_DIR)/$(BIN_FILE)

# tests : cible pour compiler et exécuter les tests unitaires
# Dépend de $(TEST_BIN_FILE), donc compile l'exécutable de tests d'abord
tests: $(TEST_BIN_FILE)
	# Lance l'exécutable de tests
	$(BIN_DIR)/$(TEST_BIN_FILE)

# ============================================================================
# RÈGLES D'ANALYSE ET NETTOYAGE
# ============================================================================

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
