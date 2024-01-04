#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#include<locale.h>

char listaPalavras[8][10] = {"alugar", "cadeira", "moto", "destino", "gato", "louco", "muito", "caneta"};
char palavra[10];
char palavraEscondida[10];

void sortearPalavra() {
    int sorteio;

    srand(time(NULL));
    sorteio = rand()%4;
    strcpy(palavra, listaPalavras[sorteio]);
    for (int i = 0; i < 10; i++) {
        if (palavra[i] != '\0') {
            palavraEscondida[i] = '_';
        }
    }
}

void boneco(int erro) {
    char x1 = ' ', x2 = ' ', x3 = ' ', x4 = ' ', x5 = ' ', x6 = ' ';

    if (erro >= 1) {
        x1 = 'O';
    }
    if (erro >= 2) {
        x2 = '(';
    }
    if (erro >= 3) {
        x3 = '|'; 
    }
    if (erro >= 4) {
        x4 = ')';
    }
    if (erro >= 5) {
        x5 = '(';
    }
    if (erro >= 6) {
        x6 = ')'; 
    }
    printf("\n++========+");
    printf("\n||        |");
    printf("\n||        %c", x1);
    printf("\n||       %c%c%c", x2, x3, x4);
    printf("\n||       %c %c", x5 , x6);
    printf("\n++\n\n");
}

void regras() {
    system("cls");
    printf("Uma palavra aleatória será selecionada\n\n");
    printf("Você deverá descobrir qual é a palavra escolhendo uma letra por vez\n\n");
    printf("Caso erre 6 vezes o jogo se encerra\n\n");
    system("pause");
}

void menu() {
    system("cls");
    printf("+----------------+\n");
    printf("+ 1 - Novo Jogo  +\n");
    printf("+----------------+\n");
    printf("+ 2 - Regras     +\n");
    printf("+----------------+\n");
    printf("+ 3 - Sair       +\n");
    printf("+----------------+\n");
}

void novoJogo() {
    bool vitoria, valido, forca;
    int erro = 0, diferente = 0;
    char erros[6] = {' ', ' ', ' ', ' ', ' ', ' '};
    char letra;

    system("cls");
    erro = 0;
    for (int i = 0; i < 6; i++) {
        erros[i] = ' ';
    }
    fflush(stdin);
    while (!vitoria and !forca) {
        valido = false;
        while (!valido) {
            system("cls");
            boneco(erro);
            for (int i = 0; i < 10; i++) {         
                printf("%c ", palavraEscondida[i]);
            }
            printf("\n\nEscolha uma letra (erros: %c %c %c %c %c %c)\n", erros[0], erros[1], erros[2], erros[3], erros[4], erros[5]);
            scanf("%c", &letra);
            fflush(stdin);
            if (isdigit(letra) > 0 or ispunct(letra) > 0) {
                system("cls");
                printf("Entrada inválida!\n\n");
                system("pause");
            } else {
                valido = true;
                for (int i = 0; i < 10; i++) {
                    if (letra == erros[i]) {
                        valido = false;
                        system("cls");
                        printf("Já na lista de erros!!\n\n");
                        system("pause");
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < 10; i++) {
            if (letra == palavra[i]) {
                palavraEscondida[i] = letra;
            } else {
                diferente++;
            }
        }
        if (diferente == 10) {
            erros[erro] = letra;
            erro++;
        }
        diferente = 0;
        if (strcmp(palavra, palavraEscondida) == 0) {
            vitoria = true;
        } else if (erro == 6) {
            forca = true;
        }
    }
    if (vitoria) {
        system("cls");
        printf("Palavra encontrada: %s\n\n", palavra);
        printf("Parabéns!!\n\n");
        system("pause");
    } else if (forca) {
        system("cls");
        boneco(erro);
        printf("Forca!!\n\n");
        printf("Erros: %c %c %c %c %c %c\n\n", erros[0], erros[1], erros[2], erros[3], erros[4], erros[5]);
        system("pause");
    }
}

int main() {
    int op;
    bool sair;

    setlocale(LC_ALL, "Portuguese");
    while (!sair) {
        sortearPalavra();
        menu();
        scanf("%d", &op);
        switch (op) {
        case 1:
            novoJogo();
            break;
        case 2:
            regras();
            break;
        case 3:
            system("cls");
            sair = true;
            break;
        default:
            system("cls");
            printf("Entrada inválida\n\n");
            system("pause");
            break;
        }
    }    
}