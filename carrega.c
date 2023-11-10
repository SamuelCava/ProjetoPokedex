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

void carregar_csv(Pokemon pokemon[], int tamanho){

  //  void carregar(Pokemon vetor_pokemons[]){


        FILE *arquivo;

    // Abrir arquivo csv
        arquivo = fopen("pokedex.csv", "r+");              // Modo (r)

    // Testar abertura
        if (arquivo == NULL){
            perror("Erro para abrir o arquivo.");      
            exit(1);   
        }// if
    
        for (int i = 0; i < tamanho; i++){
            fscanf(arquivo, "%d ,", &pokemon[i].numero);
            fscanf(arquivo, " %s , ", pokemon[i].nome);
            pokemon[i].nome[strcspn(pokemon[i].nome, " , ")] = '\0';
            fscanf(arquivo, " %s , ", pokemon[i].tipo1);
            pokemon[i].tipo1[strcspn(pokemon[i].tipo1, " , ")] = '\0';
            fscanf(arquivo, " %s , ", pokemon[i].tipo2);
            pokemon[i].tipo2[strcspn(pokemon[i].tipo2, " , ")] = '\0';
            fscanf(arquivo, "%d ,", &pokemon[i].total);
            fscanf(arquivo, "%d ,", &pokemon[i].ataque);
            fscanf(arquivo, "%d ,", &pokemon[i].defesa);
            fscanf(arquivo, "%d ,", &pokemon[i].ataque_especial);
            fscanf(arquivo, "%d ,", &pokemon[i].defesa_especial);
            fscanf(arquivo, "%d ,", &pokemon[i].velocidade);
            fscanf(arquivo, "%d ,", &pokemon[i].geracao);
            fscanf(arquivo, "%d ,", &pokemon[i].lendario);
            fscanf(arquivo, " %s , ", pokemon[i].cor);
            pokemon[i].cor[strcspn(pokemon[i].cor, " , ")] = '\0';
            fscanf(arquivo, "%f ,", &pokemon[i].altura);
            fscanf(arquivo, "%f ,", &pokemon[i].peso);
            fscanf(arquivo, "%d ,", &pokemon[i].taxa_captura);
        }//for
        
        for(int i = 0; i < tamanho; i++){
            printf("%d o %s tem %s tipo1 e %s tipo2.\n", pokemon[i].numero, pokemon[i].nome, pokemon[i].tipo1, pokemon[i].tipo2);
            printf("Seu ataque %d e defesa %d. Ataque especial %d e Defesa especial %d com velocidade %d\n", pokemon[i].ataque, pokemon[i].defesa,  pokemon[i].ataque_especial,  pokemon[i].defesa_especial,  pokemon[i].velocidade);
            
        }//for
}// funcao carregar_csv

int main(){
// Gerar vetor para variáveis pokemon
    int tamanho = 722;
    Pokemon pokemon[tamanho];

    carregar_csv(pokemon, tamanho);

    return 0;
}//main
