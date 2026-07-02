#include "movimentos.h"
#include <stdio.h>
#include <ctype.h>

// Função auxiliar para converter índice da torre (0, 1, 2) para letra (A, B, C)
char indiceTorreParaLetra(int indice) {
    // Converte o índice numérico para a letra correspondente da torre
    switch (indice) {
        case 0:
            return 'A';
        case 1:
            return 'B';
        case 2:
            return 'C';
        default:
            return '?';
    }
}

// Função auxiliar para converter letra (A, B, C) para índice da torre (0, 1, 2)
int letraParaIndiceTorre(char letra) {
    // Converte a letra maiúscula ou minúscula para o índice correspondente
    letra = toupper(letra);
    switch (letra) {
        case 'A':
            return 0;
        case 'B':
            return 1;
        case 'C':
            return 2;
        default:
            return -1; // Letra inválida
    }
}

// Função para validar se um movimento é legal
// Um movimento é legal se:
// 1. As torres de origem e destino são válidas
// 2. A torre de origem não está vazia
// 3. O disco do topo da origem é menor que o disco do topo do destino (ou destino está vazia)
int validarMovimento(Torre torres[], char origem, char destino) {
    // Convertendo as letras para índices
    int idxOrigem = letraParaIndiceTorre(origem);
    int idxDestino = letraParaIndiceTorre(destino);

    // Verificar se as torres são válidas
    if (idxOrigem < 0 || idxOrigem >= MAX_TORRES || idxDestino < 0 || idxDestino >= MAX_TORRES) {
        return 0; // Torres inválidas
    }

    // Verificar se a torre de origem está vazia
    if (torreVazia(&torres[idxOrigem])) {
        return 0; // Não há disco para mover
    }

    // Obter o disco do topo da torre de origem
    int discoOrigem = topoTorre(&torres[idxOrigem]);

    // Se a torre de destino está vazia, o movimento é válido
    if (torreVazia(&torres[idxDestino])) {
        return 1;
    }

    // Se a torre de destino não está vazia, o disco de origem deve ser menor
    int discoDestino = topoTorre(&torres[idxDestino]);
    return discoOrigem < discoDestino ? 1 : 0;
}

// Função para executar um movimento válido e registrar no histórico
int executarMovimento(Torre torres[], char origem, char destino, HistoricoMovimentos *historico) {
    // Validar o movimento antes de executá-lo
    if (!validarMovimento(torres, origem, destino)) {
        return 0; // Movimento inválido
    }

    int idxOrigem = letraParaIndiceTorre(origem);
    int idxDestino = letraParaIndiceTorre(destino);

    // Fazer o pop do disco da torre de origem
    int disco = pop(&torres[idxOrigem]);

    // Fazer o push do disco na torre de destino
    push(&torres[idxDestino], disco);

    // Registrar o movimento no histórico
    if (historico->contador < 1000) {
        historico->movimentos[historico->contador].origem = origem;
        historico->movimentos[historico->contador].destino = destino;
        historico->movimentos[historico->contador].disco = disco;
        historico->contador++;
    }

    return 1; // Movimento executado com sucesso
}

// Função para obter o contador de movimentos
int obterContadorMovimentos(HistoricoMovimentos *historico) {
    // Retorna o número total de movimentos realizados
    return historico->contador;
}

// Função para exibir o histórico de movimentos da partida
void exibirHistoricoMovimentos(HistoricoMovimentos *historico) {
    // Exibe todos os movimentos realizados durante a partida
    printf("\n========== HISTÓRICO DE MOVIMENTOS ==========\n");
    printf("Total de movimentos: %d\n\n", historico->contador);

    if (historico->contador == 0) {
        printf("Nenhum movimento realizado ainda.\n");
        return;
    }

    // Exibir cada movimento com sua sequência
    for (int i = 0; i < historico->contador; i++) {
        printf("%3d. Disco %d: %c -> %c\n",
               i + 1,
               historico->movimentos[i].disco,
               historico->movimentos[i].origem,
               historico->movimentos[i].destino);
    }

    printf("\n============================================\n");
}

// Função para inicializar o histórico de movimentos
void inicializarHistorico(HistoricoMovimentos *historico) {
    // Zera o contador de movimentos no início de uma nova partida
    historico->contador = 0;
    
    // Opcionalmente, limpar todo o array (não é estritamente necessário)
    for (int i = 0; i < 1000; i++) {
        historico->movimentos[i].origem = '\0';
        historico->movimentos[i].destino = '\0';
        historico->movimentos[i].disco = 0;
    }
}
