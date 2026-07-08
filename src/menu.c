#include <stdio.h>
#include <stdlib.h>
#include "../include/menu.h"

// Tela inicial do jogo
void telaInicial()
{
    system("cls");

    printf("=====================================\n");
    printf("          TORRES DE HANOI\n");
    printf("=====================================\n");
    printf("Projeto de Linguagem de Programacao\n\n");
    printf("Pressione ENTER para continuar...");
    getchar();
}

// Menu principal
int menuPrincipal()
{
    int opcao;

    system("cls");

    printf("=========== MENU ===========\n");
    printf("1 - Jogar\n");
    printf("2 - Resolver Automaticamente\n");
    printf("3 - Ver Highscore\n");
    printf("4 - Sair\n");
    printf("============================\n");
    printf("Escolha: ");

    scanf("%d", &opcao);

    while(getchar() != '\n');

    return opcao;
}

// Tela de encerramento
void telaFinal()
{
    system("cls");

    printf("\nObrigado por jogar!\n");
}
