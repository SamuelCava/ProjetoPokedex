/**
 * @file abre_arquivo.c
 * @author Leonardo Dal Poz Cardoso (lcardoso.2005@alunos.utfpr.edu.br) e Samuel Assunção Cavalherie (samuelcavalherie@alunos.utfpr.edu.br)
 * @brief Arquivo responsável por ler as informações registradas na coleção, mochila e pokedex durante o jogo
 * @version 0.1
 * @date 2023-11-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#include "pokedex.h"
#include "mochila.h"
#include "pokemon.h"
#include "colecao.h"

/**
 * @brief Função responsável por ler as informações registradas no arquivo mochila
 * 
 * @param mochila Passa como argumento da função, um ponteiro para tipo struct Mochila
 */

void abre_mochila(Mochila* mochila){
    // inicializar mochila com qtd = 0 se n tiver o mochila.dat
    FILE *arq;
    arq = fopen("mochila.dat", "rb");
    if (arq == NULL){
        perror("Erro para abrir o arquivo.");      
        exit(1);   
    }// if
    int quantidade_mochila;
    fread(&quantidade_mochila, sizeof(int), 1, arq);
    mochila->pokemons_mochila = quantidade_mochila;
    for (int i = 0; i < quantidade_mochila; i++){
        int codigo;
        fread(&codigo, sizeof(int), 1, arq);
        mochila->codigos_pokemon[i] = codigo;
    }
}

/**
 * @brief Função responsável por ler as informações registradas no arquivo pokedex
 * 
 * @param pokedex Passa como argumento da função, um ponteiro para tipo struct Pokedex
 */

void abre_pokedex(Pokedex* pokedex){
    FILE *arq;
    arq = fopen("pokedex.dat", "rb");
     if (arq == NULL){
        perror("Erro para abrir o arquivo.");      
        exit(1);   
    }// if
    // sei que a primeira coisa sempre é um número então vou verificando se 
    // numero ,nome        ,tipo1    ,tipo2    ,total ,hp  ,ataque ,defesa ,ataque_especial ,
    // defesa_especial ,velocidade ,geracao ,lendario ,cor     ,altura_m ,peso_kg ,taxa_captura
    int numero;
    Pokemon pokemon;
    while (fread(&numero, sizeof(int), 1, arq) == 1){
        pokemon.numero = numero;
        printf("n:%d\n", numero);
        fread(pokemon.nome, sizeof(char), 30, arq);
        fread(pokemon.tipo1, sizeof(char), 30, arq);
        fread(pokemon.tipo2, sizeof(char), 30, arq);
        fread(&pokemon.total, sizeof(int), 1, arq);
        fread(&pokemon.hp, sizeof(int), 1, arq);
        fread(&pokemon.ataque, sizeof(int), 1, arq);
        fread(&pokemon.defesa, sizeof(int), 1, arq);
        fread(&pokemon.ataque_especial, sizeof(int), 1, arq);
        fread(&pokemon.defesa_especial, sizeof(int), 1, arq);
        fread(&pokemon.velocidade, sizeof(int), 1, arq);
        fread(&pokemon.geracao, sizeof(int), 1, arq);
        fread(&pokemon.lendario, sizeof(int), 1, arq);
        fread(pokemon.cor, sizeof(char), 30, arq);
        fread(&pokemon.altura, sizeof(double), 1, arq);
        fread(&pokemon.peso, sizeof(double), 1, arq);
        fread(&pokemon.taxa_captura, sizeof(int), 1, arq);
        fread(&pokemon.pre_evolucao, sizeof(int), 1, arq);
        fread(&pokemon.proxima_evolucao, sizeof(int), 1, arq);
        inserir_na_pokedex(&pokemon, pokedex);
    }
}

/**
 * @brief Função responsável por ler as informações registradas no arquivo coleção
 * 
 * @param colecao Passa como argumento da função, um ponteiro para tipo struct Colecao
 */

void abre_colecao(Colecao* colecao){
    FILE *arq;
    arq = fopen("colecao.dat", "rb");
    if (arq == NULL){
        perror("Erro para abrir o arquivo.");      
        exit(1);   
    }// if
    int qtd_colecao;
    fread(&qtd_colecao, sizeof(int), 1, arq);
    for (int i = 0; i < qtd_colecao; i++){
        int codigo;
        fread(&codigo, sizeof(int), 1, arq);
        inserir_colecao(codigo, colecao);
    }
}
