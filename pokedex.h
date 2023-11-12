#include "pokemon.h"

typedef struct{
    int qtd_cadastrados;
    // tamanho representa o espaço de quantos int tenho pra usar
    int tamanho = 10;
    Pokemon *pokemons;
    

}Pokedex;

void inicia_vetor(Pokedex pokedex);
void inserir_na_pokedex(Pokemon pokemon, Pokedex pokedex);
void listar_na_pokedex(Pokedex pokedex);
void pesquisar_na_pokedex(int codigo, Pokedex pokedex);
void alterar_na_pokedex(int codigo, Pokedex pokedex);
void excluir_na_pokedex(int codigo, Pokedex pokedex);
