#include <stdio.h>

#define LINHAS 3
#define COLUNAS 5

int main()
{
  int l, c;
  int tabuleiro[10][10] = {0};
  int navio = 3;

  // Posicionando navio1 na vertical a partir da lin 3 na col 2
  for (l = 2; l < 5; l++)
  {
      tabuleiro[l][1] = navio;
  }

  // Posicionando navio2 na horizontal na lin 9 a partir col 7
  for (c = 6; c < 9; c++)
  {
      tabuleiro[8][c] = navio;
  }

  // Posicionando o navio3 na diagonal
  for (l = 1, c = 4; l < 4; l++, c++)
  {
      tabuleiro[l][c] = navio;
  }

  // Posicionando o navio4 na diagonal
  for (l = 7, c = 1; l < 10; l++, c++)
  {
      tabuleiro[l][c] = navio;
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

  return (0);
}
