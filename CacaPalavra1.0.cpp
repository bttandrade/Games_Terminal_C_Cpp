#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<locale.h>

char tabela[16][16];
char palavras[6][10];
int acertos = 6;
bool palavra1, palavra2, palavra3, palavra4, palavra5, palavra6;

void criarTabela(){
	int i, j;

	srand(time(NULL));
    for(i=0; i<16; i++){
    	for(j=0; j<16; j++){
	        tabela[i][j]= 'A' + (char)(rand()%26);
	    }
    }
}

void resetar(){
	acertos = 6;
	for(int i=0; i<6; i++){
		strcpy(palavras[i], "");
	}
	palavra1 = false, palavra2 = false, palavra3 = false, palavra4 = false, palavra5 = false, palavra6 = false;
}

void adicionarPalavras(int i){
	if(i == 0){
		tabela[5][3] = 'V';
		tabela[6][3] = 'E';
		tabela[7][3] = 'R';
		tabela[8][3] = 'M';
		tabela[9][3] = 'E';
		tabela[10][3] = 'L';
		tabela[11][3] = 'H';
		tabela[12][3] = 'O';
		//
		tabela[7][12] = 'A';
		tabela[7][13] = 'Z';
		tabela[7][14] = 'U';
		tabela[7][15] = 'L';
		//
		tabela[9][8] = 'A';
		tabela[10][9] = 'M';
		tabela[11][10] = 'A';
		tabela[12][11] = 'R';
		tabela[13][12] = 'E';
		tabela[14][13] = 'L';
		tabela[15][14] = 'O';
		//
		tabela[5][3] = 'V';
		tabela[5][4] = 'E';
		tabela[5][5] = 'R';
		tabela[5][6] = 'D';
		tabela[5][7] = 'E';
		//
		tabela[15][1] = 'R';
		tabela[15][2] = 'O';
		tabela[15][3] = 'X';
		tabela[15][4] = 'O';
		//
		tabela[1][15] = 'P';
		tabela[2][15] = 'R';
		tabela[3][15] = 'E';
		tabela[4][15] = 'T';
		tabela[5][15] = 'O';
	}
	if(i == 1){
		tabela[2][9] = 'C';
		tabela[3][9] = 'A';
		tabela[4][9] = 'V';
		tabela[5][9] = 'A';
		tabela[6][9] = 'L';
		tabela[7][9] = 'O';
		//
		tabela[13][15] = 'B';
		tabela[14][15] = 'O';
		tabela[15][15] = 'I';
		//
		tabela[1][1] = 'M';
		tabela[2][2] = 'A';
		tabela[3][3] = 'C';
		tabela[4][4] = 'A';
		tabela[5][5] = 'C';
		tabela[6][6] = 'O';
		//
		tabela[5][10] = 'J';
		tabela[6][11] = 'A';
		tabela[7][12] = 'C';
		tabela[8][13] = 'A';
		tabela[9][14] = 'R';
		tabela[10][15] = 'E';
		//
		tabela[13][3] = 'L';
		tabela[13][4] = 'O';
		tabela[13][5] = 'B';
		tabela[13][6] = 'O';
		//
		tabela[11][5] = 'Z';
		tabela[12][5] = 'E';
		tabela[13][5] = 'B';
		tabela[14][5] = 'R';
		tabela[15][5] = 'A';	
	}	
	if(i == 2){
		tabela[14][3] = 'V';
		tabela[14][4] = 'I';
		tabela[14][5] = 'O';
		tabela[14][6] = 'L';
		tabela[14][7] = 'I';
		tabela[14][8] = 'N';
		tabela[14][9] = 'O';
		//
		tabela[4][14] = 'H';
		tabela[5][14] = 'A';
		tabela[6][14] = 'R';
		tabela[7][14] = 'P';
		tabela[8][14] = 'A';
		//
		tabela[2][15] = 'G';
		tabela[3][15] = 'U';
		tabela[4][15] = 'I';
		tabela[5][15] = 'T';
		tabela[6][15] = 'A';
		tabela[7][15] = 'R';
		tabela[8][15] = 'R';
		tabela[9][15] = 'A';
		//
		tabela[1][4] = 'G';
		tabela[1][5] = 'A';
		tabela[1][6] = 'I';
		tabela[1][7] = 'T';
		tabela[1][8] = 'A';
		//
		tabela[6][6] = 'P';
		tabela[7][6] = 'I';
		tabela[8][6] = 'A';
		tabela[9][6] = 'N';
		tabela[10][6] = 'O';
		//
		tabela[6][4] = 'F';
		tabela[7][5] = 'L';
		tabela[8][6] = 'A';
		tabela[9][7] = 'U';
		tabela[10][8] = 'T';
		tabela[11][9] = 'A';
	}
}

