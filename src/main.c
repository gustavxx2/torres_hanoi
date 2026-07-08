#include <stdio.h>
#include <stdlib.h>

#include "../include/menu.h"
#include "../include/interface.h"
#include "../include/torres.h"
#include "../include/movimentos.h"
#include "../include/automatico.h"

int main()
{
    Torre torres[MAX_TORRES];

    HistoricoMovimentos historico;

    int opcao;
    int numDiscos;
    int totalMovimentos = 0;

    telaInicial();

    do
    {
        opcao = menuPrincipal();

        switch(opcao)
        {
            case 1:
            {
                printf("Quantidade de discos (1 a 7): ");
                scanf("%d", &numDiscos);

                if(numDiscos < 1 || numDiscos > MAX_DISCOS)
                {
                    printf("Quantidade invalida!\n");
                    system("pause");
                    break;
                }

                inicializarTorre(torres, numDiscos);

                inicializarHistorico(&historico);

                exibir_torre(torres, numDiscos);

                printf("\nModo manual ainda sera integrado.\n");

                system("pause");
                break;
            }

            case 2:
            {
                printf("Quantidade de discos (1 a 7): ");
                scanf("%d", &numDiscos);

                if(numDiscos < 1 || numDiscos > MAX_DISCOS)
                {
                    printf("Quantidade invalida!\n");
                    system("pause");
                    break;
                }

                inicializarTorre(torres, numDiscos);

                resolverAutomatico(
                    torres,
                    numDiscos,
                    0,
                    2,
                    1,
                    &totalMovimentos
                );

                exibir_torre(torres, numDiscos);

                printf("\nMovimentos: %d\n", totalMovimentos);

                system("pause");
                break;
            }

            case 3:
            {
                printf("\nHighscore ainda sera integrado.\n");

                system("pause");
                break;
            }

            case 4:
            {
                telaFinal();
                break;
            }

            default:
            {
                printf("Opcao invalida!\n");
                system("pause");
            }
        }

    } while(opcao != 4);

    return 0;
}
