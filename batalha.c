#include "batalha.h"
#include <string.h>

void inicia_batalha(Pokedex* pokedex, Mochila* mochila, Batalha* batalha){
    for (int i = 0; i < mochila->pokemons_mochila; i++){
        for (int j = 0; j < pokedex->qtd_cadastrados; j++){
            if (mochila->codigos_pokemon[i] == pokedex->pokemons[j].numero){
                batalha->numeros[i] = mochila->codigos_pokemon[i];
                batalha->ataques[i] = pokedex->pokemons[j].ataque;
                batalha->defesas[i] = pokedex->pokemons[j].defesa;
                batalha->vidas[i] = pokedex->pokemons[j].hp;
                batalha->velocidades[i] = pokedex->pokemons[j].velocidade;
                strcpy(batalha->nomes[i], pokedex->pokemons[j].nome);
            }
        }

    }
}