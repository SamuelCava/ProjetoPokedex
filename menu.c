#include <stdio.h>
#include <stdlib.h>
#include <menu.h>

int menu_principal(){
    printf("[1] exibir pokedex");
    printf("[2] exibir mochila");
    printf("[3] exibir itens");
    printf("[4] batalha pokemon");
    int opcao;
    scanf("%d", &opcao);
    return opcao;
}



int main(){
    return 0;
}
