#include "mochila.h"
#include "pokedex.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>   

typedef struct {
    int numero;
    // mudar esse 20
    char nome[30];
    char tipo1[30];
    char tipo2[30];
    int total;
    int hp;
    int ataque;
    int defesa;
    int ataque_especial;
    int defesa_especial;
    int velocidade;
    int geracao;
    int lendario; // na verdade é bool aqui
    char cor[30];
    float altura;
    float peso;
    int taxa_captura;
    int proxima_evolucao;
    int pre_evolucao;

}Pokemon;

void batalha_par_impar(Pokedex pokedex, Pokemon pokemons_jogador, Pokemon pokemons_adversario){
    
    int num_jogador;
    int escolha_jogador;
    int bonus_jogador = 0;
    int num_adversario;
    int bonus_adversario = 0;

    printf("Vai dar início a batalha por par ou ímpar!\n");
    printf("Seu adversario é o computador e para a batalha ser justa os pokemons serão iguais aos seus.\n");

    while (pokemons_jogador.hp > 0 && pokemons_adversario.hp > 0){

// Definindo o valor do adversario através da funcao RAND.
        srand((unsigned)time(NULL));
        num_adversario = 1 + (rand() % 100);

        printf("escolha Par ou ímpar:\n [1] Par\n [2] Ímpar\n");
        scanf("%d", &escolha_jogador);

        printf("Digite um número: ");
        scanf("%d", &num_jogador);

        if ((num_adversario + num_jogador) % 2 == 0){
            printf("Ganhou a vez. Você ataca!\n");
            if(escolha_jogador == 1){
                if (bonus_jogador <= 2){
                    pokemons_adversario.hp = pokemons_adversario.hp - pokemons_jogador.ataque;
                    bonus_jogador++;
                }else{
                    pokemons_adversario.hp = pokemons_adversario.hp - pokemons_jogador.ataque_especial;
                    bonus_jogador = 0;
                }//else
            }//if
        }else{
            printf("Perdeu a vez. O adversario ataca!\n");
            if (bonus_adversario <= 2){
                pokemons_jogador.hp = pokemons_jogador.hp - pokemons_adversario.ataque;
                bonus_adversario++;
            }else{
                pokemons_jogador.hp = pokemons_jogador.hp - pokemons_adversario.ataque_especial;
                bonus_adversario = 0;
            }//else
        }//else
    
    }//while
    printf("A batalha acabou.\n");
    if (pokemons_jogador.hp > 0){
        printf("Muito bem. Vitória!\n");
    }else{
        printf("Looser!!! Tente a próxima guerreiro.\n");
    }//else

}// função batalha_par_impar
