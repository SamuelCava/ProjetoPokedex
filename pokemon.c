#include "pokemon.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void pede_pokemon(Pokemon* pokemon){
    printf("digite o numero do pokemon: ");
    scanf("%d", &pokemon->numero);
    printf("digite o nome do pokemon: ");
    fgets(pokemon->nome, 29, stdin);
    pokemon->nome[strcspn(pokemon->nome,"\n")]='\0';

    printf("digite o primeiro tipo do pokemom: ");
    fgets(pokemon->tipo1, 29, stdin);
    pokemon->tipo1[strcspn(pokemon->tipo1,"\n")]='\0';  
    printf("digite o segundo tipo do pokemon ou NULL");
    fgets(pokemon->tipo2, 29, stdin);
    pokemon->tipo2[strcspn(pokemon->tipo2,"\n")]='\0';  
    printf("digite o total do pokemon: ");
    scanf("%d", &pokemon->total);
    printf("digite o hp do pokemon");
    scanf("%d", &pokemon->hp);


    printf("digite o ataque do pokemon:");
    scanf ("%d", &pokemon->ataque);

    printf("digite a defesa do pokemon:");
    scanf("%d", &pokemon->defesa);

    printf("digite o ataque especial do pokemon:");
    scanf("%d", &pokemon->ataque_especial);
    printf("digite a defesa especial do pokemon:");
    scanf("%d", &pokemon->defesa_especial);
    // ,velocidade ,geracao ,lendario ,cor     ,altura_m ,peso_kg ,taxa_captura
    printf("digite a velocidade do pokemon");
    scanf("%d", &pokemon->velocidade);

    printf("digite a geração do pokemon");
    scanf("%d", &pokemon->geracao);

    printf("digite a cor do pokemon: ");
    fgets(pokemon->cor, 29, stdin);
    pokemon->cor[strcspn(pokemon->cor,"\n")]='\0';
    printf("digite a altura em metros do pokemon: ");
    scanf("%f", &pokemon->altura);
    printf("digite o peso do pokemon em kilos: ");
    scanf("%f", &pokemon->peso);

    printf("digite a taxa de captura do pokemon: ");
    scanf("%d", &pokemon->taxa_captura);
    printf("digite o codigo do pokemon que é a pre evolucao desse: ");
    scanf("%d", &pokemon->pre_evolucao);

    printf("digite o codigo do pokemon que é a proxima evolucao desse:");
    scanf("%d", &pokemon->proxima_evolucao);
}