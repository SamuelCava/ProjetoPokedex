// programa que cuida das coisas que precisam ser feitas quando fecho o programa
/*

Ao sair do programa, todos os dados devem ser salvos em arquivos binários no HD e
1
recarregados novamente ao iniciar. Caso os arquivos não existam, eles devem ser
criados e uma mensagem de boas vindas deve ser apresentada ao usuário;

*/
#include <stdio.h>
#include <stdlib.h>
#include "mochila.h"
#include "pokedex.h"
#include "colecao.h"


void salva(Mochila mochila, Colecao colecao, Pokedex pokedex){
    FILE *arq = fopen("mochila.dat","wb");
    if(arq == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);// 1 significa erro
    }// if
    fwrite(&mochila.pokemons_mochila, sizeof(int), 1, arq);
    fwrite(mochila.codigos_pokemon, sizeof(int), mochila.pokemons_mochila, arq);
    fclose(arq);

    arq = fopen("colecao.dat", "wb");
    if (arq == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);// 1 significa erro
    }
    fwrite(&colecao.capturados, sizeof(int), 1, arq);
    fwrite(colecao.codigo_capturados, sizeof(int), colecao.capturados, arq);
    fclose(arq);
    
    arq = fopen("pokedex.dat", "wb");
    if (arq == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);// 1 significa erro
    }
    // escrever aqui para salvar o arquivo da pokedex em binario

}
