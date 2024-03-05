#ifndef enemy2_h
#define enemy2_h


// estrutura do inimigo tipo 2 (inimigo que persegue a direcao do jogador)
typedef struct {
	Rectangle ret;
	Color cor;
} InimSegue; 

void enemy2_init();
void enemy2_movement(float playerX, float playerY);
void draw_enemy2();
#endif