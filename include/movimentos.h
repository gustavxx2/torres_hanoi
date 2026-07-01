#ifndef MOVIMENTOS_H
#define MOVIMENTOS_H

#include "torres.h"

// Estrutura para armazenar um histórico de movimento
typedef struct {
    char origem;      // Torre de origem (A, B ou C)
    char destino;     // Torre de destino (A, B ou C)
    int disco;        // Número do disco movido
} Movimento;

// Estrutura para armazenar o histórico completo da partida
typedef struct {
    Movimento movimentos[1000];  // Máximo de 1000 movimentos por partida
    int contador;                // Contador total de movimentos
} HistoricoMovimentos;

// Função para validar se um movimento é legal (disco menor em cima do maior)
// Retorna 1 se válido, 0 se inválido
int validarMovimento(Torre torres[], char origem, char destino);

// Função para executar um movimento válido e registrar no histórico
// Retorna 1 se o movimento foi executado com sucesso, 0 se falhou
int executarMovimento(Torre torres[], char origem, char destino, HistoricoMovimentos *historico);

// Função para obter o contador de movimentos
int obterContadorMovimentos(HistoricoMovimentos *historico);

// Função para exibir o histórico de movimentos da partida
void exibirHistoricoMovimentos(HistoricoMovimentos *historico);

// Função para inicializar o histórico de movimentos
void inicializarHistorico(HistoricoMovimentos *historico);

// Função auxiliar para converter índice da torre (0, 1, 2) para letra (A, B, C)
char indiceTorreParaLetra(int indice);

// Função auxiliar para converter letra (A, B, C) para índice da torre (0, 1, 2)
int letraParaIndiceTorre(char letra);

#endif // MOVIMENTOS_H
