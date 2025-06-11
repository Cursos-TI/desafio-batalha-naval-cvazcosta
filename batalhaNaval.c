#include <stdio.h>

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    int l, c;
    int col, lin;

    int tabuleiro[10][10] = {0};

    int navio1[1] = {3};
    int navio2[1] = {3};
    int navio3[1] = {3};
    int navio4[1] = {3};

    // Posicionando navio1 na vertical a partir da lin 3 na col 2
    for (l = 2; l < 5; l++)
    {
        tabuleiro[l][1] = navio1[0];
    }

    // Posicionando navio2 na horizontal na lin 9 a partir col 7
    for (c = 6; c < 9; c++)
    {
        tabuleiro[8][c] = navio2[0];
    }

    // Posicionando o navio3 na diagonal
    for (l = 1, c = 4; l < 4; l++, c++)
    {
        tabuleiro[l][c] = navio3[0];
    }

    // Posicionando o navio4 na diagonal
    for (l = 7, c = 1; l < 10; l++, c++)
    {
        tabuleiro[l][c] = navio4[0];
    }    

    // Imprimindo o tabuleiro após as inserções
    for (l = 0; l < 10; l++)
    {
        for (c = 0; c < 10; c++)
        {
            printf("%d ", tabuleiro[l][c]);
        }
        printf("\n");
    }    

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return (0);
}
