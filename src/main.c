#include <raylib.h>
#include <stdio.h>

int main(){

    // Inicialização
    InitWindow(1280, 720, "Primeiro Teste");
    SetTargetFPS(60);
    InitAudioDevice();
    
    // Definições de Botões e Cores
    Rectangle BotaoStart = {-5, 200, 250, 60};
    Rectangle BotaoQuit = {-5, 300, 250, 60};
    Rectangle BotaoCredits = {-5, 400, 250, 60};
    Color CorBotao = { 30, 30, 30, 255 };
    Color CorBotaoSel = { 50, 50, 50, 255 }; 
    
    // Definições de Texto para usar no MeasureText
    const int FONT_SIZE = 20;
    const char *textStart = "Iniciar Jogo";
    const char *textQuit = "Sair";
    const char *textCredits = "Créditos";
    const char *textFooter = "CIN-UFPE 2025"; 

    
    Sound Som_UI = LoadSound("Sounds/UI_SOUND.mp3");
    SetSoundVolume(Som_UI, 30);
    bool FlagMouse = false;

    float RoundButton = 0.3f;
    int Segments = 8;

    Texture2D background;
    background = LoadTexture("Images/Background.png");

    while(WindowShouldClose() == false)
    {
        
        BeginDrawing();
            ClearBackground(WHITE);
            

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
           
            // MeasureText vai receber o texto por referencia utilizando o ponteiro
            // e será definido a posicao do texto dentro da caixa de acordo com as operaçoes.
            // o MeasureText retorna a largura do texto em pixels


            // INICIAR JOGO
            int widthStart = MeasureText(textStart, FONT_SIZE);
            int xStart = BotaoStart.x + (BotaoStart.width - widthStart) / 2;
            int yStart = BotaoStart.y + (BotaoStart.height - FONT_SIZE) / 2;
            DrawText(textStart, xStart, yStart, FONT_SIZE, RAYWHITE);

            //SAIR
            int widthQuit = MeasureText(textQuit, FONT_SIZE);
            int xQuit = BotaoQuit.x + (BotaoQuit.width - widthQuit) / 2; // pega o tamanho total do botao(largura) e subtrai pelo tam do texto para descobrir as margens.
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
            DrawText(textFooter, xFooter, yFooter, FONT_SIZE, BLACK);

           

        EndDrawing();
    }
    
    UnloadSound(Som_UI);
    CloseAudioDevice();    
    CloseWindow();
    return 0;    
}