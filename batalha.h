#ifndef BATALHA_H
#define BATALHA_H
#include "pokedex.h"
#include "pokemon.h"
#include "colecao.h"
#include "mochila.h"


typedef struct{
    char nomes[6][30];
    int numeros[6];
    int ataques[6];
    int defesas[6];
    int vidas[6];
    int velocidades[6];
}Batalha;
void batalha_par_impar(Mochila* mochila,Pokedex* pokedex);
void inicia_batalha(Pokedex* pokedex, Mochila* mochila, Batalha* batalha);


#endif
