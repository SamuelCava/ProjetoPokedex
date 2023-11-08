// arquivo responsavel em carregar as coisas quando entrar no jogo
/*
◦ A lista com os dados iniciais para o Pokédex será construída lendo os dados de um
arquivo .csv (valores separados por vírgula) disponibilizado que deve ser lido e
carregado em um vetor de tamanho dinâmico na primeira abertura do programa.
*/

/*
Abrir o arquivo.csv, reconhecer o seu tamanho, alocar memória e salvar em binário
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "pokemon.h"

void carregar(Pokemon){


    FILE *arquivo;

    Pokemon pokemon;
    int c;
    int cont_linha = 0;

    arquivo = fopen("pokedex.csv", "r");              // Modo (r)

// Testar abertura
    if (arquivo == NULL){
        perror("Erro para abrir o arquivo.");      
        exit(1);   
    }// if
    
// Identificar tamanho do arquivo csv e ler linha por linha
    while((c = fgetc(arquivo)) != EOF){
    // If para ignorar a primeira linha
        if(c == "\n"){
            cont_linha++;
        }//if
    // Ler as linhas do arquivo
        if(cont_linha > 1){                                                                             // OSB. Talvez tenha que arrumar o 9.2f do pokemon.altura. Na verdade os de float em geral.                              
            fscanf(arquivo, "%7d,%12s,%9s,%9s,%6d,%4d,%7d,%7d,%16d,%16d,%11d,%8d,%9d,%8s,%9.2f,%8.2f,%12d", &pokemon.numero, pokemon.nome, pokemon.tipo1, pokemon.tipo2, &pokemon.total, &pokemon.hp,
            &pokemon.ataque, &pokemon.defesa, &pokemon.ataque_especial, &pokemon.defesa_especial, &pokemon.velocidade, &pokemon.geracao, &pokemon.lendario, pokemon.cor, &pokemon.altura, &pokemon.peso, &pokemon.taxa_captura);
        }//if

        
        // Fazer um fscanf formatado para a linha do arquivo.csv e salvar nas respectivas variáveis da struct
    }// WHILE
