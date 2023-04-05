gcc -o arvore_binaria_de_busca.o arvore_binaria_de_busca.c -c
gcc -o main.elf ../Arvore_Binaria/arvore_binaria.o arvore_binaria_de_busca.o main.c 
./main.elf