
/**
 * @file main.c
 * @author Leonardo Dal Poz Cardoso (lcardoso.2005@alunos.utfpr.edu.br) e Samuel Assunção Cavalherie (samuelcavalherie@alunos.utfpr.edu.br)
 * @brief Arquivo responsavel por executar o jogo
 * @version 0.1
 * @date 2023-11-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "menu.h"
#include "carrega.h"
#include "colecao.h"
#include "mochila.h"
#include "pokemon.h"
#include "sair.h"
#include "abre_arquivo.h"
#include "batalha.h"

/**
 * @brief Função responsável por executar o programa
 * 
 * @return int Valor de retorno para encerrar a execução da função main
 */
int main(){
	Pokedex pokedex;
	Mochila mochila;
	Colecao colecao;
	// verifica se já existe o arquivo e se n existir cria a pokedex em binario
	carregar_csv();
	printf("teste");
	abre_colecao(&colecao);
	abre_mochila(&mochila);
	abre_pokedex(&pokedex);
	int gameloop = 1;
	printf("começando\n");
	while (gameloop == 1){
		int opcao = menu_principal();
		switch (opcao){
		case 1:
			menu_pokedex(&pokedex);
			break;
		case 2:
			menu_colecao(&colecao, &pokedex);
			break;
		case 3:
			menu_mochila(&mochila, &pokedex);
			break;
		case 4:
			break;
		case 5:
			batalha_par_impar(&mochila, &pokedex);
			break;
		case 6:
			// aqui salva o progresso
			salva(&mochila, &colecao, &pokedex);
			break;
		case 7:
			gameloop = 0;
			break;
		}
	}
	salva(&mochila, &colecao, &pokedex);

    return 0;
}
