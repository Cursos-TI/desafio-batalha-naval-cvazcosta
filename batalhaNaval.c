#include <stdio.h>

#define LINHAS 3
#define COLUNAS 5

int main()
{
  int l, c;
  int lin, col;
  int soma;
  int colunaCentral = COLUNAS / 2;
  int linhaCentral = LINHAS / 2;
  int tabuleiro[10][10] = {0};
  
  /*
    Definindo o cone
    A variável lin determina qual a linha do tabuleiro que quero colocar o
    topo do cone (valor máximo: 7)
    A variável col determina qual a coluna do tabuleiro que quero colocar o
    topo do cone (valor máximo: 5)
  */
  soma = 0;
  for (l = 0, lin = 0; l < LINHAS; l++, lin++)
  {
    for (c = 0, col = 5; c < COLUNAS; c++, col++)
    {
      if ((c >= (colunaCentral - soma)) && (c <= (colunaCentral + soma)))
      {
        tabuleiro[lin][col] = 1;
      }
      else
      {
        tabuleiro[lin][col] = 0;
      }      
    }
    soma++;
  }

  // Definindo o octaedro
  soma = 0;
  for (l = 0, lin = 4; l < LINHAS; l++, lin++)
  {
    for (c = 0, col = 0; c < COLUNAS; c++, col++)
    {
      if ((c >= (colunaCentral - soma)) && (c <= (colunaCentral + soma)))
      {
        tabuleiro[lin][col] = 1;
      }
      else
      {
        tabuleiro[lin][col] = 0;
      }      
    }
    /*
      Após o preenchimento da linha central, o intervalo de preenchimento vai
      reduzindo até que somente a coluna base seja preenchida na última linha
    */
    if (l < linhaCentral)
    {      
      soma++;
    } else
    {
      soma--;
    }    
  }
  
  // Definindo a cruz
  for (l = 0, lin = 7; l < LINHAS; l++, lin++)
  { 
    // Quando a linha central for percorrida todas as colunas serão 1
    if (l == linhaCentral)
    {
      soma = colunaCentral;
    } else
    {
      soma = 0;
    }

    for (c = 0, col = 4; c < COLUNAS; c++, col++)    
    {
      if ((c >= (colunaCentral - soma)) && (c <= (colunaCentral + soma)))
      {
        tabuleiro[lin][col] = 1;
      }
      else
      {
        tabuleiro[lin][col] = 0;
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