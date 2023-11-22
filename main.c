#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct Velha {
    int i;
    int j;
    int linha;
    int coluna;
    int jogador;
    int ganhou;
    int jogadas;
    int opcao;
    int op;
    char tabu[3][3];
} Velha;

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Portuguese_Brazil");

    Velha jogo;

    do {
        printf("\n\t-> Jogo da velha <-\n");
        printf("\n\n\n\tDigite (1) para jogar\n\n\tDigite (2) para Ver os créditos\n\n\tDigite (3) para sair\n\n");
        scanf("%d", &jogo.op);

        while (getchar() != '\n');  
        system("cls");

        switch (jogo.op) {
            case 1: {
                do {
                    jogo.jogador = 1;
                    jogo.ganhou = 0;
                    jogo.jogadas = 0;

                    for (jogo.i = 0; jogo.i < 3; jogo.i++) {
                        for (jogo.j = 0; jogo.j < 3; jogo.j++) {
                            jogo.tabu[jogo.i][jogo.j] = ' ';
                        }
                    }

                    do {
                        printf("\n\n\t 1   2   3\n\n");
                        for (jogo.i = 0; jogo.i < 3; jogo.i++) {
                            for (jogo.j = 0; jogo.j < 3; jogo.j++) {
                                if (jogo.j == 0) {
                                    printf("\t");
                                }
                                printf(" %c", jogo.tabu[jogo.i][jogo.j]);
                                if (jogo.j < 2) {
                                    printf(" |");
                                }
                                if (jogo.j == 2) {
                                    printf("   %d", jogo.i + 1);
                                }
                            }
                            if (jogo.i < 2) {
                                printf("\n\t-----------");
                            }
                            printf("\n");
                        }

                        do {
                            printf("\n\n  Jogador %d: Digite a linha e a coluna que deseja jogar:\n", jogo.jogador);
                            scanf("%d%d", &jogo.linha, &jogo.coluna);

                            while (getchar() != '\n');  

                            jogo.linha = jogo.linha - 1;
                            jogo.coluna = jogo.coluna - 1;
                            if (jogo.linha < 0 || jogo.linha > 2 || jogo.coluna < 0 || jogo.coluna > 2 ||
                                jogo.tabu[jogo.linha][jogo.coluna] != ' ') {
                                printf("Jogada inválida. Tente novamente.\n");
                            } else {
                                system("cls");
                            }
                        } while (jogo.linha < 0 || jogo.linha > 2 || jogo.coluna < 0 || jogo.coluna > 2 ||
                                 jogo.tabu[jogo.linha][jogo.coluna] != ' ');

                        if (jogo.jogador == 1) {
                            jogo.tabu[jogo.linha][jogo.coluna] = '0';
                            jogo.jogador++;
                        } else {
                            jogo.tabu[jogo.linha][jogo.coluna] = 'X';
                            jogo.jogador = 1;
                        }

                        jogo.jogadas++;

                        if (jogo.tabu[0][0] == '0' && jogo.tabu[0][1] == '0' && jogo.tabu[0][2] == '0' ||
                            jogo.tabu[1][0] == '0' && jogo.tabu[1][1] == '0' && jogo.tabu[1][2] == '0' ||
                            jogo.tabu[2][0] == '0' && jogo.tabu[2][1] == '0' && jogo.tabu[2][2] == '0') {
                            printf("\nParabéns!!! Jogador 1 venceu!!!\n");
                            getchar();
                            jogo.ganhou = 1;
                        }

                        if (jogo.tabu[0][0] == 'X' && jogo.tabu[0][1] == 'X' && jogo.tabu[0][2] == 'X' ||
                            jogo.tabu[1][0] == 'X' && jogo.tabu[1][1] == 'X' && jogo.tabu[1][2] == 'X' ||
                            jogo.tabu[2][0] == 'X' && jogo.tabu[2][1] == 'X' && jogo.tabu[2][2] == 'X') {
                            printf("\nParabéns!!! Jogador 2 venceu!!!\n");
                            getchar();
                            jogo.ganhou = 1;
                        }

                        if (jogo.tabu[0][0] == '0' && jogo.tabu[1][0] == '0' && jogo.tabu[2][0] == '0' ||
                            jogo.tabu[0][1] == '0' && jogo.tabu[1][1] == '0' && jogo.tabu[2][1] == '0' ||
                            jogo.tabu[0][2] == '0' && jogo.tabu[1][2] == '0' && jogo.tabu[2][2] == '0') {
                            printf("\nParabéns!!! Jogador 1 venceu!!!\n");
                            getchar();
                            jogo.ganhou = 1;
                        }

                        if (jogo.tabu[0][0] == 'X' && jogo.tabu[1][0] == 'X' && jogo.tabu[2][0] == 'X' ||
                            jogo.tabu[0][1] == 'X' && jogo.tabu[1][1] == 'X' && jogo.tabu[2][1] == 'X' ||
                            jogo.tabu[0][2] == 'X' && jogo.tabu[1][2] == 'X' && jogo.tabu[2][2] == 'X') {
                            printf("\nParabéns!!! Jogador 2 venceu!!!\n");
                            getchar();
                            jogo.ganhou = 1;
                        }

                        if (jogo.tabu[0][0] == '0' && jogo.tabu[1][1] == '0' && jogo.tabu[2][2] == '0') {
                            printf("\nParabéns!!! Jogador 1 venceu!!!\n");
                            getchar();
                            jogo.ganhou = 1;
                        }

                        if (jogo.tabu[0][0] == 'X' && jogo.tabu[1][1] == 'X' && jogo.tabu[2][2] == 'X') {
                            printf("\nParabéns!!! Jogador 2 venceu!!!\n");
                            getchar();
                            jogo.ganhou = 1;
                        }

                        if (jogo.tabu[0][2] == '0' && jogo.tabu[1][1] == '0' && jogo.tabu[2][0] == '0') {
                            printf("\nParabéns!!! Jogador 1 venceu!!!\n");
                            getchar();
                            jogo.ganhou = 1;
                        }

                        if (jogo.tabu[0][2] == 'X' && jogo.tabu[1][1] == 'X' && jogo.tabu[2][0] == 'X') {
                            printf("\nParabéns!!! Jogador 2 venceu!!!\n");
                            getchar();
                            jogo.ganhou = 1;
                        }
                    } while (jogo.ganhou == 0 && jogo.jogadas < 9);

                    if (jogo.ganhou == 0) {
                        system("cls");
                        printf("O jogo finalizou sem ganhador!\n");
                        printf("Digite 1 para jogar novamente digite (2) para sair:  ");
                        scanf("%d", &jogo.opcao);
                    }

                    if (jogo.ganhou == 1) {
                        system("cls");
                        printf("O jogo acabou, deseja ir outra partida?\n");
                        printf("Digite 1 para jogar novamente ou digite (2) para sair: ");
                        scanf("%d", &jogo.opcao);
                        
                    }

                } while (jogo.opcao == 1);

                break;
            }
            case 2: {
                printf("\n\tCriado por:\n\n\tArysson André\n\n\tKaike Garcia\n\n\tAnthonny John\n\n\nPressione qualquer tecla: ");
                break;
            }
            case 3: {
                printf("Fechando jogo!\n");
                exit(0);
                break;
            }
            default: {
                printf("Opção inválida\n");
                system("cls");
                break;
            }
        }

        while (getchar() != '\n'); 
        system("cls");
    } while (jogo.op != 1);

    return 0;
}

