#include <stdio.h>
#include <stdlib.h>
#include <menu.h>

int intervalo(int a, int b){
    // fica pedindo o inteiro até que a <= x <= b;
    int x;
    scanf("%d", &x);
    while (!(a <= x && x <= b)){
        scanf("%d", &x);
    }
    return x;
}


int menu_pokedex(){
    // (inserir/listar/pesquisar/alterar/exclui
    int qtd_opcoes = 5;
    printf("[1] inserir\n");
    printf("[2] listar\n");
    printf("[3] pesquisar\n");
    printf("[4] alterar\n");
    printf("[5] inserir\n");
    int opcao = intervalo(1, qtd_opcoes);
    return opcao;
}

int menu_colecao(){
    int qtd_opcoes = 5;
    printf("[1] inserir\n");
    printf("[2] listar\n");
    printf("[3] pesquisar\n");
    printf("[4] alterar\n");
    printf("[5] inserir\n");
    int opcao = intervalo(1, qtd_opcoes);
    return opcao;
}

int menu_mochila(){
    int qtd_opcoes = 2;
    printf("[1] mudar pokemon\n");
    printf("[2] ver pokemon\n");
    int opcao = intervalo(1, qtd_opcoes);
    return opcao;
}



int menu_principal(){
    int qtd_opcoes = 7;
    printf("[1] pokedex\n");
    printf("[2] colecao\n");
    printf("[3] mochila\n");
    printf("[4] exibir itens\n");
    printf("[5] batalha pokemon\n");
    printf("[6] salvar progresso\n");
    printf("[7] sair\n");
    int opcao = intervalo(1, qtd_opcoes);
    return opcao;
}
