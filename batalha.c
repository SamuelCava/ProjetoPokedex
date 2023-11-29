#include "mochila.h"
#include "pokemon.h"
#include "pokedex.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>   

void pocao(Pokemon* pokemon, int vida){
    pokemon->hp += vida;
}


void batalha_par_impar(Mochila* mochila,Pokedex* pokedex, int qtd[]){
    
    Pokemon pokemons_jogador; 
    Pokemon pokemons_adversario;
    printf("Com qual pokemon deseja batalhar? ");
    for (int i = 0; i < mochila->pokemons_mochila; i++){
        for (int j = 0; j < pokedex->qtd_cadastrados; j++){
            if (pokedex->pokemons[i].numero == mochila->codigos_pokemon[j]){
                printf("[%d] %s\n", i+1, pokedex->pokemons[i].nome);
            }
        }
    }
    int escolha;
    scanf("%d", &escolha);
    for (int i = 0; i < pokedex->qtd_cadastrados; i++){
        if (pokedex->pokemons[i].numero == mochila->codigos_pokemon[escolha-1]){
            copia_pokemon(&pokemons_jogador, &pokedex->pokemons[i]);
            copia_pokemon(&pokemons_adversario, &pokedex->pokemons[i+1]);
        }
    }

    int num_jogador;
    int escolha_jogador;
    int bonus_jogador = 0;
    int num_adversario;
    int bonus_adversario = 0;
    int menu_batalha;

    printf("Vai dar início a batalha por par ou ímpar!\n");
    printf("Seu adversario é o computador e para a batalha os pokemons serão os próximos listados aos seus.\n");

    while (pokemons_jogador.hp > 0 && pokemons_adversario.hp > 0){

// Definindo o valor do adversario através da funcao RAND.
        srand((unsigned)time(NULL));
        num_adversario = 1 + (rand() % 100);

        printf("Deseja curar ou batalha? [1] Curar [2] Batalha\n");
        scanf("%d", &menu_batalha);

        switch(menu_batalha){
            case 1:
               // mostrar_itens(qtd);
                break;
            case 2:
            
            printf("escolha Par ou ímpar:\n [1] Ímpar\n [2] Par\n");
            scanf("%d", &escolha_jogador);
    
            printf("Digite um número: ");
            scanf("%d", &num_jogador);
    
            if ((num_adversario + num_jogador) % 2 == (escolha_jogador % 2)){
                printf("Ganhou a vez. Você ataca!\n");
                if (bonus_jogador <= 2){
                    pokemons_adversario.hp = pokemons_adversario.hp - pokemons_jogador.ataque;
                    bonus_jogador++;
                }else{
                    pokemons_adversario.hp = pokemons_adversario.hp - pokemons_jogador.ataque_especial;
                    bonus_jogador = 0;
                }//else
            }//if
            else{
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