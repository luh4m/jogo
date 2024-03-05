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

int main(){

    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 1000;
    int screenHeight = 736;
    bool WindowFullscreen = IsWindowFullscreen(); 

    InitWindow(screenWidth, screenHeight, "Jogo - Projeto");

    // fase1_init();
    fase2_init();
    character_init();
    enemy1_init();

    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    // Main game loop
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {
        
        if( IsKeyPressed(KEY_F) && !WindowFullscreen){
            ToggleFullscreen();
        }

        if(IsKeyPressed(KEY_F) && WindowFullscreen){
            ToggleBorderlessWindowed();
        }
        
        camera_settings(&screenWidth);
        character_movement();
        enemy1_movement();
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            BeginMode2D(camera);
                ClearBackground(RAYWHITE);
                // draw_fase1();
                draw_fase2();
                draw_character();       
                draw_enemy1();
            EndMode2D();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

        unload_charactertex();
        unload_enemy1_tex();
        //----------------------------------------------------------------------------------
         CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
     return 0;
    }
   
  
  