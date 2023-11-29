#ifndef FUNCRAY_H
#define FUNCRAY_H

#include "pokemon.h"

void menu_raylib(int comeco, int* opcao, int qtd_opcoes, int fontsz, char opcoes[][30]);
void mostra_pokemon(Pokemon* pokemon);
void mostra_itens(int qtds[]);
//bool IsAnyKeyPressed();
void entrada_texto(char resultado[], int tmaximo);
void perfil(char nome[30], int numero, int linha, int coluna);
void pede(char mensagem[60], char* resultado);
void listar(char nomes[][30], int numeros[], int qtd, int pagina);
#endif