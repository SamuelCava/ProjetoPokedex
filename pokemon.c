/**
 * @file pokemon.c
 * @author Leonardo Dal Poz Cardoso (lcardoso.2005@alunos.utfpr.edu.br) e Samuel Assunção Cavalherie (samuelcavalherie@alunos.utfpr.edu.br)
 * @brief Arquivo responsável por armazenar função que faz o registro de um novo pokemon
 * @version 0.1
 * @date 2023-11-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "pokemon.h"
#include "pokedex.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * @brief Função responsável por registrar um novo pokemon no jogo
 * 
 * @param pokemon Passa como argumento da função, um ponteiro para tipo struct Pokemon
 */
void pede_pokemon(Pokemon* pokemon, int tem_numero){
    if (tem_numero == 0){
        printf("digite o numero do pokemon: ");
        scanf("%d", &pokemon->numero);
    }
    

    

    printf("digite o nome do pokemon: ");
    setbuf(stdin, NULL);
    fgets(pokemon->nome, 29, stdin);
    pokemon->nome[strcspn(pokemon->nome,"\n")]='\0';

    printf("digite o primeiro tipo do pokemom: ");
    fgets(pokemon->tipo1, 29, stdin);
    pokemon->tipo1[strcspn(pokemon->tipo1,"\n")]='\0';  
    setbuf(stdin, NULL);
    printf("digite o segundo tipo do pokemon ou NULL");
    fgets(pokemon->tipo2, 29, stdin);
    pokemon->tipo2[strcspn(pokemon->tipo2,"\n")]='\0';  
    setbuf(stdin, NULL);
    printf("digite o total do pokemon: ");
    scanf("%d", &pokemon->total);
    printf("digite o hp do pokemon");
    scanf("%d", &pokemon->hp);


    printf("digite o ataque do pokemon:");
    scanf ("%d", &pokemon->ataque);

    printf("digite a defesa do pokemon:");
    scanf("%d", &pokemon->defesa);

    printf("digite o ataque especial do pokemon:");
    scanf("%d", &pokemon->ataque_especial);
    printf("digite a defesa especial do pokemon:");
    scanf("%d", &pokemon->defesa_especial);
    // ,velocidade ,geracao ,lendario ,cor     ,altura_m ,peso_kg ,taxa_captura
    printf("digite a velocidade do pokemon");
    scanf("%d", &pokemon->velocidade);

    printf("digite a geração do pokemon");
    scanf("%d", &pokemon->geracao);

    printf("digite a cor do pokemon: ");
    setbuf(stdin, NULL);
    fgets(pokemon->cor, 29, stdin);
    pokemon->cor[strcspn(pokemon->cor,"\n")]='\0';
    printf("digite a altura em metros do pokemon: ");
    scanf("%f", &pokemon->altura);
    printf("digite o peso do pokemon em kilos: ");
    scanf("%f", &pokemon->peso);

    printf("digite a taxa de captura do pokemon: ");
    scanf("%d", &pokemon->taxa_captura);
    printf("digite o codigo do pokemon que é a pre evolucao desse: ");
    scanf("%d", &pokemon->pre_evolucao);

    printf("digite o codigo do pokemon que é a proxima evolucao desse:");
    scanf("%d", &pokemon->proxima_evolucao);
}

void copia_pokemon(Pokemon* destino, Pokemon* fonte){
    destino->numero;
    // mudar esse 20
    strcpy(destino->nome, fonte->nome);
    strcpy(destino->tipo1, fonte->tipo1);
    strcpy(destino->tipo2, fonte->tipo2);
    destino->total = fonte->total;
    destino->hp = fonte->hp;
    destino->ataque = fonte->ataque;
    destino->defesa = fonte->defesa;
    destino->ataque_especial = fonte->ataque_especial;
    destino->defesa_especial = fonte->defesa_especial;
    destino->velocidade = fonte->velocidade;
    destino->geracao = fonte->geracao;
    destino->lendario = fonte->lendario ; // na verdade é bool aqui
    strcpy(destino->cor, fonte->cor);
    destino->altura = fonte->altura;
    destino->peso = fonte->peso;
    destino->taxa_captura = fonte->taxa_captura;
    destino->proxima_evolucao = fonte->proxima_evolucao;
    destino->pre_evolucao = fonte->pre_evolucao;
}