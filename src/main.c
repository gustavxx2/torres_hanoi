#include <stdio.h>
#include <stdlib.h>

// Inclusão dos arquivos de cabeçalho do projeto
#include "../include/menu.h"
#include "../include/interface.h"
#include "../include/torres.h"
#include "../include/movimentos.h"
#include "../include/automatico.h"
#include "../include/pontuacao.h"

// Função principal do programa
int main()
{
    // Vetor que armazenará as três torres do jogo
    Torre torres[MAX_TORRES];

    // Estrutura para armazenar o histórico dos movimentos
    HistoricoMovimentos historico;

    // Variáveis de controle
    int opcao;
    int numDiscos;
    int totalMovimentos = 0;
    
    // Variáveis da sua parte (Pontuação e Tempo)
    int tempo_gasto;
    int pontos;

    // Exibe a tela inicial
    telaInicial();

    // Mantém o menu funcionando até o usuário escolher sair
    do
    {
        // Mostra o menu e recebe a opção escolhida
        opcao = menuPrincipal();

        switch(opcao)
        {
            // Inicia o modo manual
            case 1:
            {
                printf("Quantidade de discos (1 a 7): ");
                scanf("%d", &numDiscos);

                // Verifica se a quantidade de discos é válida
                if(numDiscos < 1 || numDiscos > MAX_DISCOS)
                {
                    printf("Quantidade invalida!\n");
                    system("pause");
                    break;
                }

                // Inicializa as torres com os discos
                inicializarTorre(torres, numDiscos);

                // Zera o histórico de movimentos
                inicializarHistorico(&historico);

                // Mostra as torres na tela
                exibir_torre(torres, numDiscos);
                
                // Zera a contagem de movimentos para a nova partida
                totalMovimentos = 0;

               
                // Começa a contar o tempo antes de liberar o jogador
                iniciar_cronometro();

                // Parte do jogo manual ainda será integrada
                printf("\nModo manual ainda sera integrado.\n");

                // Quando o loop do jogo manual for criado, 
                // as linhas abaixo devem rodar APENAS QUANDO O JOGADOR VENCER!
                
                tempo_gasto = parar_cronometro();
                pontos = calcular_pontuacao(numDiscos, totalMovimentos, tempo_gasto);

                printf("\n--- RESULTADOS DA PARTIDA ---\n");
                printf("Tempo de jogo: %d segundos\n", tempo_gasto);
                printf("Movimentos: %d\n", totalMovimentos);
                printf("Sua pontuacao final: %d\n", pontos);
                
                // Chama a sua função que verifica se bateu o recorde e salva no .txt
                salvar_highscore(pontos);
                

                system("pause");
                break;
            }

            // Inicia o modo automático
            case 2:
            {
                printf("Quantidade de discos (1 a 7): ");
                scanf("%d", &numDiscos);

                // Valida a quantidade de discos
                if(numDiscos < 1 || numDiscos > MAX_DISCOS)
                {
                    printf("Quantidade invalida!\n");
                    system("pause");
                    break;
                }

                // Inicializa as torres
                inicializarTorre(torres, numDiscos);

                // Resolve automaticamente utilizando recursão
                totalMovimentos = 0; // Zera para garantir contagem limpa
                resolverAutomatico(
                    torres,
                    numDiscos,
                    0,
                    2,
                    1,
                    &totalMovimentos
                );

                // Exibe as torres após a resolução
                exibir_torre(torres, numDiscos);

                // Mostra a quantidade total de movimentos
                printf("\nMovimentos realizados: %d\n", totalMovimentos);

                system("pause");
                break;
            }

            // Mostra o highscore 
            case 3:
            {
                //          ---> HIGHSCORE <---
                int recorde = ler_highscore();
                
                printf("\n====================================\n");
                printf("       HIGHSCORE ATUAL: %d PONTOS\n", recorde);
                printf("====================================\n\n");

                system("pause");
                break;
            }

            // Encerra o programa
            case 4:
            {
                telaFinal();
                break;
            }

            // Caso o usuário digite uma opção inválida
            default:
            {
                printf("Opcao invalida!\n");
                system("pause");
            }
        }

    } while(opcao != 4); // Repete o menu enquanto a opção não for sair

    return 0;
}