#include <stdio.h>

#define linhas 10
#define colunas 10

int main(){
    char coordenadas1[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int coordenadas2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tabuleiro[linhas][colunas] = {0};
    int navio1[3] = {3, 3, 3}, navio2[3] = {3, 3, 3}, navio3[3] = {3, 3, 3}, navio4[3] = {3, 3, 3};

    // insere os barcos no tabuleiro
    for (int i = 0; i < 3; i++) {

        if (1 < linhas && (5 + i) < colunas) tabuleiro[1][5 + i] = navio1[i]; // posiciona o primeiro navio
        if ((5 + i) < linhas && 1 < colunas) tabuleiro[5 + i][1] = navio2[i]; // posiciona o segundo navio
        if ((6 + i) < linhas && (6 + i) < colunas) tabuleiro[6 + i][6 + i] = navio3[i]; // posiciona o terceiro navio
        if ((0 + i) < linhas && (2 + i) < colunas) tabuleiro[0 + i][2 + i] = navio4[i]; // posiciona o quarto navio
    }

    // seção das habilidades
    // cone
    int hab_l = 2, hab_c = 5; 
    for (int i = 0; i < 3; i++) {
        for (int j = -i; j <= i; j++) {
            if ((hab_l + i) >= 0 && (hab_l + i) < linhas && (hab_c + j) >= 0 && (hab_c + j) < colunas) {
                tabuleiro[hab_l + i][hab_c + j] = 5;
            }
        }
    }

    // cruz
    hab_l = 8, hab_c = 8;
    for (int i = -2; i <= 2; i++) {
        if ((hab_l + i) >= 0 && (hab_l + i) < linhas) tabuleiro[hab_l + i][hab_c] = 5;
        if ((hab_c + i) >= 0 && (hab_c + i) < colunas) tabuleiro[hab_l][hab_c + i] = 5;
    }

    // octaedro
    hab_l = 4, hab_c = 4;
    int r = 2;
    for (int i = -r; i <= r; i++) {
        for (int j = -r; j <= r; j++) {
            int mi = (i < 0) ? -i : i;
            int mj = (j < 0) ? -j : j;
            if (mi + mj <= r) {
                if ((hab_l + i) >= 0 && (hab_l + i) < linhas && (hab_c + j) >= 0 && (hab_c + j) < colunas) {
                    tabuleiro[hab_l + i][hab_c + j] = 5;
                }
            }
        }
    }

    // imprime o tabuleiro no terminal
    printf("   ");
    for (int i = 0; i < 10; i++) printf(" %c", coordenadas1[i]);
    printf("\n");

    for (int i = 0; i < linhas; i++) {
        printf("%2d ", coordenadas2[i]);
        for (int j = 0; j < colunas; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}