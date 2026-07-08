#include "automatico.h"
#include <stdio.h>
#include "interface.h"

char NOMES_TORRES[3] = {'A', 'B', 'C'};
static void gerarMovimentos(Torre torres[], int numDiscos, int origem, int destino, int auxiliar,
                            int *contador, int movimentoAlvo, int *origemAlvo, int *destinoAlvo,
                            int *encontrado, int executar)
{
    if (numDiscos == 0 || (encontrado && *encontrado)) {
        return;
    }

    gerarMovimentos(torres, numDiscos - 1, origem, auxiliar, destino, contador, movimentoAlvo, origemAlvo, destinoAlvo, encontrado, executar);

    if (encontrado && *encontrado) {
        return;
    }

    (*contador)++;

    if (executar) {
        int disco = pop(&torres[origem]);
        push(&torres[destino], disco);
        exibir_dica(NOMES_TORRES[origem], NOMES_TORRES[destino]);
    }

    if (movimentoAlvo >= 0 && contador && *contador == movimentoAlvo) {
        if (origemAlvo) *origemAlvo = origem;
        if (destinoAlvo) *destinoAlvo = destino;
        if (encontrado) *encontrado = 1;
        return;
    }

    gerarMovimentos(torres, numDiscos - 1, auxiliar, destino, origem, contador, movimentoAlvo, origemAlvo, destinoAlvo, encontrado, executar);
}

void resolverAutomatico(Torre torres[], int numDiscos, int origem, int destino, int auxiliar, int *totalMovimentos)
{
    int contador = 0;
    int encontrado = 0;
    int dummyOrigem = -1;
    int dummyDestino = -1;

    printf("Resolver automaticamente...\n");

    gerarMovimentos(torres, numDiscos, origem, destino, auxiliar, &contador, -1, &dummyOrigem, &dummyDestino, &encontrado, 1);

    if (totalMovimentos) *totalMovimentos = contador;
    printf("Resolvido em %d movimentos.\n", contador);
}

int proximaDica(Torre torres[], int numDiscos, int origem, int destino, int auxiliar, int *totalMovimentos)
{
    if (totalMovimentos) *totalMovimentos = (1 << numDiscos) - 1;
    return 0;
}