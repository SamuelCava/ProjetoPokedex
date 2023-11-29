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

    for (int i = 0; i < pokedex->qtd_cadastrados; i++){
            for (int j = 0; j < mochila->pokemons_mochila; j++){
                
            if (pokedex->pokemons[i].numero == mochila->codigos_pokemon[j]){

                pokemons_jogador = pokedex->pokemons[i];
                pokemons_adversario = pokedex->pokemons[i+1];
                
            }//if
                
        }//for
    }//for

    int num_jogador;
    int escolha_jogador;
    int bonus_jogador = 0;
    int num_adversario;
    int bonus_adversario = 0;
    int menu_batalha;

    //printf("Vai dar início a batalha por par ou ímpar!\n");
    //printf("Seu adversario é o computador e para a batalha os pokemons serão os próximos listados aos seus.\n");

    while (pokemons_jogador.hp > 0 && pokemons_adversario.hp > 0){

// Definindo o valor do adversario através da funcao RAND.
        srand((unsigned)time(NULL));
        num_adversario = 1 + (rand() % 100);
		char escolha[10];
		pede("Deseja curar ou batalha? [1] Curar [2] Batalha", escolha);
		menu_batalha = atoi(escolha);
		
        switch(&menu_batalha){
            case 1:
                mostrar_itens(qtd)
                break;
            case 2:
            pede("escolha Par ou Impar:\n [1] Impar\n [2] Par", escolha);
			escolha_jogador = atoi(escolha);
			pede("Digite um numero", escolha);
			num_jogador = atoi(escolha);
		
				if ((num_adversario + num_jogador) % 2 == (escolha_jogador % 2))){
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
			}//switch
	}//while
	printf("A batalha acabou.\n");
	if (pokemons_jogador.hp > 0){
		printf("Muito bem. Vitória!\n");
	}else{
		printf("Looser!!! Tente a próxima guerreiro.\n");
	}//else


}// função batalha_par_impar
