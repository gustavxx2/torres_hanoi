#ifndef AUTOMATICO_H
#define AUTOMATICO_H

#include "torres.h" // definição da struct Torre e suas operações (push/pop)

void resolverAutomatico (Torre torres[], int numDiscos, int origem, int destino, int auxiliar, int *totalMovimentos); // resolve o jogo inteiro automaticamente

int proximaDica(Torre torres[], int numDiscos, int origem, int destino, int auxiliar, int *totalMovimentos); // calcula e mostra só o próximo movimento

#endif // AUTOMATICO_H