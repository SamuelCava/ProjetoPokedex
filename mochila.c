#include "mochila.h"
#include <stdio.h>
#include <stdlib.h>


void trocar(int posicao1, int posicao2, Mochila* mochila){
    // as posicoes é como o usuario ve entçao começa em 1 e vai ate 6
    int temporario = mochila->codigos_pokemon[posicao1];
    mochila->codigos_pokemon[posicao1] = mochila->codigos_pokemon[posicao2];
    mochila->codigos_pokemon[posicao2] = temporario;
}
void inserir(int codigo, Mochila* mochila){
    if (mochila->pokemons_mochila >= 6){
        printf("mochila cheia, não foi possível inserir");
        printf("gostaria de substituir?");
    }
    else{
        mochila->codigos_pokemon[mochila->pokemons_mochila] = codigo;
        mochila->pokemons_mochila++;
    }
}
void visualizar(int posicao, Mochila* mochila, Pokedex* pokedex){
    pesquisar_na_pokedex(mochila->codigos_pokemon[posicao], &pokedex);
}