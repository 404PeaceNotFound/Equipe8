#include <raylib.h>

int main(){

    InitWindow(1280, 720, "Primeiro Teste");
    SetTargetFPS(60);

    Rectangle BotaoStart = {50, 200, 250, 75};
    Rectangle BotaoQuit = {50, 300, 250, 75};
    Rectangle BotaoCredits = {50, 400, 250, 75};

    float RoundButton = 0.3f;
    int Segments = 8;


    while(WindowShouldClose() == false)
    {

        // Desenho
        BeginDrawing();
        ClearBackground(WHITE);

        //  Botões Menu
        DrawRectangleRounded(BotaoStart, RoundButton, Segments, RED);
        DrawRectangleRounded(BotaoQuit, RoundButton, Segments,  RED);
        DrawRectangleRounded(BotaoCredits, RoundButton, Segments, RED);

        //Texto dos Botões
        DrawText("Iniciar Jogo", 110, 225, 25, RAYWHITE);
        DrawText("Sair", 110, 325, 25, RAYWHITE);
        DrawText("Créditos", 110, 425, 25, RAYWHITE);




        EndDrawing();
    }

    
    
    CloseWindow();
    return 0; 
}