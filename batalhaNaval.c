#include <stdio.h>

int main(){
    int index;
    char coordenadas1[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int coordenadas2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tabuleiro[10][10] = {0};
    int navio1[3] = {3, 3, 3};
    int navio2[3] = {3, 3, 3};

    // insere os barcos no tabuleiro
    for (int i = 0; i < 10; i++) // linhas da matriz
    {
        for (int j = 0; j < 10; j++) // colunas das matriz
        {
           if (i == 1 && j == 6){tabuleiro[i][j] = navio1[1];} 
           else if (i == 1 && j == 7) {tabuleiro[i][j] = navio1[1];}
           else if (i == 1 && j == 8) {tabuleiro[i][j] = navio1[1];}
           else if (i == 6 && j == 1) {tabuleiro[i][j] = navio1[1];}
           else if (i == 7 && j == 1) {tabuleiro[i][j] = navio1[1];}
           else if (i == 8 && j == 1) {tabuleiro[i][j] = navio1[1];}          
        } 
        
    }
    printf("   ");
    for (int i = 0; i < 10; i++){printf (" %c", coordenadas1[i]);} // coordenadas das linhas
    printf("\n");

    // imprime o tabuleiro no terminal
    for (int i = 0; i < 10; i++) // linhas da matriz
    {   printf("%2d ", coordenadas2[i]); // coordenadas das colunas
        for (int j = 0; j < 10; j++) // colunas das matriz
        {
           printf(" %d", tabuleiro[i][j]);        
        } 
        printf("\n");
    }

    return 0;
}