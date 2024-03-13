#include "raylib.h"
#include <stdio.h>

Sound pulo;
Music music1;
Music music2;

void initsounds(){

    pulo = LoadSound("assets/sounds/pulo.wav");
    music1 = LoadMusicStream("assets/sounds/medieval.wav");
    music2 = LoadMusicStream("assets/sounds/plimplimplon.wav");

}






