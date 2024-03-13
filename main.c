#include <stdio.h>
#include <math.h>
#include "raylib.h"
#include "includes/character.h"
#include "includes/character.c"
#include "includes/fase1.h"
#include "includes/fase1.c"
#include "includes/fase2.h"
#include "includes/fase2.c"
#include "includes/enemy1.c"
#include "includes/enemy2.c"
#include "includes/enemy2.h"
#include "includes/menu.h"
#include "includes/menu.c"
#include "includes/transition.h"
#include "includes/transition.c"
#include "includes/sons.c"
#include "includes/sons.h"

int main()
{

    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 1000;
    int screenHeight = 736;
    int button = 0;
    int colidiu1 = 0, colidiu2 = 0;
    int delay=0;
    
    InitWindow(screenWidth, screenHeight, "Al Sem Ammy");

    InitAudioDevice();
    initsounds();

    SetMusicVolume(music2, 0.1);
    SetMusicVolume(music1, 0.1);

    fase1_init();
    fase2_init();
    character_init();
    enemy1_init();
    enemy2_init();
    DefineThings();
    FinalTransition_init();

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second

    PlayMusicStream(music1);
    PlayMusicStream(music2);

    // Main game loop
    //--------------------------------------------------------------------------------------
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        //musica da fase 1 e menu
        if(transition(&button, &playerhitbox, &posicao, &jumptimer) == 1){
            UpdateMusicStream(music1);
        }
        //musica da fase 2
        else if(transition(&button, &playerhitbox, &posicao, &jumptimer) == 2){
            delay+=1;
            if(delay>120){
                UpdateMusicStream(music2);
            }
        }
        //lógica das escolhas de botão do menu
        if (button == 0 || button == 2 || button == 3)
            choose_button(&button);

        //logica do jogo 
        if (button == 1)
        {
            camera_settings(&screenWidth, &screenHeight, transition(&button, &playerhitbox, &posicao, &jumptimer));
            character_movement(pulo);
            enemy1_movement();
            enemy2_movement(posicao.x, posicao.y);
        }

        //botões da tela game over
        if (button == 4)
        {
            choose_buttonover(&button);
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(RAYWHITE);
            if (button == 0 || button == 2 || button == 3)
                DrawThings(&button);
            if (button == 4)
            {
                DrawThingsover(&button);
            }
            if (button == 1)
            {
                BeginMode2D(camera);

                    //desenha a fase 1
                    if (transition(&button, &playerhitbox, &posicao, &jumptimer) == 1)
                    {
                        draw_fase1();
                        draw_enemy1_map1();
                        draw_enemy2_map1();
                        draw_character();
                        colidiu1 = colisaoinimigosfase1();

                        //tela de game over quando morre
                        if (colidiu1 == 1)
                        {
                            button = 4;
                        }
                    }

                    //desenha a fase 2
                    if (transition(&button, &playerhitbox, &posicao, &jumptimer) == 2)
                    {
                        draw_fase2();
                        draw_enemy1_map2();
                        draw_enemy2_map2();
                        draw_character();
                        colidiu2 = colisaoinimigosfase2();

                         //tela de game over quando morre
                        if (colidiu2 == 1)
                        {
                            button = 4;
                        }
                    }
                EndMode2D();
                
                //transiçao pós fim do jogo
                if (transition(&button, &playerhitbox, &posicao, &jumptimer) == 3)
                    FinalTransition(&button);
                
            }
        
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    //descarrega as texturas
    unload_charactertex();
    unload_enemy1_tex();
    unload_enemy2_tex();
    unload_finaltex();
    unload_menutex();
    //----------------------------------------------------------------------------------

    //descarrega os sons
    UnloadSound(pulo);
    UnloadMusicStream(music1);
    UnloadMusicStream(music2);

    CloseAudioDevice();

    CloseWindow(); // Close window and OpenGL context
                   //--------------------------------------------------------------------------------------
    return 0;
}
