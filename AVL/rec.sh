gcc -o avl.o avl.c -c
gcc -o main.elf ../Arvore_Binaria/arvore_binaria.o ../Arvore_Binaria_de_Busca/arvore_binaria_de_busca.o avl.o main.c 
./main.elf