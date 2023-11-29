#include "raylib.h"
#include "pokemon.h"
#include "pokedex.h"
#include "funcoes_raylib.h"
#include <stdio.h>
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
void menu_raylib(int comeco, int* opcao, int qtd_opcoes, int fontsz, char opcoes[][30]){
    if (*opcao > qtd_opcoes-1) *opcao = qtd_opcoes-1;
    if (*opcao < 0) *opcao = 0;
    DrawText(TextFormat(">"), 20, comeco + (*opcao)*fontsz, fontsz, VIOLET);
    for (int i = 0; i < qtd_opcoes; i++){
        DrawText(TextFormat(opcoes[i]), 40, comeco + fontsz*i, fontsz, VIOLET);
    }
}
//
//numero ,nome        ,tipo1    ,tipo2    ,total ,hp  ,ataque ,defesa ,ataque_especial ,defesa_especial ,
//velocidade ,geracao ,lendario ,cor     ,altura_m ,peso_kg ,taxa_captura
void mostra_pokemon(Pokemon* pokemon){
    char image_name[17] = "pokemons/000.png";
    image_name[11] = pokemon->numero%10;
    image_name[10] = (pokemon->numero%100)/10;
    image_name[9] = pokemon->numero/100;
    // 96 por 96 a imagem
    Texture2D pokemon_img = LoadTexture(image_name);
    DrawTexture(pokemon_img,  800/2-96, 4, WHITE);
    int fontsz = 20;
    char aux[30];
    sprintf(aux, "%d", pokemon->numero);
    DrawText(TextFormat(aux), 20, 100, fontsz, VIOLET);
    
    DrawText(TextFormat(pokemon->nome), 20, 100+fontsz, fontsz, VIOLET);
    DrawText(TextFormat(pokemon->tipo1), 20, 100+2*fontsz, fontsz, VIOLET);
    DrawText(TextFormat(pokemon->tipo2), 20, 100+3*fontsz, fontsz, VIOLET);
    DrawText(TextFormat(aux), 20, 100+4*fontsz, fontsz, VIOLET);
    sprintf(aux, "%d", pokemon->hp);
    DrawText(TextFormat(aux), 20, 100+5*fontsz, fontsz, VIOLET);
    sprintf(aux, "%d", pokemon->ataque);
    DrawText(TextFormat(aux), 20, 100+6*fontsz, fontsz, VIOLET);
    sprintf(aux, "%d", pokemon->defesa);
    DrawText(TextFormat(aux), 20, 100+7*fontsz, fontsz, VIOLET);
    sprintf(aux, "%d", pokemon->ataque_especial);
    DrawText(TextFormat(aux), 20, 100+8*fontsz, fontsz, VIOLET);
    sprintf(aux, "%d", pokemon->defesa_especial);
    DrawText(TextFormat(aux), 20, 100+9*fontsz, fontsz, VIOLET);
    sprintf(aux, "%d", pokemon->velocidade);

    DrawText(TextFormat(aux), 20, 100+10*fontsz, fontsz, VIOLET);
    sprintf(aux, "%d", pokemon->geracao);
    DrawText(TextFormat(aux), 20, 100+11*fontsz, fontsz, VIOLET);
    sprintf(aux, "%d", pokemon->lendario);
    DrawText(TextFormat(aux), 20, 100+12*fontsz, fontsz, VIOLET);
    DrawText(TextFormat(pokemon->cor), 20, 100+13*fontsz, fontsz, VIOLET);
    sprintf(aux, "%f", pokemon->altura);
    DrawText(TextFormat(aux), 20, 100+14*fontsz, fontsz, VIOLET);
    sprintf(aux, "%f", pokemon->peso);
    DrawText(TextFormat(aux), 20, 100+15*fontsz, fontsz, VIOLET);
    sprintf(aux, "%d", pokemon->taxa_captura);
    DrawText(TextFormat(aux), 20, 100+16*fontsz, fontsz, VIOLET);
}

void mostra_itens(int qtds[]){
    char arquivos[7][30] = {"itens/20hp.png", "itens/50hp.png", "itens/200hp.png", "itens/allhp.png", "itens/x1.png", "itens/x1,5.png", "itens/x2.png"};
    int img_height = 55;
    int fontsz = 55;
    for (int i = 0; i < 7; i++){
        Texture2D item = LoadTexture(arquivos[i]);
        DrawTexture(item, 4, img_height*i + 20, WHITE);
        DrawText(TextFormat(qtds[i]), 700, img_height*i, img_height, VIOLET);
    }
}


//void mostra_pokedex(Pokedex* pokedex){



void entrada_texto(char resultado[], int tmaximo){
    int key = GetCharPressed();
    int letterCount = 0;
    // Check if more characters have been pressed on the same frame
    while (key > 0)
    {
        // NOTE: Only allow keys in range [32..125]
        if ((key >= 32) && (key <= 125) && (letterCount < tmaximo))
        {
            resultado[letterCount] = (char)key; 
            resultado[letterCount+1] = '\0'; // Add null terminator at the end of the string.
            letterCount++;
        }

        key = GetCharPressed();  // Check next character in the queue
    }

    if (IsKeyPressed(KEY_BACKSPACE))
    {
        letterCount--;
        if (letterCount < 0) letterCount = 0;
        resultado[letterCount] = '\0';
    }


}
//ray
void perfil(char nome[30], int numero, int linha, int coluna){
    Texture2D img = LoadTexture(numero);
    int fontsz = 40;
    DrawTexture(img, coluna*(96+21), linha*(96+40+21), WHITE);
    DrawText(TextFormat(nome), coluna*(96+21), linha*(96+40+21) + 96, fontsz, VIOLET);
}

// cada pagina tem 3*7 = 21 pokemons
void listar(char nomes[][30], int numeros[], int qtd, int pagina){
    int linha = 0;
    int coluna = 0;
    for (int i = pagina*(3*7); i < MIN(qtd, (pagina+1)*21); i++){
        perfil(nomes[i], numeros[i], linha, coluna);
        coluna++;
        if (coluna == 7){
            linha ++;
            coluna = 0;
        }
    }
}


//ray
void pede(char mensagem[60], char* resultado){
    ClearBackground(WHITE);
    int fontsz = 40;
    DrawText(TextFormat(mensagem), 0, 200, fontsz, VIOLET);
    int contagem = 0;
    while(1 == 1){
        int key = GetCharPressed();
        if (key >= 32 && key <= 125){
            resultado[contagem] = (char)key;
            resultado[contagem+1] = '\0';
            contagem++;
        }
        if (isKeyPressed(KEY_BACKSPACE)){
            contagem--;
            resultado[contagem] = '\0';
        }
        if (isKeyPressed(KEY_ENTER)){
            if (contagem > 0){
                break;
            }
        }
        DrawText(TextFormat(resultado), 0, 300, fontsz, VIOLET);
    } 
}  
