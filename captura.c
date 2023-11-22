#include "mochila.h"
#include "colecao.h"
#include "pokedex.h"
#include "pokemon.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<time.h>

typedef struct{
    int pokebolas_comum;
    int pokebolas_especial;
}Pokebolas;


void captura_pokemon(Pokedex* pokedex, Colecao* colecao, Pokemon* pokemon,int* codigo_pokemon, Pokebolas pokebolas){
    
    int captura = 0;
    int tentar = 1;
    int tipo_pokebola;
    int num_tentativa = rand() %1001;

    do{
        printf("Faça sua tentativa\n");
        printf("[1] Pokebola Comum\n[2] Pokebola Especial\n");
        printf("Escolha o tipo da sua pokebola: ");
        scanf("%d", &tipo_pokebola);
        switch (tipo_pokebola){
        case 1:
            pokebolas.pokebolas_comum;
            break;
        case 2:
            pokebolas.pokebolas_especial;
            break;
        default:
            break;
        }//switch

        for (int i = 0; i < pokedex->qtd_cadastrados; i++){
            if (pokedex->pokemons[i].numero == codigo_pokemon){
                if (num_tentativa <= pokemon->taxa_captura)
                {
                    /* code */
                }
                
            }//if
        }//for


        if (captura == 1){
            inserir_colecao(codigo_pokemon, colecao);
            tentar = 0;
        }else{
            printf("Não foi desta vez.\n Tentar novamente: [1] Sim [2] Não\n");
            scanf("%d", &tentar);
        }

    } while (tentar > 0);
    

}