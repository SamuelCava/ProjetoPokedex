#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"


int main(){
    const int width = 800;
	const int height = 500;
	InitWindow(width, height, "pokemon");
    int menu = 1;
    int opcao = 0;
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);
        switch (menu){
        case 1:
            DrawText(TextFormat(">"), 20, height/4-20-40*opcao, 40, VIOLET);
            DrawText(TextFormat("POKEDEX"),(width/2) - MeasureText("POKEDEX",40)/2, height/4-20, 40, VIOLET);
            DrawText(TextFormat("COLECAO"),(width/2) - MeasureText("COLECAO",40)/2, height/4+20, 40, VIOLET);
            DrawText(TextFormat("MOCHILA"),(width/2) - MeasureText("MOCHILA",40)/2, height/4+60, 40, VIOLET);
            DrawText(TextFormat("ITENS"),(width/2) - MeasureText("ITENS",40)/2, height/4+100, 40, VIOLET);
            DrawText(TextFormat("BATALHA"),(width/2) - MeasureText("BATALHA",40)/2, height/4+140, 40, VIOLET);
            DrawText(TextFormat("SALVAR PROGRESSO"),(width/2) - MeasureText("SALVAR PROGRESSO",40)/2, height/4+180, 40, VIOLET);
            DrawText(TextFormat("SAIR"),(width/2) - MeasureText("SAIR",40)/2, height/4+220, 40, VIOLET);
            break;
        
        default:
            break;
        }
        if (IsKeyPressed(KEY_UP)) opcao++;
        if (IsKeyPressed(KEY_DOWN)) opcao--;
        EndDrawing();
    }
    return 0;
}