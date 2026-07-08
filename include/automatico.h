#ifndef AUTOMATICO_H
#define AUTOMATICO_H

#include "torres.h"

void resolverAutomatico (Torre torres[], int numDiscos, int origem, int destino, int auxiliar, int *totalMovimentos);

int proximaDica(Torre torres[], int numDiscos, int origem, int destino, int auxiliar, int *totalMovimentos);

#endif // AUTOMATICO_H