# !/bin/bash

gcc -o main.elf main.c ../AVL/avl.c dsw.c -lm
./main.elf