bool tabelaCor(char co1[10], char co2[10]){
	if((strcmp(co1, "d5") == 0) and (strcmp(co2, "d12") == 0) and !palavra1){
		strcpy(palavras[acertos - 1], "vermelho");
		acertos--;
		palavra1 = true;
	}
	else if((strcmp(co1, "m7") == 0) and (strcmp(co2, "p7") == 0) and !palavra2){
		strcpy(palavras[acertos - 1], "azul");
		acertos--;
		palavra2 = true;
	}
	else if((strcmp(co1, "i9") == 0) and (strcmp(co2, "o15") == 0) and !palavra3){
		strcpy(palavras[acertos - 1], "amarelo");
		acertos--;
		palavra3 = true;
	}
	else if((strcmp(co1, "d5") == 0) and (strcmp(co2, "h5") == 0) and !palavra4){
		strcpy(palavras[acertos - 1], "verde");
		acertos--;
		palavra4 = true;
	}
	else if((strcmp(co1, "p1") == 0) and (strcmp(co2, "p5") == 0) and !palavra5){
		strcpy(palavras[acertos - 1], "preto");
		acertos--;
		palavra5 = true;
	}
	else if((strcmp(co1, "b15") == 0) and (strcmp(co2, "e15") == 0) and !palavra6){
		strcpy(palavras[acertos - 1], "roxo");
		acertos--;
		palavra6 = true;
	}
	if(acertos == 0){
		return true;
	}else{
		return false;
	}	
}

bool tabelaInstrumento(char co1[10], char co2[10]){
	if((strcmp(co1, "d14") == 0) and (strcmp(co2, "j14") == 0) and !palavra1){
		strcpy(palavras[acertos - 1], "violino");
		acertos--;
		palavra1 = true;
	}
	else if((strcmp(co1, "o4") == 0) and (strcmp(co2, "o8") == 0) and !palavra2){
		strcpy(palavras[acertos - 1], "harpa");
		acertos--;
		palavra2 = true;
	}
	else if((strcmp(co1, "p2") == 0) and (strcmp(co2, "p9") == 0) and !palavra3){
		strcpy(palavras[acertos - 1], "guitarra");
		acertos--;
		palavra3 = true;
	}
	else if((strcmp(co1, "e1") == 0) and (strcmp(co2, "i1") == 0) and !palavra4){
		strcpy(palavras[acertos - 1], "gaita");
		acertos--;
		palavra4 = true;
	}
	else if((strcmp(co1, "e6") == 0) and (strcmp(co2, "j11") == 0) and !palavra5){
		strcpy(palavras[acertos - 1], "flauta");
		acertos--;
		palavra5 = true;
	}
	else if((strcmp(co1, "g6") == 0) and (strcmp(co2, "g10") == 0) and !palavra6){
		strcpy(palavras[acertos - 1], "piano");
		acertos--;
		palavra6 = true;
	}
	if(acertos == 0){
		return true;
	}else{
		return false;
	}	
}

bool tabelaAnimal(char co1[10], char co2[10]){
	if((strcmp(co1, "j2") == 0) and (strcmp(co2, "j7") == 0) and !palavra1){
		strcpy(palavras[acertos - 1], "cavalo");
		acertos--;
		palavra1 = true;
	}
	else if((strcmp(co1, "p13") == 0) and (strcmp(co2, "p15") == 0) and !palavra2){
		strcpy(palavras[acertos - 1], "boi");
		acertos--;
		palavra2 = true;
	}
	else if((strcmp(co1, "b1") == 0) and (strcmp(co2, "g6") == 0) and !palavra3){
		strcpy(palavras[acertos - 1], "macaco");
		acertos--;
		palavra3 = true;
	}
	else if((strcmp(co1, "k5") == 0) and (strcmp(co2, "p10") == 0) and !palavra4){
		strcpy(palavras[acertos - 1], "jacare");
		acertos--;
		palavra4 = true;
	}
	else if((strcmp(co1, "d13") == 0) and (strcmp(co2, "g13") == 0) and !palavra5){
		strcpy(palavras[acertos - 1], "lobo");
		acertos--;
		palavra5 = true;
	}
	else if((strcmp(co1, "f11") == 0) and (strcmp(co2, "f15") == 0) and !palavra6){
		strcpy(palavras[acertos - 1], "zebra");
		acertos--;
		palavra6 = true;
	}
	if(acertos == 0){
		return true;
	}else{
		return false;
	}	
}

