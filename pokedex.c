
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pokedex.h"



void inicia_pokedex(Pokedex* pokedex){
    pokedex->tamanho = 10;
    pokedex-> qtd_cadastrados = 0;
    pokedex->pokemons = (Pokemon*) calloc(pokedex->tamanho, sizeof(Pokemon));
    if (pokedex->pokemons == NULL){
        printf("memoria insuficiente\n");
        exit(1);
    }
    printf("iniciou\n");
}

void muda_pokedex_posicao(int posicao, Pokemon* pokemon, Pokedex* pokedex){
    pokedex->pokemons[posicao].numero = pokemon->numero;
    strcpy(pokedex->pokemons[posicao].nome, pokemon->nome);
    strcpy(pokedex->pokemons[posicao].tipo1, pokemon->tipo1);
    strcpy(pokedex->pokemons[posicao].tipo2, pokemon->tipo2);
    strcpy(pokedex->pokemons[posicao].cor, pokemon->cor);
    //total ,hp  ,ataque ,defesa ,ataque_especial ,defesa_especial ,velocidade
    // ,geracao ,lendario ,cor     ,altura_m ,peso_kg ,taxa_captura
    //
    pokedex->pokemons[posicao].total = pokemon->total;
    pokedex->pokemons[posicao].hp = pokemon->hp;
    pokedex->pokemons[posicao].ataque = pokemon->ataque;
    pokedex->pokemons[posicao].defesa = pokemon->defesa;
    pokedex->pokemons[posicao].ataque_especial = pokemon->ataque_especial;
    pokedex->pokemons[posicao].defesa_especial = pokemon->defesa_especial;
    pokedex->pokemons[posicao].velocidade = pokemon->velocidade;
    pokedex->pokemons[posicao].geracao = pokemon->geracao;
    pokedex->pokemons[posicao].lendario = pokemon->lendario;
    pokedex->pokemons[posicao].altura = pokemon->altura;
    pokedex->pokemons[posicao].peso = pokemon->peso;
    pokedex->pokemons[posicao].taxa_captura = pokemon->taxa_captura;
    pokedex->pokemons[posicao].pre_evolucao = pokemon->pre_evolucao;
    pokedex->pokemons[posicao].proxima_evolucao = pokemon->proxima_evolucao;
}

void inserir_na_pokedex(Pokemon* pokemon, Pokedex* pokedex){
    for (int i = 0; i < pokedex->qtd_cadastrados; i++){
        if (pokedex->pokemons[i].numero == pokemon->numero){
            return;
            // nesse caso eu já tenho aquele pokemon cadastrado
        }
    }
    // verifico se preciso aumentar o tamanho do meu vetor
    if (pokedex->tamanho <= pokedex->qtd_cadastrados + 1){
        pokedex->tamanho += 10;
        pokedex->pokemons = realloc(pokedex->pokemons, pokedex->tamanho*sizeof(Pokemon));
    }
    pokedex->qtd_cadastrados++;
    // n posso uasr essa linha aqui
    muda_pokedex_posicao(pokedex->qtd_cadastrados-1, &pokemon, &pokedex);
}

void listar_na_pokedex(Pokedex* pokedex){
    for (int i = 0; i < pokedex->qtd_cadastrados; i++){
        // acho que eu quero pelo menos o nome do pokemon aqui
        // seria interessante usar outro arquivo pra cuidar dessas buscas, isso tbm é comum ao outro coisa la
        // da mochila
        // quando no ponto eu troco por -> não funciona
        printf("nome: %s", pokedex->pokemons[i].nome);
    }
}

void pesquisar_na_pokedex(int codigo, Pokedex* pokedex){
    for (int i = 0; i < pokedex->qtd_cadastrados; i++){
        if (pokedex->pokemons[i].numero == codigo){
            // achei ele
            printf("achei\n");
            printf("nome: %s\n", pokedex->pokemons[i].nome);
        }
    }
}


void alterar_na_pokedex(int codigo, Pokedex* pokedex){
    for (int i = 0; i < pokedex->qtd_cadastrados; i++){
        if (pokedex->pokemons[i].numero == codigo){
            Pokemon pokemon;
            pede_pokemon(&pokemon);
            muda_pokedex_posicao(i, &pokemon, &pokedex);
        }
    }
}


void excluir_na_pokedex(int codigo, Pokedex* pokedex){
    for (int i = 0; i < pokedex->qtd_cadastrados; i++){
        if (pokedex->pokemons[i].numero == codigo){
            pokedex->qtd_cadastrados--;
            // seria interssante reescrever aqui os valores
            for (int l = i; l < pokedex->qtd_cadastrados; l++){
                //colecao[l] = colecao[l+1];
            }
            if (pokedex->tamanho - pokedex->qtd_cadastrados > 10){
                pokedex->tamanho -= 10;
                pokedex->pokemons = realloc(pokedex->pokemons, pokedex->tamanho*sizeof(Pokemon));
            }
            return;
        }
    }
    printf("pokemon não encontrado\n");
}