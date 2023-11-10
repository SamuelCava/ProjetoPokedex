/*
abre_arquivo é responsável por fazer a leitura do arquivo dos dados dos pokemons em binário

Em seguida vai armazenar esses dados em um vetor em memória alocada dinãmicamente
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "pokemon.h"


void abrir_arquivo(){

    FILE *arquivo;
    int pokemons_registrados;

// Usando a alocação dinâmica
    Pokemon* pokemon;
    int tamanho = 722;

    pokemon = (Pokemon*) malloc(tamanho* sizeof(Pokemon));
    if (pokemon == NULL){
        printf("Erro para alocar memória.\n");
        exit(1);
    }//if

// Abrir arquivo Pokedex 
    arquivo = fopen("pokedex.dat", "rb+");      // Leitura de Binário

    if (arquivo == NULL){
        perror("Erro ao abrir pokedex.\n");
        exit(1);
    }//if
    
// Ler o arquivo Pokedex
    for (int i = 0; i < tamanho; i++){

    // If para identificar o número de pokemons registrado da lista. Que sempre será um número na primeira linha
        if (i == 0){
            fread(&pokemons_registrados, sizeof(int), 1, arquivo);
        }//if
        
    // Ler dados dos pokemons
        fread(pokemon[i].nome, sizeof(char), 30, arquivo);
        fread(pokemon[i].tipo1, sizeof(char), 30, arquivo);
        fread(pokemon[i].tipo2, sizeof(char), 30, arquivo);
        fread(&pokemon[i].total, sizeof(int), 1, arquivo);
        fread(&pokemon[i].hp, sizeof(int), 1, arquivo);
        fread(&pokemon[i].ataque, sizeof(int), 1, arquivo);
        fread(&pokemon[i].defesa, sizeof(int), 1, arquivo);
        fread(&pokemon[i].ataque_especial, sizeof(int), 1, arquivo);
        fread(&pokemon[i].defesa_especial, sizeof(int), 1, arquivo);
        fread(&pokemon[i].velocidade, sizeof(int), 1, arquivo);
        fread(&pokemon[i].geracao, sizeof(int), 1, arquivo);
        fread(&pokemon[i].lendario, sizeof(int), 1, arquivo);
        fread(pokemon[i].cor, sizeof(char), 30, arquivo);
        fread(&pokemon[i].altura, sizeof(float), 1, arquivo);
        fread(&pokemon[i].peso, sizeof(float), 1, arquivo);
        fread(&pokemon[i].taxa_captura, sizeof(int), 1, arquivo);
        fread(&pokemon[i].proxima_evolucao, sizeof(int), 1, arquivo);
        fread(&pokemon[i].pre_evolucao, sizeof(int), 1, arquivo);

    }//for
    


    return;
}// função abrir_arquivo