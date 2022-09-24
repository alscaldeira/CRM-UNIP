#include <stdio.h>

// adiciona um novo elemento na variável
char *adicionar(char lista[], char c) {

    int size = sizeof(*lista);
    char *novaLista[size];

    for(int i=0; i<size; i++) {
        novaLista[i] = &lista[i];
    }

    *novaLista[size] = c;
    return *novaLista;

}