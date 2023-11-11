#include "pokemon.h"

typedef struct{
    int cadastrados;
    // tamanho representa o espaço de quantos int tenho pra usar
    int tamanho = 10;
    Pokemon *capturados;
    

}Pokedex;

void inicia_vetor(Pokedex pokedex);