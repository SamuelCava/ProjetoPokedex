#ifndef MENU_H
#define MENU_H
#include "mochila.h"
#include "colecao.h"
#include "pokedex.h"
int menu_principal();

void menu_colecao(Colecao* colecao, Pokedex* pokedex);
void menu_pokedex(Pokedex* pokedex);
int menu_mochila(Mochila* mochila, Pokedex* pokedex);
#endif