
/**
 * @file colecao.c
 * @author Leonardo Dal Poz Cardoso (lcardoso.2005@alunos.utfpr.edu.br) e Samuel Assunção Cavalherie (samuelcavalherie@alunos.utfpr.edu.br)
 * @brief Arquivo responsável por armazenar as funções usadas para a coleção
 * @version 0.1
 * @date 2023-11-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include "colecao.h"
#include "pokedex.h"

/**
 * @brief Função responsável por iniciar a coleção
 * 
 * @param colecao Passa como argumento da função, um ponteiro para tipo struct Colecao
 */
void inicia_colecao(Colecao* colecao){
    colecao->tamanho = 10;
    colecao->codigo_capturados = (int*) calloc(colecao->tamanho, sizeof(int));
    if (colecao->codigo_capturados == NULL){
        printf("memoria insuficiente\n");
        exit(1);
    }
}
/**
 * @brief Função responsável por inserir um pokemon na coleção
 * 
 * @param codigo Passa como argumento da função, um numero do tipo int para identificar o código/índice que representa o pokemon
 * @param colecao Passa como argumento da função, um ponteiro para tipo struct Colecao
 */
void inserir_colecao(int codigo, Colecao* colecao){
    printf("x");
    for (int i = 0; i < colecao->capturados; i++){
        if (colecao->codigo_capturados[i] == codigo){
            return;
            // nesse caso eu já tenho aquele pokemon cadastrado
        }
    }
    // verifico se preciso aumentar o tamanho do meu vetor
    if (colecao->tamanho == colecao->capturados + 1){
        colecao->tamanho += 10;
        colecao->codigo_capturados = realloc(colecao->codigo_capturados, colecao->tamanho*sizeof(int));
    }
    colecao->capturados++;
    colecao->codigo_capturados[colecao->capturados-1] = codigo;
}
/**
 * @brief Função responsável por listar os pokemons na coleção
 * 
 * @param colecao Passa como argumento da função, um ponteiro para tipo struct Colecao
 * @param pokedex Passa como argumento da função, um ponteiro para tipo struct Pokedex
 */
// preciso escrever essa função pesquisa
void listar_colecao(Colecao* colecao, Pokedex* pokedex){
    for (int i = 0; i < colecao->capturados; i++){
        for (int j = 0; j < pokedex->qtd_cadastrados; j++){
            if(pokedex->pokemons[j].numero == colecao->codigo_capturados[i]){
                printf("nome: %s\n", pokedex->pokemons[j].nome);
                break;
            }
        }
    }
}

/**
 * @brief Função responsável por pesquisar um pokemon na coleção
 * 
 * @param codigo Passa como argumento da função, um numero do tipo int para identificar o código/índice que representa o pokemon
 * @param colecao Passa como argumento da função, um ponteiro para tipo struct Colecao
 */
// talvez deixar essa função mais legal 
void pesquisar_colecao(int codigo, Colecao* colecao){
    for (int i = 0; i < colecao->capturados; i++){
        if (colecao->codigo_capturados[i] == codigo){
            // achei ele
            printf("achei");
        }
    }
}

/**
 * @brief Função responsável por alterar um pokemon na coleção
 * 
 * @param codigo Passa como argumento da função, um numero do tipo int para identificar o código/índice que representa o pokemon
 * @param colecao Passa como argumento da função, um ponteiro para tipo struct Colecao
 */
// preciso ver como vou fazer isso tbm
void alterar_colecao(int codigo, Colecao* colecao){
    for (int i = 0; i < colecao->capturados; i++){
        if (colecao->codigo_capturados[i] == codigo){
            // achei ele
            printf("achei");
        }
    }
}

/**
 * @brief Função responsável por excluir um pokemon na coleção
 * 
 * @param codigo Passa como argumento da função, um numero do tipo int para identificar o código/índice que representa o pokemon
 * @param colecao Passa como argumento da função, um ponteiro para tipo struct Colecao
 */
void excluir_colecao(int codigo, Colecao* colecao){
    for (int i = 0; i < colecao->capturados; i++){
        if (colecao->codigo_capturados[i] == codigo){
            colecao->capturados--;
            // seria interssante reescrever aqui os valores
            for (int l = i; l < colecao->capturados; l++){
                colecao->codigo_capturados[l] = colecao->codigo_capturados[l+1];
            }
            if (colecao->tamanho - colecao->capturados > 10){
                colecao->tamanho -= 10;
                colecao->codigo_capturados = realloc(colecao->codigo_capturados, colecao->tamanho*sizeof(int));
            }
            return;
        }
    }
    printf("pokemon não encontrado\n");
}