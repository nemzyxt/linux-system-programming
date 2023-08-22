#! /bin/bash

# Steps : Preprocessing -> Compilation -> Assembly -> Linking

# 1. Preprocessing :
echo "[*] Preprocessing ..."
gcc -E -P cube-prog.c -o cube-prog.i

# 2. Compilation :
echo "[*] Compilation ..."
gcc -S cube-prog.i -o cube-prog.s
gcc -S cube-func.c -o cube-func.s

# 3. Assembly :
echo "[*] Assembly ..."
gcc -c cube-prog.s -o cube-prog.o
gcc -c cube-func.s -o cube-func.o

# 4. Linking :
echo "[*] Linking ..."
gcc cube-func.o cube-prog.o -o cube

echo "[*] Compilation complete"