void menu(){
	printf("+----------------------------+\n");
	printf("| Bem-vindo ao Caça Palavras |\n");
	printf("+----------------------------+\n");
	printf("| 1 - Novo Jogo              |\n");
	printf("+----------------------------+\n");
	printf("| 2 - Regras                 |\n");
	printf("+----------------------------+\n");
	printf("| 3 - Sair                   |\n");
	printf("+----------------------------+\n");
}

void regras(){
	printf("+----------------------------------------------------------------+\n");
	printf("  1- Um tema aleatário será escolhido para você\n");
	printf("+----------------------------------------------------------------+\n");
	printf("  2- Você deverá procurar na tabela 6 palavras escondidas\n");
	printf("+----------------------------------------------------------------+\n");
	printf("  3- Ao encontrar uma palavra você deverá digitar a coordenada \nde sua primeira letra e apertar enter\n");
	printf("+----------------------------------------------------------------+\n");
	printf("  4- Então deverá digitar a coordenada da última letra da palavra \nencontrada e apertar enter\n");
	printf("+----------------------------------------------------------------+\n");
	printf("  5- Sempre inicie a coordenada pela parte superior (a-p)\n");
	printf("+----------------------------------------------------------------+\n\n");
}

int main(){
	bool sair; 

	while(!sair){
		int i, j, op, sorteio;
		char co1[10] = " ", co2[10] = " ";
		bool vitoria = false;
		
		setlocale(LC_ALL, "Portuguese");
		criarTabela();
		system("cls");
		menu();
		scanf("%d", &op);
		switch(op){
			case 1:
				system("cls");	
				printf("Um tema aleatário será escolhido para você\n");
				printf("Você deverá encontrar as 6 palavras escondidas\n\n");
				printf("Boa Sorte!\n\n");
				system("pause");
				system("cls");
				resetar();				
				srand(time(NULL));
				sorteio = rand() % 3;	
				adicionarPalavras(sorteio);
				while(!vitoria){
					if(sorteio == 0){
						printf("TEMA: CORES\n");
					}else if(sorteio == 1){
						printf("TEMA: ANIMAIS\n");
					}else{
						printf("TEMA: INSTRUMENTOS MUSICAIS\n");
					}
					printf("    a--b--c--d--e--f--g--h--i--j--k--l--m--n--o--p\n");
					for(i=0;i<16;i++){
						if(i<10){
							printf(" %d-", i);
						}else{
							printf("%d-", i);
						}
						for(j=0;j<16;j++) {
							printf(" %c ",tabela[i][j]);
						}
						putchar('\n');				
					}
					printf("\nPalavras para encontrar: %d", acertos);
					printf("\nPalavras encontradas: ");
					printf("%s %s %s %s %s %s", (palavras[5]), (palavras[4]), (palavras[3]), (palavras[2]), (palavras[1]), (palavras[0]));						
					printf("\n\nDigite as coordenadas da primeira letra da palavra encontrada: ");
					scanf("%s", &co1);
					printf("\nDigite as coordenadas da última letra da palavra encontrada: ");
					scanf("%s", &co2);
					system("cls");
					if(sorteio == 0){
						vitoria = tabelaCor(co1, co2);							
					}else if(sorteio == 1){
						vitoria = tabelaAnimal(co1, co2);
					}else{
						vitoria = tabelaInstrumento(co1, co2);
					}
				}				
				break;			
			case 2:
				system("cls");
				regras();
				system("pause");
				break;
			case 3:
				system("cls");
				sair = true;
				break;			
			default:
				fflush(stdin);
				break;
		}
		if(vitoria){
			printf("Parabéns, você achou todas as palavras!!\n\n");
			printf("Palavras encontradas: ");
			printf("%s %s %s %s %s %s\n\n", (palavras[5]), (palavras[4]), (palavras[3]), (palavras[2]), (palavras[1]), (palavras[0]));
			system("pause");
		}
	}
}			