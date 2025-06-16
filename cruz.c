#include <stdio.h>

#define LINHAS 3
#define COLUNAS 5

int main()
{
  int l, c;
  int colunaCentral = COLUNAS / 2;
  int linhaCentral = LINHAS / 2;
  int soma = 0;

  for (l = 0; l < LINHAS; l++)
  {    
    if (l == linhaCentral)
    {
      soma = colunaCentral;
    } else
    {
      soma = 0;
    }

    for (c = 0; c < COLUNAS; c++)
    {      
      if ((c >= (colunaCentral - soma)) && (c <= (colunaCentral + soma)))
      {
        printf("1 ");
      }
      else
      {
        printf("0 ");
      }      
    }
    printf("\n");
  }

  return (0);
}