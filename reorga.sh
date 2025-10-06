# 1) Créer l’arborescence des tests
mkdir -p src/tests/include src/tests/sources

# 2) Déplacer tous les fichiers de tests (sauf lancementTests.cpp) dans tests/sources
#   -> adapte si tu as d’autres fichiers que Test*.cpp
shopt -s nullglob
for f in src/tests/Test*.cpp; do
  mv "$f" src/tests/sources/
done

# 3) Créer des .h correspondants dans tests/include (stubs simples)
for f in src/tests/sources/*.cpp; do
  base="$(basename "$f" .cpp)"
  h="src/tests/include/${base}.h"
  if [ ! -f "$h" ]; then
    guard="$(echo "${base}_H" | tr '[:lower:]-' '[:upper:]_')"
    cat > "$h" <<EOF
#pragma once
// Header auto-généré pour ${base}.cpp
// Déclare ici tes fonctions de test, ex. : void ${base}_run();
EOF
  fi
done

# 4) Vérifier que lancementTests.cpp reste bien à la racine
# (ne rien faire si déjà là)
test -f src/tests/lancementTests.cpp && echo "OK: lancementTests.cpp est à la racine de src/tests/."

