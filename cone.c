#include <stdio.h>

#define LINHAS 5
#define COLUNAS 9

int main()
{
  int l, c;
  int colunaCentral = COLUNAS / 2;
  int soma = 0;

  for (l = 0; l < LINHAS; l++)
  {
    for (c = 0; c < COLUNAS; c++)
    {
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
    }
    printf("\n");
    soma++;
  }
}