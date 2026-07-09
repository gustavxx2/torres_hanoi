#include "automatico.h"
#include <stdio.h>
#include "interface.h"

char NOMES_TORRES[3] = {'A', 'B', 'C'}; // nomes das torres, usados nas dicas

// resolve Torre de Hanói dependendo do que foi solicitado; pode executar tudo ou só achar 1 movimento
static void gerarMovimentos(Torre torres[], int numDiscos, int origem, int destino, int auxiliar,
                            int *contador, int movimentoAlvo, int *origemAlvo, int *destinoAlvo,
                            int *encontrado, int executar)
{
    if (numDiscos == 0 || (encontrado && *encontrado)) { // caso base
        return;
    }

    gerarMovimentos(torres, numDiscos - 1, origem, auxiliar, destino, contador, movimentoAlvo, origemAlvo, destinoAlvo, encontrado, executar); // move N-1 para auxiliar

    if (encontrado && *encontrado) {
        return;
    }

    (*contador)++; // conta o movimento do disco maior

    if (executar) { // executa o movimento de verdade
        int disco = pop(&torres[origem]);
        push(&torres[destino], disco);
        exibir_dica(NOMES_TORRES[origem], NOMES_TORRES[destino]);
    }

    if (movimentoAlvo >= 0 && contador && *contador == movimentoAlvo) { // achou o movimento buscado
        if (origemAlvo) *origemAlvo = origem;
        if (destinoAlvo) *destinoAlvo = destino;
        if (encontrado) *encontrado = 1;
        return;
    }

    gerarMovimentos(torres, numDiscos - 1, auxiliar, destino, origem, contador, movimentoAlvo, origemAlvo, destinoAlvo, encontrado, executar); // move N-1 para destino
}

// resolve o jogo inteiro, executando todos os movimentos
void resolverAutomatico(Torre torres[], int numDiscos, int origem, int destino, int auxiliar, int *totalMovimentos)
{
    int contador = 0;
    int encontrado = 0;
    int dummyOrigem = -1;
    int dummyDestino = -1;

    printf("Resolver automaticamente...\n");

    gerarMovimentos(torres, numDiscos, origem, destino, auxiliar, &contador, -1, &dummyOrigem, &dummyDestino, &encontrado, 1); // resolve tudo

    if (totalMovimentos) *totalMovimentos = contador;
    printf("Resolvido em %d movimentos.\n", contador);
}

// calcula e mostra só o próximo movimento, sem executar o jogo todo
int proximaDica(Torre torres[], int numDiscos, int origem, int destino, int auxiliar, int *totalMovimentos)
{
    int contador = 0;
    int encontrado = 0;
    int origemAlvo = -1;
    int destinoAlvo = -1;

    if (totalMovimentos) *totalMovimentos = (1 << numDiscos) - 1; // total de movimentos restantes

    if (numDiscos == 0) {
        return 0; // nada a mover
    }

    gerarMovimentos(torres, numDiscos, origem, destino, auxiliar,
                     &contador, 1, &origemAlvo, &destinoAlvo, &encontrado, 0); // busca só o 1º movimento

    if (encontrado) {
        exibir_dica(NOMES_TORRES[origemAlvo], NOMES_TORRES[destinoAlvo]); // mostra a dica
        return 1;
    }

    return 0;
}