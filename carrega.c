// arquivo responsavel em carregar as coisas quando entrar no jogo
/*
◦ A lista com os dados iniciais para o Pokédex será construída lendo os dados de um
arquivo .csv (valores separados por vírgula) disponibilizado que deve ser lido e
carregado em um vetor de tamanho dinâmico na primeira abertura do programa.
*/

/*
Abrir o arquivo.csv, reconhecer o seu tamanho, alocar memória e salvar em binário
*/

typedef struct {
    int numero;
    // mudar esse 20
    char nome[20];
    char tipo1[20];
    char tipo[20];
    int total;
    int ataque;
    int defesa;
    int ataque_especial;
    int defesa_especial;
    int velocidade;
    int geracao;
    int lendario; // na verdade é bool aqui
    char cor[20];
    float altura;
    float peso;
    int taxa_captura;
    int proxima_evolucao;
    int pre_evolucao;

}Pokemon;

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "pokemon.h"

void carregar(Pokemon){


    FILE *arquivo;

    int c;

    char meu_texto[25] = "Batalha pokemons.";

    arquivo = fopen("dados.txt", "r");              // Modo (r)

    if (arquivo == NULL){
        perror("Erro para abrir o arquivo.");       // Comando para exibir mensagem de erro
        exit(1);    // Finaliza o programa
    }// if
    
    while((c = fgetc(arquivo)) != EOF){
        // Fazer um fscanf formatado para a linha do arquivo.csv e salvar nas respectivas variáveis da struct
    }// WHILE
