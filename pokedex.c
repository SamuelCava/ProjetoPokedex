/**
 * @file pokedex.c
 * @author Leonardo Dal Poz Cardoso (lcardoso.2005@alunos.utfpr.edu.br) e Samuel Assunção Cavalherie (samuelcavalherie@alunos.utfpr.edu.br)
 * @brief Arquivo responsável por armazenar as funções usadas para a pokedex
 * @version 0.1
 * @date 2023-11-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pokedex.h"


/**
 * @brief Função responsável por iniciar a pokedex
 * 
 * @param pokedex Passa como argumento da função, um ponteiro para tipo struct Pokedex
 */
void inicia_pokedex(Pokedex* pokedex){
    pokedex->tamanho = 10;
    pokedex-> qtd_cadastrados = 0;
    pokedex->pokemons = (Pokemon*) calloc(pokedex->tamanho, sizeof(Pokemon));
    if (pokedex->pokemons == NULL){
        printf("memoria insuficiente\n");
        exit(1);
    }
    printf("Iniciou o jogo e a pokedex =)\n");
}

/**
 * @brief Função responsável por mudar posição do pokemon dentro da pokedex
 * 
 * @param posicao Passa como argumento da função, um numero do tipo int para identificar o código/índice que representa o pokemon
 * @param pokemon Passa como argumento da função, um ponteiro para tipo struct Pokemon
 * @param pokedex Passa como argumento da função, um ponteiro para tipo struct Pokedex
 */
void muda_pokedex_posicao(int posicao, Pokemon* pokemon, Pokedex* pokedex){
    pokedex->pokemons[posicao].numero = pokemon->numero;
    strcpy(pokedex->pokemons[posicao].nome, pokemon->nome);
    strcpy(pokedex->pokemons[posicao].tipo1, pokemon->tipo1);
    strcpy(pokedex->pokemons[posicao].tipo2, pokemon->tipo2);
    strcpy(pokedex->pokemons[posicao].cor, pokemon->cor);
    //total ,hp  ,ataque ,defesa ,ataque_especial ,defesa_especial ,velocidade
    // ,geracao ,lendario ,cor     ,altura_m ,peso_kg ,taxa_captura
    //
    pokedex->pokemons[posicao].total = pokemon->total;
    pokedex->pokemons[posicao].hp = pokemon->hp;
    pokedex->pokemons[posicao].ataque = pokemon->ataque;
    pokedex->pokemons[posicao].defesa = pokemon->defesa;
    pokedex->pokemons[posicao].ataque_especial = pokemon->ataque_especial;
    pokedex->pokemons[posicao].defesa_especial = pokemon->defesa_especial;
    pokedex->pokemons[posicao].velocidade = pokemon->velocidade;
    pokedex->pokemons[posicao].geracao = pokemon->geracao;
    pokedex->pokemons[posicao].lendario = pokemon->lendario;
    pokedex->pokemons[posicao].altura = pokemon->altura;
    pokedex->pokemons[posicao].peso = pokemon->peso;
    pokedex->pokemons[posicao].taxa_captura = pokemon->taxa_captura;
    pokedex->pokemons[posicao].pre_evolucao = pokemon->pre_evolucao;
    pokedex->pokemons[posicao].proxima_evolucao = pokemon->proxima_evolucao;
}
/**
 * @brief Função responsável por inserir um pokemon na coleção
 * 
 * @param pokemon Passa como argumento da função, um ponteiro para tipo struct Pokemon
 * @param pokedex Passa como argumento da função, um ponteiro para tipo struct Pokedex
 */
void inserir_na_pokedex(Pokemon* pokemon, Pokedex* pokedex){
    for (int i = 0; i < pokedex->qtd_cadastrados; i++){
        if (pokedex->pokemons[i].numero == pokemon->numero){
            printf("Ja existe um pokemon neste registro\n");
            return;
            // nesse caso eu já tenho aquele pokemon cadastrado
        }
    }
    // verifico se preciso aumentar o tamanho do meu vetor
    if (pokedex->tamanho <= pokedex->qtd_cadastrados + 1){
        pokedex->tamanho += 10;
        pokedex->pokemons = realloc(pokedex->pokemons, pokedex->tamanho*sizeof(Pokemon));
    }
    pokedex->qtd_cadastrados++;
    // n posso uasr essa linha aqui
    muda_pokedex_posicao(pokedex->qtd_cadastrados-1, pokemon, pokedex);
}

/**
 * @brief Função responsável por listar os pokemons na pokedex
 * 
 * @param pokedex Passa como argumento da função, um ponteiro para tipo struct Pokedex
 */
void listar_na_pokedex(Pokedex* pokedex){
    for (int i = 0; i < pokedex->qtd_cadastrados; i++){
        // acho que eu quero pelo menos o nome do pokemon aqui
        // seria interessante usar outro arquivo pra cuidar dessas buscas, isso tbm é comum ao outro coisa la
        // da mochila
        // quando no ponto eu troco por -> não funciona
        printf("Os pokemons listados nesta versão do game são.\n");
        printf("Pokemon: %s\n", pokedex->pokemons[i].nome);
    }
}


/**
 * @brief Função responsável por pesquisar um pokemon na pokedex
 * 
 * @param codigo Passa como argumento da função, um numero do tipo int para identificar o código/índice que representa o pokemon
 * @param pokedex Passa como argumento da função, um ponteiro para tipo struct Pokedex
 */
void pesquisar_na_pokedex(int codigo, Pokedex* pokedex){
    for (int i = 0; i < pokedex->qtd_cadastrados; i++){
        if (pokedex->pokemons[i].numero == codigo){
            // achei ele
            printf("Pokemon encontrado\n");
            printf("O nome do pokemon é: %s\n", pokedex->pokemons[i].nome);
        }
    }
}
/**
 * @brief Função responsável por alterar um pokemon na pokedex
 * 
 * @param codigo Passa como argumento da função, um numero do tipo int para identificar o código/índice que representa o pokemon
 * @param pokedex Passa como argumento da função, um ponteiro para tipo struct Pokedex
 */
void alterar_na_pokedex(int codigo, Pokedex* pokedex){
    for (int i = 0; i < pokedex->qtd_cadastrados; i++){
        if (pokedex->pokemons[i].numero == codigo){
            Pokemon pokemon;
            pede_pokemon(&pokemon, 0);
            muda_pokedex_posicao(i, &pokemon, pokedex);
        }
    }
}

/**
 * @brief Função responsável por excluir um pokemon na pokedex
 * 
 * @param codigo Passa como argumento da função, um numero do tipo int para identificar o código/índice que representa o pokemon
 * @param pokedex Passa como argumento da função, um ponteiro para tipo struct Pokedex
 */
void excluir_na_pokedex(int codigo, Pokedex* pokedex){
    for (int i = 0; i < pokedex->qtd_cadastrados; i++){
        if (pokedex->pokemons[i].numero == codigo){
            pokedex->qtd_cadastrados--;
            // seria interssante reescrever aqui os valores
            for (int l = i; l < pokedex->qtd_cadastrados; l++){
                muda_pokedex_posicao(l, &pokedex->pokemons[l+1], pokedex);
                //colecao[l] = colecao[l+1];
            }
            if (pokedex->tamanho - pokedex->qtd_cadastrados > 10){
                pokedex->tamanho -= 10;
                pokedex->pokemons = realloc(pokedex->pokemons, pokedex->tamanho*sizeof(Pokemon));
            }
            return;
        }
    }
    printf("pokemon não encontrado\n");
}