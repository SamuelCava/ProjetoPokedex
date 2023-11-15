/**
 * @file menu.c
 * @author  Leonardo Dal Poz Cardoso (lcardoso.2005@alunos.utfpr.edu.br) e Samuel Assunção Cavalherie (samuelcavalherie@alunos.utfpr.edu.br)
 * @brief Arquivo responsavel por armazenar as funções de menu do jogo
 * @version 0.1
 * @date 2023-11-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "mochila.h"
#include "colecao.h"
#include "pokedex.h"
#include "pokemon.h"

/**
 * @brief Função responsável por restringir a entrada de opção digitada pelo usuário, dentro do intervalo de opções disponíveis
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int intervalo(int a, int b){
    // fica pedindo o inteiro até que a <= x <= b;
    int x;
    scanf("%d", &x);
    while (!(a <= x && x <= b)){
        scanf("%d", &x);
    }
    return x;
}

/**
 * @brief Função responsável por exibir menu de opções da pokedex
 * 
 * @param pokedex Passa como argumento da função, um ponteiro para tipo struct Pokedex
 */
// verificado
void menu_pokedex(Pokedex* pokedex){
    // (inserir/listar/pesquisar/alterar/exclui
    int qtd_opcoes = 5;
    printf("[1] inserir\n");
    printf("[2] listar\n");
    printf("[3] pesquisar\n");
    printf("[4] alterar\n");
    printf("[5] excluir\n");
    int opcao = intervalo(1, qtd_opcoes);
    int codigo_pokemon;
    

    switch (opcao){
    case 1:
    // preciso pegar o pokemon aqui dentro
        Pokemon pokemon;
        pede_pokemon(&pokemon);
        inserir_na_pokedex(&pokemon, pokedex);
        break;
    case 2:
        listar_na_pokedex(pokedex);
        break;
    case 3:
        printf("Digite cógido do pokemon: ");
        scanf("%d", &codigo_pokemon);
        pesquisar_na_pokedex(codigo_pokemon, pokedex);
        break;
    case 4:
        printf("Digite cógido do pokemon: ");
        scanf("%d", &codigo_pokemon);
        alterar_na_pokedex(codigo_pokemon, pokedex);
        break;
    case 5:
        printf("Digite cógido do pokemon: ");
        scanf("%d", &codigo_pokemon);
        excluir_na_pokedex(codigo_pokemon, pokedex);
        break;
    default:
        printf("Opção invalida\n");
        //perror("Opção inválida\n");
        break;
    }//switch

    return;
}

/**
 * @brief Função responsável por exibir menu de opções da coleção
 * 
 * @param colecao Passa como argumento da função, um ponteiro para tipo struct Colecao
 * @param pokedex Passa como argumento da função, um ponteiro para tipo struct Pokedex
 */
// verificado
void menu_colecao(Colecao* colecao, Pokedex* pokedex){
    int qtd_opcoes = 5;
    // remvoer inserir repetido
    printf("[1] inserir\n");
    printf("[2] listar\n");
    printf("[3] pesquisar\n");
    printf("[4] alterar\n");
    printf("[5] excluir\n");
    int opcao = intervalo(1, qtd_opcoes);
    int codigo_pokemon;

    switch (opcao){
    case 1:
        printf("Digite cógido do pokemon: ");
        scanf("%d", &codigo_pokemon);
        inserir_colecao(codigo_pokemon, colecao);
        break;
    case 2:
        listar_colecao(colecao, pokedex);
        break;
    case 3:
        printf("Digite cógido do pokemon: ");
        scanf("%d", &codigo_pokemon);
        pesquisar_colecao(codigo_pokemon, colecao);
        break;
    case 4:
        printf("Digite cógido do pokemon: ");
        scanf("%d", &codigo_pokemon);
        alterar_colecao(codigo_pokemon, colecao);
        break;
    case 5:
        printf("Digite cógido do pokemon: ");
        scanf("%d", &codigo_pokemon);
        excluir_colecao(codigo_pokemon, colecao);
        break;
    default:
        perror("Opção inválida\n");
        break;
    }//switch

    return;
}

/**
 * @brief Função responsável por exibir menu de opções da mochila
 * 
 * @param mochila Passa como argumento da função, um ponteiro para tipo struct Mochila
 * @return int 
 */
int menu_mochila(Mochila* mochila){
    int qtd_opcoes = 2;
    printf("[1] mudar pokemon\n");
    printf("[2] ver pokemon\n");
    int opcao = intervalo(1, qtd_opcoes);
    switch (opcao){
    case 2:
        printf("digite a posicao que deseja visualizar: ");
        int posicao;
        scanf("%d", &posicao);
        visualizar_mochila(posicao, &mochila);
        break;
    
    default:
        break;
    }
    return opcao;
}

/**
 * @brief Função responsável por exibir menu de opções inicial
 * 
 * @return int Valor de retorno para indicar a opção escolhida
 */
int menu_principal(){
    int qtd_opcoes = 7;
    printf("[1] pokedex\n");
    printf("[2] colecao\n");
    printf("[3] mochila\n");
    printf("[4] exibir itens\n");
    printf("[5] batalha pokemon\n");
    printf("[6] salvar progresso\n");
    printf("[7] sair\n");
    int opcao = intervalo(1, qtd_opcoes);
    return opcao;
}