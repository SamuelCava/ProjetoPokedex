
#include <stdlib.h>
#include<stdio.h>
#include "pokedex.h"
#include "pokemon.h"

void inicia_vetor(Pokedex pokedex){
    pokedex.pokemons = (Pokemon*) calloc(pokedex.tamanho, sizeof(Pokemon));
    if (pokedex.pokemons == NULL){
        printf("memoria insuficiente\n");
        exit(1);
    }
}



void inserir_na_pokedex(Pokemon pokemon, Pokedex pokedex){
    for (int i = 0; i < pokedex.qtd_cadastrados; i++){
        if (pokedex.pokemons[i].numero == pokemon.numero){
            return;
            // nesse caso eu já tenho aquele pokemon cadastrado
        }
    }
    // verifico se preciso aumentar o tamanho do meu vetor
    if (pokedex.tamanho == pokedex.qtd_cadastrados + 1){
        pokedex.tamanho += 10;
        realloc(pokedex.qtd_cadastrados, pokedex.tamanho*sizeof(Pokemon));
    }
    pokedex.qtd_cadastrados++;
    // n posso uasr essa linha aqui
    pokedex.pokemons[pokedex.qtd_cadastrados-1] = pokemon;

}

void listar_na_pokedex(Pokedex pokedex){
    for (int i = 0; i < pokedex.qtd_cadastrados; i++){
        // acho que eu quero pelo menos o nome do pokemon aqui
        // seria interessante usar outro arquivo pra cuidar dessas buscas, isso tbm é comum ao outro coisa la
        // da mochila
        printf("nome: %s", pokedex.pokemons[i].nome);
    }
}

void pesquisar_na_pokedex(int codigo, Pokedex pokedex){
    for (int i = 0; i < pokedex.qtd_cadastrados; i++){
        if (pokedex.pokemons[i].numero == codigo){
            // achei ele
            printf("achei\n");
            printf("nome: %s\n", pokedex.pokemons[i].nome);
        }
    }
}


void alterar_na_pokedex(int codigo, Pokedex pokedex){
    for (int i = 0; i < pokedex.qtd_cadastrados; i++){
        if (pokedex.pokemons[i].numero == codigo){
            // achei ele
            printf("achei");
        }
    }
}


void excluir_na_pokedex(int codigo, Pokedex pokedex){
    for (int i = 0; i < pokedex.qtd_cadastrados; i++){
        if (pokedex.pokemons[i].numero == codigo){
            pokedex.qtd_cadastrados--;
            // seria interssante reescrever aqui os valores
            for (int l = i; l < pokedex.qtd_cadastrados; l++){
                //colecao[l] = colecao[l+1];
            }
            if (pokedex.tamanho - pokedex.qtd_cadastrados > 10){
                pokedex.tamanho -= 10;
                realloc(pokedex.pokemons, pokedex.tamanho*sizeof(int));
            }
            return;
        }
    }
    printf("pokemon não encontrado\n");
}
