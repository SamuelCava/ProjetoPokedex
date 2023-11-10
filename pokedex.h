#include <stdio.h>
#include <stdlib.h>
#include "pokemon.h"

typedef struct{
    int cadastrados;
    // tamanho representa o espaço de quantos int tenho pra usar
    int tamanho = 10;
    Pokemon *codigo_capturados;

}Pokedex;

void inicia_vetor(Pokedex pokedex);