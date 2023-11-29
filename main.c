/*
Nesta atividade os alunos deverão desenvolver um sistema que permita a um Mestre Pokémon
gerenciar: uma Pokédex contendo o catálogo de todos os pokémons conhecidos; uma coleção
contendo todos os pokémons que você possui e; sua mochila que possui os 6 pokémons que
ele pode carregar em uma batalha. O sistema deve ser desenvolvido utilizando a linguagem C e
os conceitos visto em sala de aula. A atividade deverá ser desenvolvida em trios
impreterivelmente.

◦ Caso os arquivos não existam, eles devem ser
criados e uma mensagem de boas vindas deve ser apresentada ao usuário;

◦ O sistema deverá exibir no menu uma opção de exportar ao dados das estruturas em
um arquivo texto no formato .CSV (separados por vírgula);

*/




/*
◦
// string formatada

fscanf depois tudo fread fwrite
// deixar para fazer as alterações no hd no final
feito: struct pokemon
Deverá permitir cadastrar
(inserir/listar/pesquisar/alterar/excluir) os Pokémons disponíveis para serem capturados.
Essa relação deve aumentar e diminuir dinamicamente.

◦ Deverá apresentar um menu inicial com as opções disponíveis. Caso necessário,
submenus. A interface deverá ser fácil e intuitiva, seja criativo, utilize cores e beeps :) .
Trate erros do usuário com mensagens e alertas;


◦ 
◦ O sistema deverá exibir no menu uma opção de exportar ao dados das estruturas em
um arquivo texto no formato .CSV (separados por v

*/
// fclose(arq);
// free()
// exportar para csv no menu

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
