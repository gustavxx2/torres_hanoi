#include "torres.h"
#include <stdio.h>
#include <string.h>

void inicializarTorre(Torre torres[], int numDiscos){
    Torre nomes[MAX_TORRES] = {"A", "B", "C"};
    //inicializar as torres com os nomes e topo -1
    

    for(int i = 0; i < MAX_TORRES; i++){
        torres[i].topo = -1;
        strcpy(torres[i].nome, nomes[i]);
    }

    //colcar os discos na torre A do maior pro menor
    for(int i = numDiscos; i > 0; i--){
        push(&torres[0], i);
    }
}
void push(Torre *torre, int disco)
{
    // verificar se a torre está cheia
    if (torre->topo < MAX_DISCOS - 1)
    {
        torre->topo++;
        torre->discos[torre->topo] = disco;
    }
}
int pop(Torre *torre)
{
    if (torreVazia(torre))
    {
        return -1; // retorna -1 se a torre estiver vazia
    }
    int disco = torre->discos[torre->topo];
    torre->topo--;
    return disco;
}
int torreVazia(Torre *torre)
{
    return torre->topo == -1; // retorna 1 se a torre estiver vazia, caso contrário retorna 0
}
int topoTorre(Torre *torre)
{
    if (torreVazia(torre))
    {
        return -1; // retorna -1 se a torre estiver vazia
    }
    return torre->discos[torre->topo]; // retorna o disco do topo da torre
}