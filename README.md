# Desafio Nível Mestre

## Acerca das soluções encontradas

As soluções aqui apresentadas provavelmente não são as melhores possíveis. Elas refletem o grau de proficiência de um estudante iniciante no mundo da programação após a conclusão de um curso introdutório à linguagem de programação em C.

Elas, no entanto, contêm a honestidade de quem evitou o caminho mais fácil e tentou encontrar saídas utilizando o próprio raciocínio e as técnicas aprendidas ao longo deste curso e em alguns livros sobre o tema.

Confesso que inicialmente fiquei surpreso com a **aparente** simplicidade das atividades. Contudo, quando tive de parar para pensar na solução me vi obrigado a pensar de forma algorítmica, buscando resolver o problema passo a passo e nisso residiu o grande desafio. Quanto mais familiaridade obtenho com a linguagem em si percebo a necessidade de melhorar o meu processo de resolução de problemas.

Primeiro, me propus a criar um loop capaz de desenhar a forma geométrica requisitada e depois fiz a modificação necessária para incluí-la no tabuleiro dos níveis anteriores.

A sequência de artefatos gerados até chegar na solução proposta está exposta a seguir.

---

## Algoritmo do Cone

```Plain Text
1. Determinar o índice da coluna base
  1.1 Dividir o total de colunas da matriz (5) por 2

2. Criar a estrutura de repetição para criar a matriz cônica
  2.1 Se for a 1ª linha da matriz:
    2.1.1 Se a coluna percorrida for igual ao valor da coluna base
      2.1.1.1 Imprimir 1
    2.1.2 Senão
      2.1.2.1 Imprimir 0

  2.2 A partir da 2ª linha
    2.2.1 Se a coluna percorrida estiver no intervalo [(colBase - índiceLinha), (colBase + índiceLinha)]
      2.2.1.1 Imprimir 1
    2.2.2 Senão
      2.2.2.1 Imprimir 0
```

Evidentemente, para que a forma geométrica tenha simetria, é preciso que o número de colunas informado seja ímpar. Para simplificar, determinei 5 colunas e 3 linhas.

A primeira grande ideia foi compreender que o índice da coluna na 1ª linha (`coluna base`) equivaleria à metade do total de colunas da matriz. Isto permitiu com que a lógica da primeira validação ( `2.1`) fosse colocada em prática a fim de garantir com que o valor único da primeira linha sempre fique na posição central.

Mas acredito que a ideia determinante foi encontrar a relação entre a coluna base e o índice da linha que está sendo percorrida no momento `[(colBase - índiceLinha), (colBase + índiceLinha)]`.

Este foi o grande salto que me permitiu resolver o problema de forma mais generalista, isto é, de forma independente da quantidade de linhas e colunas, o código é capaz de gerar a forma geométrica requisitada.

Desta forma, sempre teremos os valores 1 sendo impressos dentro do intervalo que sempre inclui 1 coluna à esquerda e uma à direita à cada iteração.

---

## Exemplo do código base

```C
// Definindo a dimensão da matriz cônica
#define LINHAS 3
#define COLUNAS 5

for (l = 0; l < LINHAS; l++)
{
  for (c = 0; c < COLUNAS; c++)
  {
    if (!l)
    {
      if (c == colBase)
      {
        printf("1");
      }
      else
      {
        printf("0");
      }
    }
    else
    {
      if ((c >= (colBase - l)) && (c <= (colBase + l)))
      {
        printf("1");
      }
      else
      {
        printf("0");
      }
    }
  }
}
```

---

### Exemplo de saída do código base

```Plain Text
0 0 1 0 0

0 1 1 1 0

1 1 1 1 1
```

## Exemplo do código utilizado

```C
for (l = 0, lin = 0; l < LINHAS; l++, lin++)
{
  for (c = 0, col = 5; c < COLUNAS; c++, col++)
  {
    if (!l)
    {
      if (c == colBase)
      {
        tabuleiro[lin][col] = 1;
      } else
      {
        tabuleiro[lin][col] = 0;
      }                
    } else
    {
      if ((c >= (colBase - l)) && (c <= (colBase + l)))
      {
        tabuleiro[lin][col] = 1;
      } else
      {
        tabuleiro[lin][col] = 0;
      }                
    }            
  }
}
```

No código utilizado no programa a diferença é que o valor 0 ou 1 é atribuído à coordenada (linha, coluna) da matriz `tabuleiro`.

Na prática, fiz uso da **forma avançada** de declaração de loops, incluindo as variáveis `lin` e `col` para possibilitar o controle da linha e coluna base onde a matriz cônica será colocada.

---

### Exemplo de saída de habilidade em octaedro

0 0 1 0 0

0 1 1 1 0

0 0 1 0 0

### Exemplo de saída de habilidade em cruz

0 0 1 0 0

1 1 1 1 1

0 0 1 0 0
