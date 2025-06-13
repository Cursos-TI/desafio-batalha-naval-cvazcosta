#include <stdio.h>

#define LINHAS 3
#define COLUNAS 5

int main()
{
  int l, c;
  int colBase = COLUNAS / 2;
  int soma = 0;

  for (l = 0; l < LINHAS; l++)
  {
    for (c = 0; c < COLUNAS; c++)
    {
      // if (!l)
      // {
      //   if (c == colBase)
      //   {
      //     printf("1 ");
      //   }
      //   else
      //   {
      //     printf("0 ");
      //   }
      // }
      // else
      // {}
      if ((c >= (colBase - soma)) && (c <= (colBase + soma)))
      {
        printf("1 ");
      }
      else
      {
        printf("0 ");
      }
    }
    printf("\n");
    soma++;
  }
}