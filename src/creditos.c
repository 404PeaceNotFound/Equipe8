#include <raylib.h>


void TelaCreditos(void) {

    Texture2D Background = LoadTexture("Images/background_creditos.jpeg"); //imagem de fundo 
    //Music music = LoadMusicStream("Sounds/POL-into-the-castle-short.mp3"); // musica dos créditos

    //PlayMusicStream(music);
    //SetMusicVolume(music, 0.5f);
    Sound Som_UI = LoadSound("sounds/UI_SOUND.mp3");
    SetSoundVolume(Som_UI, 10);
    bool FlagMouse = false;
    
    Rectangle btnback  = {1000, 650, 175, 50}; // v_locais 
    Color CorBotao = { 30, 30, 30, 150 };
    float scrolly = 720.0f;

    while (!WindowShouldClose()) { //loop  que roda os creditos
        //UpdateMusicStream(music);
        if(IsKeyPressed(KEY_ESCAPE)){
            break;
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTextureEx(Background, (Vector2){0, 0}, 0.0f, (float)GetScreenWidth()/Background.width, WHITE);
        DrawRectangleRec(btnback, CorBotao);
        

        scrolly -= 1.0f;
        if(scrolly < -400){ //descer os creditos
            scrolly =720;
        }
        //testos na pagina de creditos
        DrawText("CRÉDITOS", 290, scrolly + 2, 50, BLACK);
        DrawText("CRÉDITOS", 290, scrolly, 50, WHITE);

        //Nome dos colaboradores
        DrawText("Desenvolvedor 1: Gibriel Vieira <gvnrb>", 240, scrolly+80, 30, BLACK);
        DrawText("Desenvolvedor 1: Gibriel Vieira <gvnrb>", 238, scrolly+78, 30, WHITE);

        DrawText("Desenvolvedor 2: Guilherme Vitor <gvca>",240, scrolly+120, 30, BLACK);
        DrawText("Desenvolvedor 2: Guilherme Vitor <gvca>",238, scrolly+118, 30, WHITE);

        DrawText("Desenvolvedor 3: João victor <jvajs>", 240, scrolly+160, 30, BLACK);
        DrawText("Desenvolvedor 3: João victor <jvajs>", 238, scrolly+158, 30, WHITE);

        DrawText("Desenvolvedor 4: José Lucas <jlhm>", 240, scrolly+200, 30, BLACK);
        DrawText("Desenvolvedor 4: José Lucas <jlhm>", 238, scrolly+198, 30, WHITE);

        DrawText("Desenvolvedor 5: Luciano José <ljsj>", 240, scrolly+240, 30, BLACK);
        DrawText("Desenvolvedor 5: Luciano José <ljsj>", 238, scrolly+238, 30, WHITE);

        // Agradecimentos 

        DrawText("Obrigado Por Jogar! : NOME_DO_JOGO", 240, scrolly+360, 30, BLACK);
        DrawText("Obrigado Por Jogar! : NOME_DO_JOGO", 238, scrolly+358, 30, WHITE);

        //Botão de Voltar
        if(CheckCollisionPointRec(GetMousePosition(), btnback)){
            DrawRectangleRec(btnback, Fade(LIGHTGRAY, 0.8f));
            if(!FlagMouse){
                    PlaySound(Som_UI);
                    FlagMouse = true;
            }

            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                break;                                               
            }                                                   
                
        }
        else{
            FlagMouse = false;
        }

        DrawText("VOLTAR", btnback.x+45, btnback.y+15, 20, WHITE);

        EndDrawing();
    }
    // Limpa recursos usados 
    //StopMusicStream(music);
    UnloadSound(Som_UI);
    UnloadTexture(Background);

}
