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
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "funcoes_raylib.h"
//raylib
/**
 * @brief Função responsável por registrar um novo pokemon no jogo
 * 
 * @param pokemon Passa como argumento da função, um ponteiro para tipo struct Pokemon
 */
void pede_pokemon(Pokemon* pokemon, int tem_numero){
    printf("digite o numero do pokemon: ");
    char numero[30];
    if (tem_numero == 0){
        pede("digite o numero do pokemon: ", numero);
        pokemon->numero = atoi(numero);
    }
    
    pede("digite o nome do pokemon: ", pokemon->nome);
    pede("digite o primeiro tipo do pokemom: ", pokemon->tipo1);
    pede("digite o segundo tipo do pokemon ou NULL", pokemon->tipo2);
    pede("digite o total do pokemon: ", numero);
    pokemon->total = atoi(numero);
    pede("digite o hp do pokemon", numero);
    pokemon->hp = atoi(numero);

    pede("digite o ataque do pokemon:", numero);
    pokemon->ataque = atoi(numero);

    pede("digite a defesa do pokemon:", numero);
    pokemon->defesa = atoi(numero);

    pede("digite o ataque especial do pokemon:", numero);
    pokemon->ataque_especial = atoi(numero);

    pede("digite a defesa especial do pokemon:", numero);
    pokemon->defesa_especial = atoi(numero);

    pede("digite a velocidade do pokemon", numero);
    pokemon->velocidade = atoi(numero);

    pede("digite a geração do pokemon", numero);
    pokemon->geracao = atoi(numero);
    pede("digite a cor do pokemon: ", pokemon->cor);

    pede("digite a altura em metros do pokemon: ", numero);
    pokemon->altura = atof(numero);
    pede("digite o peso do pokemon em kilos: ", numero);
    pokemon->peso = atof(numero);
    pede("digite a taxa de captura do pokemon: ", numero);
    pokemon->taxa_captura = atoi(numero);
    pede("digite o codigo do pokemon que é a pre evolucao desse: ", numero);
    pokemon->pre_evolucao = atoi(numero);
    pede("qual o codigo do pokemon que é a proxima evolucao desse:", numero);
    pokemon->proxima_evolucao = atoi(numero);
}