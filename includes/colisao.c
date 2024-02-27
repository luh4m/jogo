#include "raylib.h"
#include "structs.h"
#include "colisao.h"

#ifndef COLISAO_C
#define COLISAO_C

float collision_y(Rectangle player, fase fase, int num_fase)
{
    int count;
    if (num_fase == 1)
    {
        count = 14;
    }
    else
        count = 17;

    for (int i = 0; i < count; i++)
    {
        if (CheckCollisionRecs(player, fase.plataformas[i]))
        {
            return fase.plataformas[i].y;
        }
    }
    return -1;
}
#endif