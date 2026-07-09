#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pontuacao.h"

// Variável global para guardar a hora que o jogo começou
time_t inicio_jogo;

// Marca o momento exato em que o jogador fez o primeiro movimento (ou iniciou a fase)
void iniciar_cronometro() {
    inicio_jogo = time(NULL);
}

// Retorna quantos segundos se passaram desde o inicio
int parar_cronometro() {
    time_t fim_jogo = time(NULL);
    return (int)(fim_jogo - inicio_jogo); 
}

// Lógica de pontos: baseada na quantidade de discos, movimentos e tempo gasto
int calcular_pontuacao(int discos, int movimentos, int tempo_segundos) {
    // Calcula o minimo de movimentos possíveis para terminar (2 elevado a N - 1)
    int min_movimentos = 1;
    for(int i = 0; i < discos; i++) {
        min_movimentos *= 2;
    }
    min_movimentos -= 1;

    // Pontuação base (mais discos = mais pontos)
    int base_pontos = discos * 1000;
    
    // Tira pontos se o jogador fez movimentos a mais ou demorou muito
    int penalidade_mov = (movimentos - min_movimentos) * 50;
    int penalidade_tempo = tempo_segundos * 10;

    int total = base_pontos - penalidade_mov - penalidade_tempo;

    // Não deixa a pontuação ficar negativa caso o jogador vá muito mal
    if (total < 0) {
        total = 0;
    }

    return total;
}

// Lê o arquivo para descobrir o recorde atual
int ler_highscore() {
    FILE *arquivo = fopen("highscore.txt", "r");
    int recorde = 0;

    // Se o arquivo existir, lê o número que está lá
    if (arquivo != NULL) {
        fscanf(arquivo, "%d", &recorde);
        fclose(arquivo);
    }
    
    return recorde; // Se o arquivo não existir, vai retornar 0
}

// Verifica se a pontuação atual é maior que a salva e atualiza o arquivo
void salvar_highscore(int pontuacao_atual) {
    int recorde_atual = ler_highscore();

    if (pontuacao_atual > recorde_atual) {
        FILE *arquivo = fopen("highscore.txt", "w");
        
        if (arquivo != NULL) {
            fprintf(arquivo, "%d", pontuacao_atual);
            fclose(arquivo);
            printf("\nNovo Recorde! %d pontos salvos com sucesso!\n", pontuacao_atual);
        } else {
            printf("\nErro ao salvar o arquivo de pontuacao.\n");
        }
    }
}