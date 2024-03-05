#include <stdio.h>
#include "raylib.h"
#include "enemy2.h"

#define qtdenemy2 2 // quantos inimigos q seguem o jogador serao inicializados

static InimSegue enemy2[qtdenemy2] = { 0 }; // vetor de inimigos q seguem (de structs)

// inicializacao dos inimigos que perseguem o jogador 
void enemy2_init() {
	for (int i = 0; i < qtdenemy2; i++) {

		// coordenadas dos inimigos (so um exemplo, pode tirar do loop pra colocar coordenadas diferentes aleatorias)
		enemy2[i].ret.x = 50 + (800 * i);
		enemy2[i].ret.y = pow((-50it), i); // coloquei potencia pra ele aparecer as vzs de baixo e as vzs de cima (resultado par ou impar)

		// tamanhos e cor do retangulo
		enemy2[i].ret.width = 70;
		enemy2[i].ret.height = 70;
		enemy2[i].cor = RED;
	}
}

// movimento dos inimigos que perseguem durante o jogo
void enemy2_movement(float playerX, float playerY/*posicoes do jogador*/) {

	for (int i = 0; i < qtdenemy2; i++) { 

		// quando a posicao X ou Y do jogador eh maior que a posicao equivalente do inimigo,
		// o inimigo anda mais nessa direcao. caso contrario, ele volta.
		if ( playerX > enemy2[i].ret.x) enemy2[i].ret.x += 1; // indo para a direita
		if (playerX < enemy2[i].ret.x) enemy2[i].ret.x -= 1; // indo para a esquerda
		if (playerY > enemy2[i].ret.y) enemy2[i].ret.y += 1; // indo para baixo
		if (playerY < enemy2[i].ret.y) enemy2[i].ret.y -= 1; // indo para cima
	}
}

void draw_enemy2(){
	for (int i = 0; i < qtdenemy2; i++) 
		DrawRectangleRec(enemy2[i].ret, enemy2[i].cor);
}
