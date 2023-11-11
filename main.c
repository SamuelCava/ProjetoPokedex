




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

int main(){
	Pokedex pokedex;
	Mochila mochila;
	Colecao colecao;
	// verifica se já existe o arquivo e se n existir cria a pokedex em binario
	carregar_csv(722);
	
	abre_colecao(colecao);
	abre_mochila(mochila);
	abre_pokedex(pokedex);

	while (true){
		int opcao = menu_principal();
		switch (opcao){
		case 1:
			menu_pokedex();
			break;
		case 2:
			menu_colecao();
			break;
		case 3:
			menu_mochila();
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		
	}
	salva(mochila, colecao, pokedex);

    return 0;
}
