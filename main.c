#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char *argv[]) {
	
	//area da declaração das variaveis
	int i,j,linha,coluna, jogador, ganhou, jogadas, opcao, op;
	char tabu[3][3];
	FILE *rak;
	
	struct jogadores{
		char nome[500];
		int id;
	};
	
	struct jogadores jo;
	
	do{
		//aqui ele irar fazer imprimir todo o menu
		printf("\n\tJogo da velha\n");
		printf("\n\n\n\tDigite (1) para jogar\n\n\tDigite (2) para Ver o ranking\n\n\tDigite (3) para ver os creditos\n\n\tDigite (4) para Sair\n\n");
		scanf("%d",&op);
		//o system será usado para que as informações apresentadas anteriomente não fique na tela, deixando assim mais dinamico
		system("cls");
		
			//dando a possibilidade de poder escolher as opções apresentadas anteriormente
			switch(op){
				case 1:{
					
							do{
						jogador = 1;
						ganhou = 0;
						jogadas = 0;
						
						//criação do tabuleiro
						for (i=0;i<3;i++){
							
							for(j=0;j<3;j++){
								
								tabu[i][j]=' ';
											
							}
							
						}
						
						
						do{
							//as coordenadas do tabuleiro, que ira reprentar a localização das possiveis jogadas
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
									printf("\nParabens!!! Jogador 1 venceu!!!\n");
									getchar();
									ganhou = 1;
								}
								
							if(tabu [0][0] == 'X' && tabu [0][1] == 'X' && tabu [0][2] == 'X' ||
								tabu [1][0] == 'X' && tabu [1][1] == 'X' && tabu [1][2] == 'X' ||
								tabu [2][0] == 'X' && tabu [2][1] == 'X' && tabu [2][2] == 'X'){
									printf("\nParabens!!! Jogador 2 venceu!!!\n");
									getchar();
									ganhou = 1;
								}
								
							if(tabu [0][0] == '0' && tabu[1][0] == '0' && tabu [2][0] == '0' ||
								tabu [0][1] == '0' && tabu[1][1] == '0' && tabu [2][1] == '0'||
								tabu [0][2] == '0' && tabu[1][2] == '0' && tabu [2][2] == '0'){
									printf("\nParabens!!! Jogador 1 venceu!!!\n");
									getchar();
									ganhou = 1;
									}	
									
							if(tabu [0][0] == 'X' && tabu[1][0] == 'X' && tabu [2][0] == 'X' ||
								tabu [0][1] == 'X' && tabu[1][1] == 'X' && tabu [2][1] == 'X'||
								tabu [0][2] == 'X' && tabu[1][2] == 'X' && tabu [2][2] == 'X'){
									printf("\nParabens!!! Jogador 2 venceu!!!\n");
									getchar();
									ganhou = 1;
									}	
							
							if(tabu [0][0] == '0' && tabu[1][1] == '0' && tabu [2][2] == '0'){
								printf("\nParabens!!! Jogador 1 venceu!!!\n");
								getchar();
								ganhou = 1;
							}
							
							if(tabu [0][0] == 'X' && tabu[1][1] == 'X' && tabu [2][2] == 'X'){
								printf("\nParabens!!! Jogador 2 venceu!!!\n");
								getchar();
								ganhou = 1;
							}
							
							if(tabu [0][2] == '0' && tabu[1][1] == '0' && tabu [2][0] == '0'){
								printf("\nParabens!!! Jogador 1 venceu!!!\n");
								getchar();
								ganhou = 1;
							}
							
							if(tabu [0][2] == 'X' && tabu[1][1] == 'X' && tabu [2][0] == 'X'){
								printf("\nParabens!!! Jogador 2 venceu!!!\n");
								getchar();
								ganhou = 1;
							}
						}while(ganhou == 0 && jogadas < 9);
						
						if((ganhou == 1 && jogador == 1) || (ganhou == 1 && jogador == 2)){
									
							rak= fopen("Ranking.txt", "r");
							
							if(rak == NULL){
								jo.id=1;
							}else{
								jo.id++;	
							}
																																
							rak = fopen("Ranking.txt", "a");
							
							if(rak == NULL){
								printf("Erro ao abrir o arquivo!\n");
								getchar();
							}
							
							printf("\nDigite seu nome, ganhador:");
							scanf("%s",jo.nome);	
					
							
							fprintf(rak,"\n%d:%s. Ganhou!!!",jo.id,jo.nome);
								
							fclose(rak);
								
							printf("Seu nome foi gravado com sucesso!!!");
							
						    jogadas = 0;
						}
						
						if(ganhou == 0){
							system("cls");
							printf("O jogo finalizou sem ganhador!"); 	
							printf("\nDigite 1 para jogar novamente: ");
							printf("\nDigite qualquer outra coisa para sair: ");
							scanf("%d",&opcao);
							
						}
						
						if(ganhou == 1){
							system("cls");
							printf("O jogo acabou, deseja ir outra partida?");
							printf("\nDigite 1 para jogar novemente: ");
							printf("\nDigite qualquer outra coisa para sair: ");
							scanf("%d",&opcao);
						}
						
						if(opcao > 1){
							rak = fopen("Ranking.txt","a");
							fprintf(rak,"\n----------------------------------\n\n");
							
						}
						
					}while(opcao == 1);
					
					break;
				}
				case 2:{
					
					printf("Arysson sempre em primeiro\nKaike em segundo\nAnthonny nem em terceiro, esse coitado!!!\n\nPrecione qualquer tecla: ");
					getchar();
					
					break;
				}
				case 3:{
					
					printf("Criador por:\nArysson Andre\nKaike Garcia\nAnthonny John\n\n\nPrecione qualquer tecla: ");
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
					
					printf("Opcao invalida");
					system("cls");
					
					break;
				}
			}
		getchar();
		system("cls");
		}while(op != 1);
	
	return 0;
}
