#ifndef INTERFACE_H
#define INTERFACE_H

#include "torres.h"


void limpar_Tela();
void exibir_Torre(Torre torres[], int num_discos);
void exibir_menu();
void exibir_vitoria(int numMovimentos, int tempo);
void exibir_mensagem_erro();
void exibir_dica(char origem, char destino);

#endif // INTERFACE_H