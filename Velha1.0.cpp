#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

char v[10] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'};
bool vitoria = false;

void regras(){
	printf("Dois jogadores são necessários\n");
    printf("O primeiro jogador é o círculo\n");
    printf("O segundo jogador é o xis\n\n");
    printf("Para jogar escolha em sua vez um número de 1 a 9\n");
    printf("Essas são as posições:\n\n");
    printf("_7_|_8_|_9_\n");
    printf("_4_|_5_|_6_\n");
    printf(" 1 | 2 | 3 \n\n");
}

void testeVitoria(int i){
	char x = ' ';

	if(i == 1){
		x = 'O';
	}else{
		x = 'X';
	}
	if (v[0] == x && v[1] == x && v[2] == x) {
        vitoria = true;
    }else if (v[3] == x && v[4] == x && v[5] == x) {
        vitoria = true;
    }else if (v[6] == x && v[7] == x && v[8] == x) {
        vitoria = true;
    }else if (v[0] == x && v[3] == x && v[6] == x) {
        vitoria = true;
    }else if (v[1] == x && v[4] == x && v[7] == x) {
        vitoria = true;
    }else if (v[2] == x && v[5] == x && v[8] == x) {
        vitoria = true;
    }else if (v[0] == x && v[4] == x && v[8] == x) {
        vitoria = true;
    }else if (v[2] == x && v[4] == x && v[6] == x) {
        vitoria = true;
    }
}

void velha(){
	printf("\n  %c | %c | %c\n", v[6], v[7], v[8]);
	printf(" --- --- ---  \n");
	printf("  %c | %c | %c\n", v[3], v[4], v[5]);
    printf(" --- --- ---  \n");
    printf("  %c | %c | %c\n", v[0], v[1], v[2]);
}
	
void jogada(char jogador[20], int i){
	int jog;
	bool valido = false;
	char x = ' ';

	if(i==1){
		x = 'O';
	}else{
		x = 'X';
	}
	while(!valido){
		printf("\n%s - Escolha de 1 a 9 para decidir onde jogar: ", jogador);
		scanf("%d", &jog);
		fflush(stdin);
		for(int i=0; i<9; i++){
			if(jog == i+1 && v[i] != 'O' && v[i] != 'X'){
				v[i] = x;
				valido = true;
			}
		}
		if(!valido){
			system("cls");
			velha();
			printf("\nJogada Inválida\n");
		}
	}
}

void resetar(){
	for(int i = 0; i<9; i++){
		v[i] = ' ';
	}
}

void menu(){
	printf("--------------------------\n");
	printf("*     JOGO DA VELHA     *\n");
	printf("--------------------------\n");
	printf("*  1 - Novo jogo        *\n");
	printf("--------------------------\n");
	printf("*  2 - Regras           *\n");
	printf("--------------------------\n");
	printf("*  3 - Sair             *\n");
	printf("--------------------------\n");
}

int main(){
	int escolha = 0, qntVitA = 0, qntVitB = 0, emp = 0, inverte = 2;
	bool sair = false, novamente = true;
	char jogador1[20], jogador2[20];

	setlocale(LC_ALL, "Portuguese");
    while(!sair){
    	system("cls");
    	menu();
		scanf("%d", &escolha);
		fflush(stdin);
		switch(escolha){
			case 1:
				qntVitA = 0;
				qntVitB = 0; 
				emp = 0;
				inverte = 2;
				system("cls");
				printf("Nome do Jogador 1: ");
				scanf("%s", &jogador1);
				fflush(stdin);
				printf("\nNome do Jogador 2: ");
				scanf("%s", &jogador2);
				fflush(stdin);
				novamente = true;

				while(novamente){		
				    int empate = 0;
				    bool vitA = false, vitB = false, valido = false;
				    char jogarNovamente = ' ';
				    velha();
					while(vitA == false && vitB == false){
						if(inverte%2==0){							
							jogada(jogador1, 1);
							empate++;						
							system("cls");
					    	velha();
					    	testeVitoria(1);
					    	if(vitoria){
					    		vitA = true;
					    		break;
							}
							if(empate == 5){
								break;
							}
					        jogada(jogador2, 0);
							system("cls");
							velha();
					 		testeVitoria(0);
					 		if(vitoria){
					    		vitB = true;
							}
						}else{
							jogada(jogador2, 0);
							empate++;
							system("cls");
							velha();
					 		testeVitoria(0);
					 		if(vitoria){
					    		vitB = true;
					    		break;
							}
							if(empate == 5){
								break;
							}
							jogada(jogador1, 1);						
							system("cls");
					    	velha();
					    	testeVitoria(1);
					    	if(vitoria){
					    		vitA = true;
							}						
						}
				    }
					if(vitA){
				        qntVitA++;
				    }else if (vitB){
				        qntVitB++;
				    }else{
				        emp++;
				    }
				    valido = false;
				    while(!valido){
				    	printf("\n%s: %d\n", jogador1, qntVitA);
				    	printf("%s: %d\n", jogador2, qntVitB);
				    	printf("Empates: %d\n", emp);
					    printf("\nContinuar? (s/n): ");
					    scanf("%c", &jogarNovamente);
					    fflush(stdin);
					    if(jogarNovamente == 's'){
					    	novamente = true;
					    	valido = true;
					    	vitoria = false;
					    	system("cls");
					    	inverte++;
							resetar();
						}else if(jogarNovamente == 'n'){
							valido = true;
							novamente = false;
							vitoria = false;
							resetar();
						}
					}
				}
				break;
			case 2:
				system("cls");
				regras();
				printf("Pressione enter para voltar\n");
				getchar();
				break;
			case 3:
				system("cls"); 
				sair = true;
				break;
			default:
				system("cls");
		}	
	} 		
}