#include "../include/interface.h"
#include <stdio.h>
#include <stdlib.h>

void limpar_tela()
{
    system("cls"); // Limpa a tela no Windows
}
void exibir_menu()
{
    printf("==============================\n");
    printf("   TORRES DE HANOI\n");
    printf("==============================\n");
    printf("1. Jogar\n");
    printf("2. modo automativo\n");
    printf("3. ver highscore\n");
    printf("4. Sair\n");
    printf("==============================\n");
    printf("Escolha uma opção: ");
}
void exibir_torre(Torre torres[], int num_discos)
{
    printf("\n");
    for (int linha = num_discos - 1; linha >= 0; linha--)
    {
        for (int torre = 0; torre < 3; torre++)
        {
            int disco = -1; // Valor padrão para indicar ausência de disco

            if (torres[torre].topo >= linha)
            {
                disco = torres[torre].discos[linha];
            }

            if (disco == -1)
            {
                printf("     ");
            }
            else
            {
                int tamanho = disco * 2 - 1;
                int espacos = (num_discos - disco);

                for (int i = 0; i < espacos; i++)
                    printf(" ");
                printf("[");
                for (int i = 0; i < tamanho; i++)
                    printf("=");
                printf("]");
                for (int i = 0; i < espacos; i++)
                    printf(" ");
            }
        }
        printf("\n");
    }

    printf("=========|=========|=========\n");
    printf("torre A  |torre  B |torre C   \n\n");
}
void exibir_vitoria(int Movimentos, int tempo)
{
    printf("=====================================\n");
    printf("    PARABÉNS! VOCÊ VENCEU!\n");
    printf("=====================================\n");
    printf("Movimentos: %d\n", Movimentos);
    printf("Tempo: %d segundos\n", tempo);
    printf("=====================================\n");
}
void exibir_mensagem_erro()
{
    printf("=====================================\n");
    printf("    MOVIMENTO INVÁLIDO! TENTE NOVAMENTE.\n");
    printf("=====================================\n");
}
void exibir_dica(char origem, char destino)
{
    printf("=====================================\n");
    printf("    DICA: Mova o disco da torre %c para a torre %c\n", origem, destino);
    printf("=====================================\n");
}
