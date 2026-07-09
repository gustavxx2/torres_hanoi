#ifndef PONTUACAO_H
#define PONTUACAO_H

// Funções do cronômetro
void iniciar_cronometro();
int parar_cronometro();

// Função para calcular os pontos da partida
int calcular_pontuacao(int discos, int movimentos, int tempo_segundos);

// Funções de manipulação de arquivo (Highscore)
int ler_highscore();
void salvar_highscore(int pontuacao_atual);

#endif