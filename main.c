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
#include "funcoes_raylib.h"
#include "batalha.h"
/**
 * @brief Função responsável por executar o programa
 * 
 * @return int Valor de retorno para encerrar a execução da função main
 */


enum MENUS {PRINCIPAL, POKEDEX, COLECAO, MOCHILA, ITENS, BATALHA, BUSCA, ARQUIVOS};
int main(){
	Pokedex pokedex;
	Mochila mochila;
	Colecao colecao;
    Batalha batalha;
	// verifica se já existe o arquivo e se n existir cria a pokedex em binario
	carregar_csv();
	printf("teste");
	abre_colecao(&colecao);
	abre_mochila(&mochila);
	abre_pokedex(&pokedex);

    const int width = 800;
	const int height = 450;
	InitWindow(width, height, "pokemon");
    int menu = 0;
    int opcao = 0;
    const int qtd_menu_princial = 8;
    const int qtd_menu_pokedex = 5;
    const int qtd_menu_colecao = 5;
    const int qtd_menu_mochila = 2;
    int qtd_menu_busca = 2;
    // falta fazer salvar progresso
    char menu_principal_strings[8][30] = {"POKEDEX", "COLECAO", "MOCHILA","ITENS",  "BATALHA", "BUSCA", "SALVAR PROGRESSO", "SAIR"};
    char menu_pokedex_strings[5][30] = {"INSERIR", "LISTAR", "PESQUISAR", "ALTERAR", "EXCLUIR"};
    char menu_colecao_strings[5][30] = {"INSERIR", "LISTAR", "PESQUISAR", "ALTERAR", "EXCLUIR"};
    char menu_mochila_strings[2][30] = {"LISTAR", "TROCAR"};
    char menu_busca_strings[2][30] = {"GERACAO", "TIPO"};
    Texture2D background = LoadTexture("battle_background.png");
    int comeco;
    int fontsz = 40;
    int qtd_item[7] = {0, 0, 0, 0, 0, 0, 0};
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);
        switch (menu){
            case PRINCIPAL:
                comeco = 100;
                menu_raylib(comeco, &opcao, qtd_menu_princial, fontsz, menu_principal_strings);
            break;
            case POKEDEX:
                comeco = 200;
                menu_raylib(comeco, &opcao, qtd_menu_pokedex, fontsz, menu_pokedex_strings);
                break;
            case COLECAO:
                comeco = 200;
                menu_raylib(comeco, &opcao, qtd_menu_colecao, fontsz, menu_colecao_strings);
                break;
            case MOCHILA:
                comeco = 200;
                menu_raylib(comeco, &opcao, qtd_menu_mochila, fontsz, menu_mochila_strings);
                break;
            case ITENS:
                mostra_itens(qtd_item);
                break;
            case BATALHA:
                inicia_batalha(&pokedex, &mochila, &batalha);
                break;
            case BUSCA:
                menu_raylib(comeco, &opcao, qtd_menu_busca, fontsz, menu_busca_strings);
                break;

            default:
                break;
            }
        EndDrawing();
        if (IsKeyPressed(KEY_UP)) opcao--;
        if (IsKeyPressed(KEY_DOWN)) opcao++;
        if (IsKeyPressed(KEY_ENTER)){
            switch (menu){
            case PRINCIPAL:
                menu = opcao + 1;
            break;
            case POKEDEX:
				menu_pokedex(&pokedex, opcao);
            case COLECAO:
                menu_colecao(&colecao, &pokedex, opcao);
                break;
            case MOCHILA:
                menu_mochila(&mochila, &pokedex, opcao);
                break;
            case ITENS:
                
                break;
            case BATALHA:
                
                break;
            case BUSCA:
                break;

            default:
                break;
            }
        }
        
    }
	salva(&mochila, &colecao, &pokedex);
    return 0;
}
