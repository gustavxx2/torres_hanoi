#ifndef TORRES_H
#define TORRES_H

//tamanho máximo de discos e torres definidas como constantes
#define MAX_DISCOS 7
#define MAX_TORRES 3

//estrutura struct para represntar a torre, contendo um array de discos, um topo e um nome
typedef struct {
    int discos[MAX_DISCOS];
    int topo;
    char nome[20];
} Torre;

//funções para manipular as torres, incluindo inicialização, empilhar, desempilhar, verificar se a torre está vazia e obter o disco do topo
void inicializarTorre(Torre torres[], int numDiscos);
void push(Torre *torre, int disco);
int pop(Torre *torre);
int torreVazia(Torre *torre);
int topoTorre(Torre *torre);

#endif // TORRES_H