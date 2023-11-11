
#include <stdlib.h>
#include<stdio.h>
#include "pokedex.h"
#include "pokemon.h"

void inicia_vetor(Pokedex pokedex){
    pokedex.capturados = (Pokemon*) calloc(pokedex.tamanho, sizeof(Pokemon));
    if (pokedex.capturados == NULL){
        printf("memoria insuficiente\n");
        exit(1);
    }
}



void inserir_na_pokedex(Pokemon pokemon, Pokedex pokedex){
    for (int i = 0; i < pokedex.capturados; i++){
        if (pokedex.capturados[i].numero == pokemon.numero){
            return;
            // nesse caso eu já tenho aquele pokemon cadastrado
        }
    }
    // verifico se preciso aumentar o tamanho do meu vetor
    if (pokedex.tamanho == pokedex.cadastrados + 1){
        pokedex.tamanho += 10;
        realloc(pokedex.cadastrados, pokedex.tamanho*sizeof(int));
    }
    pokedex.cadastrados++;
    // n posso uasr essa linha aqui
    pokedex.capturados[pokedex.cadastrados-1] = pokemon;

}

void listar_pokemons(Pokedex pokedex){
    for (int i = 0; i < pokedex.cadastrados; i++){
        // acho que eu quero pelo menos o nome do pokemon aqui
        // seria interessante usar outro arquivo pra cuidar dessas buscas, isso tbm é comum ao outro coisa la
        // da mochila
        printf("nome: %s", pokedex.capturados[i].nome);
    }
}

void pesquisar_pokemon(int codigo, Pokedex pokedex){
    for (int i = 0; i < colecao.capturados; i++){
        if (colecao.codigo_capturados[i] == codigo){
            // achei ele
            printf("achei");
        }
    }
}


void alterar_pokemon(int codigo, Colecao colecao){
    for (int i = 0; i < colecao.capturados; i++){
        if (colecao.codigo_capturados[i] == codigo){
            // achei ele
            printf("achei");
        }
    }
}


void excluir_pokemon(int codigo, Colecao colecao){
    for (int i = 0; i < colecao.capturados; i++){
        if (colecao.codigo_capturados[i] == codigo){
            // seria interssante reescrever aqui os valores
            for (int l = i; l < colecao.capturados; l++){
                colecao[l] = colecao[l+1];
            }
            if (colecao.tamanho - colecao.capturados > 10){
                colecao.tamanho -= 10;
                realloc(colecao.codigo_capturados, colecao.tamanho*sizeof(int));
            }
            return;
        }
    }
    printf("pokemon não encontrado\n");
}
