#include <raylib.h>
#include <stdio.h>
#include "creditos.h"

int main(){

    // Inicialização
    InitWindow(1280, 720, "Princesa Não Encontrada");
    SetTargetFPS(60);
    InitAudioDevice();
    
    // Definições de Botões e Cores
    Rectangle BotaoStart = {-5, 300, 300, 60};
    Rectangle BotaoQuit = {-5, 400, 300, 60};
    Rectangle BotaoCredits = {-5, 500, 300, 60};
    Color CorBotao = { 30, 30, 30, 150 };
    Color CorBotaoSel = { 50, 50, 50, 255 };
    
    // Definições de Texto para usar no MeasureText
    const int FONT_SIZE = 20;
    const char *textStart = "Iniciar Jogo";
    const char *textQuit = "Sair";
    const char *textCredits = "Créditos";
    const char *textFooter = "CIN-UFPE 2025"; 

    
    Sound Som_UI = LoadSound("sounds/UI_SOUND.mp3");
    Sound Som_TelaInicial = LoadSound("sounds/Sound_Menu.mp3");
    SetSoundVolume(Som_UI, 10);
    SetSoundVolume(Som_TelaInicial, 0.25);
    bool FlagMouse = false;
    int FramesTotal = 106;
    Texture2D Frames[107];
    int FrameAtual = 0;
    bool controleframe = false;

    float RoundButton = 0.3f;
    int Segments = 8;

    for(int i = 0; i <= FramesTotal; i++){
        char Caminho[64];
        sprintf(Caminho, "frames_menu/frame_%03d.png", i+1);
        Frames[i] = LoadTexture(Caminho);
        }
    //Texture2D background = LoadTexture("Images/Background.png");

    // Musica Menu
    PlaySound(Som_TelaInicial);

    while(WindowShouldClose() == false)
    {
        if(FrameAtual >= FramesTotal){
            controleframe = true;
        }
        else if(controleframe == true && FrameAtual == 0){
            controleframe = false;
        }

        if(controleframe == false){
            FrameAtual++;
        }
        else{
            FrameAtual--;
        }
        

        BeginDrawing();
            // ClearBackground(RAYWHITE);
            DrawTexture(Frames[FrameAtual], 0, 0, WHITE);
            DrawText("Error 404:", 264, 104, 55, BLACK);
            DrawText("Error 404:", 260, 100, 55, WHITE);       
            DrawText("Princesa Não Encontrada", 104, 154, 55, BLACK);
            DrawText("Princesa Não Encontrada", 100, 150, 55, WHITE);
            
            // Botões Menu
            DrawRectangle(BotaoStart.x, BotaoStart.y, BotaoStart.width, BotaoStart.height, CorBotao);
            DrawRectangle(BotaoQuit.x, BotaoQuit.y, BotaoQuit.width, BotaoQuit.height, CorBotao);
            DrawRectangle(BotaoCredits.x, BotaoCredits.y, BotaoCredits.width, BotaoCredits.height, CorBotao);
        
            // Interação com o Botão
            if(CheckCollisionPointRec(GetMousePosition(), BotaoStart)){
                DrawRectangle(BotaoStart.x, BotaoStart.y, BotaoStart.width, BotaoStart.height, CorBotaoSel);
                // Começar Jogo
                if(!FlagMouse){
                    PlaySound(Som_UI);
                    FlagMouse = true;
                    }

                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    printf("Botão JOGAR foi clicado");
                }
            }

            else if(CheckCollisionPointRec(GetMousePosition(), BotaoQuit)){
                DrawRectangle(BotaoQuit.x, BotaoQuit.y, BotaoQuit.width, BotaoQuit.height, CorBotaoSel);
                // Sair do Jogo
                if(!FlagMouse){
                    PlaySound(Som_UI);
                    FlagMouse = true;
                    }

                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    printf("Botão Sair foi clicado");
                    break;
                }
            } 

            else if(CheckCollisionPointRec(GetMousePosition(), BotaoCredits)){
                DrawRectangle(BotaoCredits.x, BotaoCredits.y, BotaoCredits.width, BotaoCredits.height, CorBotaoSel);
                // Entrar nos créditos
                if(!FlagMouse){
                    PlaySound(Som_UI);
                    FlagMouse = true;
                    }

                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    TelaCreditos(); // creditos.c rodando aqui !!!
                }
            }
            else{
                FlagMouse = false;
            }
           
            // MeasureText vai receber o texto por referencia utilizando o ponteiro
            // e será definido a posicao do texto dentro da caixa de acordo com as operaçoes.
            // o MeasureText retorna a largura do texto em pixels


            // INICIAR JOGO
            int widthStart = MeasureText(textStart, FONT_SIZE);
            int xStart = BotaoStart.x + (BotaoStart.width - widthStart) / 2;
            int yStart = BotaoStart.y + (BotaoStart.height - FONT_SIZE) / 2;
            DrawText(textStart, xStart, yStart, FONT_SIZE, RAYWHITE);

            // SAIR
            int widthQuit = MeasureText(textQuit, FONT_SIZE);
            int xQuit = BotaoQuit.x + (BotaoQuit.width - widthQuit) / 2; // pega o tamanho total do botao (largura) e subtrai pelo tam do texto para descobrir as margens.
            int yQuit = BotaoQuit.y + (BotaoQuit.height - FONT_SIZE) / 2;
            DrawText(textQuit, xQuit, yQuit, FONT_SIZE, RAYWHITE);

            // CRÉDITOS
            int widthCredits = MeasureText(textCredits, FONT_SIZE);
            int xCredits = BotaoCredits.x + (BotaoCredits.width - widthCredits) / 2;
            int yCredits = BotaoCredits.y + (BotaoCredits.height - FONT_SIZE) / 2;
            DrawText(textCredits, xCredits, yCredits, FONT_SIZE, RAYWHITE);

            
            int widthFooter = MeasureText(textFooter, FONT_SIZE);
            int xFooter = (1280 / 2) - (widthFooter / 2); // o x do footer é a largura da tela
            int yFooter = 700   ; // Mantém sua posição Y original
            DrawText(textFooter, xFooter, yFooter, FONT_SIZE, WHITE);

           

        EndDrawing();
    }
    UnloadSound(Som_UI);
    UnloadSound(Som_TelaInicial);
    CloseAudioDevice();    
    CloseWindow();
    for(int i = 0; i <= FramesTotal; i++){
        UnloadTexture(Frames[i]);
    }
    
    return 0;    
}