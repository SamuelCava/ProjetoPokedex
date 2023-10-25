#include <stdio.h>
#include <stdlib.h>
#include <menu.h>

int menu_principal(){
    int qtd_opcoes = 6;
    printf("[1] exibir pokedex");
    printf("[2] exibir mochila");
    printf("[3] exibir itens");
    printf("[4] batalha pokemon");
    printf("[5] salvar progresso");
    printf("[6] sair");
    int opcao;
    scanf("%d", &opcao);
    return opcao;
}



int main(){
    return 0;
}
