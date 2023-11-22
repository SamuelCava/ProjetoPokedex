
#ifndef MOCHILA_H
#define MOCHILA_H
#include "pokedex.h"

typedef struct{
    /*
    Defina uma estrutura Mochila que deve armazenar a relação de até 6 Pokémons já
    capturados e que poderão ser utilizados em batalha, para isso armazene apenas o
    número(códigos).
    
    */
    // diz quantos pokemons tem na mochila
    int pokemons_mochila;
    int codigos_pokemon[6];

}Mochila;

// preciso escrever os metodos

void trocar_mochila(int posicao1, int posicao2, Mochila* mochila);
void inserir_mochila(int codigo, Mochila* mochila);
void visualizar_mochila(int posicao, Mochila* mochila, Pokedex* pokedex);
#endif