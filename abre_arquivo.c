#include <stdio.h>
#include "mochila.h"
#include "pokedex.h"
#include "pokemon.h"

void abre_mochila(Mochila mochila){
    FILE *arq;
    arq = fopen("mochila.dat", "rb");
     if (arq == NULL){
        perror("Erro para abrir o arquivo.");      
        exit(1);   
    }// if
    int quantidade_mochila;
    fread(&quantidade_mochila, sizeof(int), 1, arq);
    mochila.pokemons_mochila = quantidade_mochila;
    for (int i = 0; i < quantidade_mochila; i++){
        int codigo;
        fread(&codigo, sizeof(int), 1, arq);
        mochila.codigos_pokemon[i] = codigo;
    }
}


void abre_pokedex(Pokedex pokedex){
    FILE *arq;
    arq = fopen("pokedex.dat", "rb");
     if (arq == NULL){
        perror("Erro para abrir o arquivo.");      
        exit(1);   
    }// if

}