#include <stdio.h>

#define LINHAS 3
#define COLUNAS 5

int main()
{
  int l, c;
  int lin, col;

  int colBase = COLUNAS / 2;
  int tabuleiro[10][10] = {0};

  // // Posicionando navio1 na vertical a partir da lin 3 na col 2
  // for (l = 2; l < 5; l++)
  // {
  //     tabuleiro[l][1] = navio1[0];
  // }

  // // Posicionando navio2 na horizontal na lin 9 a partir col 7
  // for (c = 6; c < 9; c++)
  // {
  //     tabuleiro[8][c] = navio2[0];
  // }

  // // Posicionando o navio3 na diagonal
  // for (l = 1, c = 4; l < 4; l++, c++)
  // {
  //     tabuleiro[l][c] = navio3[0];
  // }

  // // Posicionando o navio4 na diagonal
  // for (l = 7, c = 1; l < 10; l++, c++)
  // {
  //     tabuleiro[l][c] = navio4[0];
  // }

  // Criando uma matriz "cônica"
  // A variável lin determina qual a linha do tabuleiro que quero colocar o
  // topo do cone. Valor máximo: 7
  // A variável col determina qual a coluna do tabuleiro que quero colocar o
  // topo do cone. Valor maximo: 5
  for (l = 0, lin = 0; l < LINHAS; l++, lin++)
  {
    for (c = 0, col = 5; c < COLUNAS; c++, col++)
    {
      // Se for a 1ª linha, colocar o valor 1 apenas no índice central
      // Senão, colocar nos intervalos definidos
      if (!l)
      {
        if (c == colBase)
        {
          tabuleiro[lin][col] = 1;
        }
        else
        {
          tabuleiro[lin][col] = 0;
        }
      }
      else
      {
        if ((c >= (colBase - l)) && (c <= (colBase + l)))
        {
          tabuleiro[lin][col] = 1;
        }
        else
        {
          tabuleiro[lin][col] = 0;
        }
      }
    }
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
