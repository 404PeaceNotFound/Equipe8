#include <raylib.h>
#include <stdio.h>

int main(){

    InitWindow(1280, 720, "Primeiro Teste");
    SetTargetFPS(60);
    InitAudioDevice();
    

    Rectangle BotaoStart = {-5, 200, 250, 60};
    Rectangle BotaoQuit = {-5, 300, 250, 60};
    Rectangle BotaoCredits = {-5, 400, 250, 60};
    Color CorBotao = { 30, 30, 30, 255 };
    Color CorBotaoSel = { 50, 50, 50, 255 }; 
    Sound Som_UI = LoadSound("Sounds/UI_SOUND.mp3");
    SetSoundVolume(Som_UI, 30);
    bool FlagMouse = false;

    float RoundButton = 0.3f;
    int Segments = 8;

    // ---------- Texto para aparececer nos botaos -------------------

    const char *texto_start = "Iniciar Jogo";
    const char *texto__quit = "Sair";
    const char *texto_credits= "Créditos";
    int tamanho_font = 20;
    

    Texture2D background;
    background = LoadTexture("Images/Background.png");

    while(WindowShouldClose() == false)
    {
        // Desenho
        BeginDrawing();
            ClearBackground(WHITE);
            //DrawTexture(background, 0, 0, WHITE);

            //  Botões Menu
            DrawRectangleRounded(BotaoStart, RoundButton, Segments, CorBotao);
            DrawRectangleRounded(BotaoQuit, RoundButton, Segments,  CorBotao);
            DrawRectangleRounded(BotaoCredits, RoundButton, Segments, CorBotao);
        
            //Interação com o Botão
            if(CheckCollisionPointRec(GetMousePosition(), BotaoStart)){
                DrawRectangleRounded(BotaoStart, RoundButton, Segments, CorBotaoSel);
                //Começar Jogo
                if(!FlagMouse){
                    PlaySound(Som_UI);
                    FlagMouse = true;
                    }

                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    printf("Botão JOGAR foi clicado");
                }
            } 


            else if(CheckCollisionPointRec(GetMousePosition(), BotaoQuit)){
                DrawRectangleRounded(BotaoQuit, RoundButton, Segments, CorBotaoSel);
                //Sair do Jogo
                if(!FlagMouse){
                    PlaySound(Som_UI);
                    FlagMouse = true;
                    }

                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    printf("Botão Saur foi clicado");
                    break;
                }
            } 


            else if(CheckCollisionPointRec(GetMousePosition(), BotaoCredits)){
                DrawRectangleRounded(BotaoCredits, RoundButton, Segments, CorBotaoSel);
                //Entrar nos créditos
                if(!FlagMouse){
                    PlaySound(Som_UI);
                    FlagMouse = true;
                    }

                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    printf("Botão Créditos foi clicado");
                }
            }

            else{
                FlagMouse = false;
            }
             
          
            Vector2 tam_texto_start = MeasureTextEx(GetFontDefault(), texto_start, tamanho_font, 1);
            DrawText(texto_start,
            BotaoStart.x + (BotaoStart.width / 2) - (tam_texto_start.x / 2),
            BotaoStart.y + (BotaoStart.height /2) - (tamanho_font / 2),
            tamanho_font, RAYWHITE);



        EndDrawing();
    }
    

    UnloadSound(Som_UI);
    CloseAudioDevice();    
    CloseWindow();
    return 0;    
}