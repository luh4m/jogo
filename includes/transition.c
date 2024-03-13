#ifndef TRANSITION_C
#define TRANSITION_C

#include "raylib.h"

int transition_num=1;
int timerfinal=0;
Rectangle finalf1, finalf2;
Texture2D final;

int transition(int* button, Rectangle* playerhitbox, Vector2* posicao, int* jumptimer){

    finalf1.x=173*32;
    finalf1.y=23*32;
    finalf1.width=2*32;
    finalf1.height=1*32;

    finalf2.x=  26 + 314*32;
    finalf2.y= 20 + 2*32;
    finalf2.width=2*32;
    finalf2.height=2*32;

    if(transition_num==1)
        if(CheckCollisionRecs(*playerhitbox, finalf1)==1){
            enemy2_init();
            transition_num=2;
            *posicao = (Vector2) {14,15};
            (*playerhitbox).x = (*posicao).x;
            (*playerhitbox).y = (*posicao).y;
        }
        
    if(transition_num==2)
        if(CheckCollisionRecs(*playerhitbox, finalf2)==1){
            character_init();
            *button = -1;
            transition_num = 3;
        }

    return transition_num;
}

void FinalTransition_init(){
    final = LoadTexture("assets/menu/final.png");
}

void unload_finaltex(){
    UnloadTexture(final);
}

void FinalTransition(int* button){
       timerfinal++;
                if(timerfinal<=180)
                    DrawTexture(final, 0, 0, WHITE);

                else{
                    *button = 0;
                    timerfinal = 0;
                    transition_num=1;
                }
}


#endif


