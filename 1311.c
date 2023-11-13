#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL, "Portuguese_Brazil");
	int i,j,linha,coluna, jogador, ganhou, jogadas, opcao, op;
	char tabu[3][3];
	
	do{
		printf("\n\t-> Jogo da Velha <- \n");
		printf("\n\n\n\tDigite (1) para Jogar\n\n\tDigite (2) para Ver o Ranking\n\n\tDigite (3) para Ver os Créditos\n\n\tDigite (4) para Sair\n\n");
		scanf("%d",&op);
		system("cls");
		
			switch(op){
				case 1:{
					
							do{
						jogador = 1;
						ganhou = 0;
						jogadas = 0;
						
						for (i=0;i<3;i++){
							
							for(j=0;j<3;j++){
								
								tabu[i][j]=' ';
											
							}
							
						}
						
						
						do{
						
							printf("\n\n\t 0   1   2\n\n");
							for (i=0;i<3;i++){
								
								for(j=0;j<3;j++){
									if(j == 0){
										printf("\t");
									}
									
									printf(" %c",tabu[i][j]);
									
									if(j < 2){
									
										printf(" |");
									}
									if(j == 2){
										
										printf("   %d",i);
									}
										
								}
								if(i < 2){
									printf("\n\t-----------");
								}
								printf("\n");
								
							}
							do{
							printf("\n\n  Jogador %d: Digite a linha e a coluna que deseja jogar:\n",jogador);
							scanf("%d%d",&linha,&coluna);
							if(linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabu[linha][coluna] != ' '){
								
							}else{
								
								system("cls");
							}
							
							}while(linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabu[linha][coluna] != ' ' );
						
							if(jogador == 1){
								tabu [linha][coluna] = '0';	
								jogador ++;
							}else{	
								tabu [linha][coluna] = 'X';
								jogador=1;
							}
							
							jogadas++;
							
							if(tabu [0][0] == '0' && tabu [0][1] == '0' && tabu [0][2] == '0' ||
								tabu [1][0] == '0' && tabu [1][1] == '0' && tabu [1][2] == '0' ||
								tabu [2][0] == '0' && tabu [2][1] == '0' && tabu [2][2] == '0'){
									printf("\nParabéns!!! Jogador 1 venceu!!!\n");
									getchar();
									ganhou = 1;
								}
								
							if(tabu [0][0] == 'X' && tabu [0][1] == 'X' && tabu [0][2] == 'X' ||
								tabu [1][0] == 'X' && tabu [1][1] == 'X' && tabu [1][2] == 'X' ||
								tabu [2][0] == 'X' && tabu [2][1] == 'X' && tabu [2][2] == 'X'){
									printf("\nParabéns!!! Jogador 2 venceu!!!\n");
									getchar();
									ganhou = 1;
								}
								
							if(tabu [0][0] == '0' && tabu[1][0] == '0' && tabu [2][0] == '0' ||
								tabu [0][1] == '0' && tabu[1][1] == '0' && tabu [2][1] == '0'||
								tabu [0][2] == '0' && tabu[1][2] == '0' && tabu [2][2] == '0'){
									printf("\nParabéns!!! Jogador 1 venceu!!!\n");
									getchar();
									ganhou = 1;
									}	
									
							if(tabu [0][0] == 'X' && tabu[1][0] == 'X' && tabu [2][0] == 'X' ||
								tabu [0][1] == 'X' && tabu[1][1] == 'X' && tabu [2][1] == 'X'||
								tabu [0][2] == 'X' && tabu[1][2] == 'X' && tabu [2][2] == 'X'){
									printf("\nParabéns!!! Jogador 2 venceu!!!\n");
									getchar();
									ganhou = 1;
									}	
							
							if(tabu [0][0] == '0' && tabu[1][1] == '0' && tabu [2][2] == '0'){
								printf("\nParabéns!!! Jogador 1 venceu!!!\n");
								getchar();
								ganhou = 1;
							}
							
							if(tabu [0][0] == 'X' && tabu[1][1] == 'X' && tabu [2][2] == 'X'){
								printf("\nParabéns!!! Jogador 2 venceu!!!\n");
								getchar();
								ganhou = 1;
							}
							
							if(tabu [0][2] == '0' && tabu[1][1] == '0' && tabu [2][0] == '0'){
								printf("\nParabéns!!! Jogador 1 venceu!!!\n");
								getchar();
								ganhou = 1;
							}
							
							if(tabu [0][2] == 'X' && tabu[1][1] == 'X' && tabu [2][0] == 'X'){
								printf("\nParabéns!!! Jogador 2 venceu!!!\n");
								getchar();
								ganhou = 1;
							}
						}while(ganhou == 0 && jogadas < 9);
						
						
						
						if(ganhou == 0){
							printf("\n O jogo finalizou sem ganhador!\n"); 	
							printf("\nDigite [1] para jogar novamente: \n");
							scanf("%d",&opcao);
							
						}
					}while(opcao == 1);
					
					break;
				}
				case 2:{
					
					printf("Arysson sempre em primeiro\nKaike em segundo\nAnthonny nem em terceiro, esse coitado :(\n\nPrecione qualquer tecla: ");
					getchar();
					
					break;
				}
				case 3:{
					
					printf("Criador por:\nArysson André\nKaike Garcia\nAnthonny John\n\nCodigo inspirado no canal: Programe seu futuro.\n\nPrecione qualquer tecla: ");
					getchar();					
					
					break;
				}
				case 4:{
					
					printf("Fechando jogo!");
					getchar();
					exit(0);
					break;
				}
				
				default:{
					
					printf("Opção invalida");
					system("cls");
					
					break;
				}
			}
		getchar();
		system("cls");
		}while(op != 1);
	
	return 0;
}
