/**
 * @file mochila.c
 * @author Leonardo Dal Poz Cardoso (lcardoso.2005@alunos.utfpr.edu.br) e Samuel Assunção Cavalherie (samuelcavalherie@alunos.utfpr.edu.br)
 * @brief Arquivo responsável por armazenar as funções usadas para a mochila
 * @version 0.1
 * @date 2023-11-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "mochila.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Função responsável por substituir um pokemon por outro na mochila
 * 
 * @param posicao1 Passa como argumento da função, um numero do tipo int para identificar uma posição que representa um pokemon na mochila
 * @param posicao2 Passa como argumento da função, um numero do tipo int para identificar outra posição que representa um pokemon na mochila
 * @param mochila Passa como argumento da função, um ponteiro para tipo struct Mochila
 */
void trocar_mochila(int posicao1, int posicao2, Mochila* mochila){
    // as posicoes é como o usuario ve entçao começa em 1 e vai ate 6
    int temporario = mochila->codigos_pokemon[posicao1];
    mochila->codigos_pokemon[posicao1] = mochila->codigos_pokemon[posicao2];
    mochila->codigos_pokemon[posicao2] = temporario;
}

/**
 * @brief Função responsável por inserir um pokemon na mochila
 * 
 * @param codigo Passa como argumento da função, um numero do tipo int para identificar o código/índice que representa o pokemon
 * @param mochila Passa como argumento da função, um ponteiro para tipo struct Mochila
 */
void inserir_mochila(int codigo, Mochila* mochila){
    if (mochila->pokemons_mochila >= 6){
        printf("mochila cheia, não foi possível inserir");
        printf("gostaria de substituir?");
    }
    else{
        mochila->codigos_pokemon[mochila->pokemons_mochila] = codigo;
        mochila->pokemons_mochila++;
    }
}

/**
 * @brief Função responsável por visualizar os pokemons da mochila
 * 
 * @param posicao Passa como argumento da função, um numero do tipo int para identificar uma posição que representa um pokemon na mochila
 * @param mochila Passa como argumento da função, um ponteiro para tipo struct Mochila
 * @param pokedex Passa como argumento da função, um ponteiro para tipo struct Pokedex
 */
void visualizar_mochila(int posicao, Mochila* mochila, Pokedex* pokedex){
    pesquisar_na_pokedex(mochila->codigos_pokemon[posicao], &pokedex);
}