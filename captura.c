#include "colecao.h"
#include "pokedex.h"
#include "pokemon.h"
#include "captura.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<time.h>

typedef struct{
    int pokebolas_comum;
    int pokebolas_greatball ;
    int pokebolas_ultraball;
}Pokebolas;


void captura_pokemon(int codigo_pokemon, Pokedex* pokedex, Colecao* colecao, Pokemon pokemon){

    Pokebolas pokebolas;

    pokebolas.pokebolas_comum = 350;
    pokebolas.pokebolas_greatball = 525;
    pokebolas.pokebolas_ultraball = 700;

    srand(time(NULL));
    int taxa;
    int captura = 0;
    int tentar = 1;
    int tipo_pokebola;
    int num_tentativa = rand() %1001;

    do{
        printf("Faça sua tentativa\n");
        printf("[1] Pokebola Comum\n[2] Great Ball\n[3] Ultra Ball\n");
        printf("Escolha o tipo da sua pokebola: ");
        scanf("%d", &tipo_pokebola);
        switch (tipo_pokebola){
        case 1:
            taxa = pokebolas.pokebolas_comum;
            break;
        case 2:
            taxa = pokebolas.pokebolas_greatball;
            break;
        case 3:
            taxa = pokebolas.pokebolas_ultraball;
            break;
        default:
            break;
        }//switch

        for (int i = 0; i < pokedex->qtd_cadastrados; i++){
            if (pokedex->pokemons[i].numero == codigo_pokemon){
                if (num_tentativa <= taxa){
                    printf("Parabéns! Capturou o %s\n", pokedex->pokemons[i].nome);
                    inserir_colecao(codigo_pokemon, colecao);
                    tentar = 0;
                }else{
                    printf("Não foi desta vez.\n Tentar novamente: [1] Sim [0] Não\n");
                    scanf("%d", &tentar);
                }
                
            }//if
        }//for

        srand(time(NULL));
        num_tentativa = rand() %1000;


    }while (tentar > 0);
    

}//funcao captura_pokemon
