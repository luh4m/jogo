#ifndef TRANSITION_H
#define TRANSITION_H

int transition(int* button, Rectangle* playerhitbox,  Vector2* posicao, int* jumptimer);
void FinalTransition_init();
void unload_finaltex();
void FinalTransition(int* button);
#endif