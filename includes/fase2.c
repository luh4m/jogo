#include "raylib.h"
#include <stdio.h>
#include "structs.h"
#include "fase1.h"
#include "defs.h"
#include "colisao.h"
#ifndef FASE2_C
#define FASE2_C

Texture2D backtext2;

    int largura_background;
    int altura_background;
    fase fase2;
    
void fase2_init(){

    backtext2 = LoadTexture("assets/definitivo.png");

    largura_background = backtext2.width;
    altura_background = backtext2.height;
    fase2;

    fase2.plataformas[0].y = altura_background + 50;
    fase2.plataformas[0].x = 0;
    fase2.plataformas[0].width = largura_background;
    fase2.plataformas[0].height = 10;

    fase2.plataformas[1].y = 160;
    fase2.plataformas[1].x = 0;
    fase2.plataformas[1].width = 64;
    fase2.plataformas[1].height = 10;

    fase2.plataformas[2].y = 640;
    fase2.plataformas[2].x = 0;
    fase2.plataformas[2].width = 288;
    fase2.plataformas[2].height = 10;

    fase2.plataformas[3].y = 640;
    fase2.plataformas[3].x = 354;
    fase2.plataformas[3].width = 224;
    fase2.plataformas[3].height = 10;

    fase2.plataformas[4].y = 593;
    fase2.plataformas[4].x = 608;
    fase2.plataformas[4].width = 160;
    fase2.plataformas[4].height = 10;

    fase2.plataformas[5].y = 465;
    fase2.plataformas[5].x = 450;
    fase2.plataformas[5].width = 160;
    fase2.plataformas[5].height = 10;

    fase2.plataformas[6].y = 369;
    fase2.plataformas[6].x = 450;
    fase2.plataformas[6].width = 160;
    fase2.plataformas[6].height = 10;

    fase2.plataformas[7].y = 305;
    fase2.plataformas[7].x = 642;
    fase2.plataformas[7].width = 224;
    fase2.plataformas[7].height = 10;

    fase2.plataformas[8].y = 547;
    fase2.plataformas[8].x = 1058;
    fase2.plataformas[8].width = 384;
    fase2.plataformas[8].height = 10;

    fase2.plataformas[9].y = 419;
    fase2.plataformas[9].x = 1410;
    fase2.plataformas[9].width = 192;
    fase2.plataformas[9].height = 10;

    fase2.plataformas[10].y = 404;
    fase2.plataformas[10].x = 1666;
    fase2.plataformas[10].width = 160;
    fase2.plataformas[10].height = 10;

    fase2.plataformas[11].y = 291;
    fase2.plataformas[11].x = 1922;
    fase2.plataformas[11].width = 352;
    fase2.plataformas[11].height = 10;

    fase2.plataformas[12].y = 180;
    fase2.plataformas[12].x = 2178;
    fase2.plataformas[12].width = 128;
    fase2.plataformas[12].height = 10;

    fase2.plataformas[13].y = 116;
    fase2.plataformas[13].x = 2402;
    fase2.plataformas[13].width = 128;
    fase2.plataformas[13].height = 10;
}

void draw_fase2(){
        DrawTexture(backtext2, 0, 0, WHITE);
}

#endif