# Desafio Nível Mestre

## Distribuição de Arquivos

- O código referente aos desafios **Novato** e **Aventureiro** podem ser encontrados no arquivo [`navios.c`](./navios.c)

- O código do desafio **Mestre** pode ser visto em [`batalhaNaval.c`](./batalhaNaval.c)

- Os códigos de teste para criação das matrizes geométricas podem ser vistos nos arquivos [`cone.c`](./cone.c), [`octaedro.c`](./octaedro.c) e [`cruz.c`](./cruz.c)

## Acerca das soluções encontradas

As soluções aqui apresentadas *provavelmente* não são as melhores possíveis. Elas refletem o grau de proficiência de um estudante iniciante no mundo da programação após a conclusão de um curso introdutório à linguagem de programação em C.

Elas, no entanto, contêm a honestidade de quem evitou o caminho mais fácil e tentou encontrar saídas utilizando o próprio raciocínio e as técnicas aprendidas ao longo deste curso e em alguns livros sobre o tema.

Confesso que inicialmente fiquei surpreso com a **aparente** simplicidade das atividades. Contudo, quando tive de parar para pensar na solução me vi obrigado a pensar de forma algorítmica, buscando resolver o problema passo a passo e nisso residiu o grande desafio. Quanto mais familiaridade obtenho com a linguagem em si percebo a necessidade de melhorar o meu processo de resolução de problemas.

Primeiro, me propus a criar um loop capaz de desenhar a forma geométrica requisitada e depois fiz a modificação necessária para incluí-la no tabuleiro dos níveis anteriores.

A sequência de artefatos gerados até chegar na solução proposta está exposta a seguir.

---

## Algoritmo do Cone

```Plain Text
1. Determinar o índice da coluna base e inicializar a soma em zero
  Coluna Base = Dividir o total de colunas da matriz por 2
  Soma = 0

2. Criar a estrutura de repetição para criar a matriz cônica
  Loop Externo - Percorre uma Linha por Repetição
    Loop Interno - Percorre uma Coluna por Repetição
      Se for a 1ª linha da matriz
        Se a coluna percorrida for igual ao valor da coluna base
          Imprimir 1
        Senão
          Imprimir 0
      Senão (a partir da 2ª linha)
        Se a coluna percorrida estiver no intervalo [(colBase - soma), (colBase + soma)]
          Imprimir 1
        Senão
          Imprimir 0
  Pula uma linha
  Incrementa a variável soma
```

Evidentemente, para que a forma geométrica tenha simetria, é preciso que o número de colunas informado seja ímpar. Para simplificar, determinei 3 linhas e 5 colunas.

A primeira grande ideia foi compreender que o índice da coluna a ser preenchida com o valor 1 na 1ª linha (a coluna base) equivaleria à **metade do total de colunas da matriz**. Isto permitiu com que a lógica da primeira validação do loop interno fosse executada garantindo a posição central do valor único da 1ª linha.

Mas acredito que a ideia determinante foi encontrar a relação entre a coluna base e a quantidade de repetições ocorridas até o momento `[(colBase - soma), (colBase + soma)]`.

Este foi o grande salto que me permitiu resolver o problema de forma mais generalista, isto é, de forma independente da quantidade de linhas e colunas, o código é capaz de gerar a forma geométrica requisitada.

Desta forma, sempre teremos os valores 1 sendo impressos dentro do intervalo que sempre inclui 1 coluna à esquerda e uma à direita à cada iteração.

O código base pode ser visto [aqui](./cone.c).

---

### Exemplo de saída do código base numa matriz 3x5

```Plain Text
0 0 1 0 0

0 1 1 1 0

1 1 1 1 1
```

## Trecho do código utilizado em [`batalhaNaval.c`](./batalhaNaval.c) para a matriz cônica

```C
soma = 0;
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
      // Determinando o intervalo dos índices das colunas para os quais os valores devem ser 1 ou 0
      if ((c >= colBase - soma) && (c <= colBase + soma))
      {
        tabuleiro[lin][col] = 1;
      }
      else
      {
        tabuleiro[lin][col] = 0;
      }
    }
  }
  soma++;
}
```

No código utilizado no programa [`batalhaNaval.c`](./batalhaNaval.c) a diferença é que o valor 0 ou 1 é atribuído à coordenada (linha, coluna) da matriz `tabuleiro` em vez de ser apenas impresso no console.

Na prática, fiz uso da **forma avançada** de declaração de loops, incluindo as variáveis `lin` e `col` para possibilitar o controle da linha e coluna base onde a matriz cônica será colocada, a fim de garantir que no final as três formas geométricas possam ocupar um determinado espaço do tabuleiro sem se sobrepor.

---

## Algoritmo do Octaedro

```Plain Text
1. Determinar o índice da coluna base e da linha central e inicializar a soma em zero
  Coluna Base = Dividir o total de colunas da matriz por 2
  Linha Central = Divisão do total de linhas da matriz por 2
  Soma = 0

2. Criar a estrutura de repetição para criar a matriz cônica
  Loop Externo - Percorre uma Linha por Repetição
    Loop Interno - Percorre uma Coluna por Repetição
      Se for a 1ª linha da matriz:
        Se a coluna percorrida for igual ao valor da coluna base
          Imprimir 1
        Senão
          Imprimir 0
      Senão (a partir da 2ª linha)
        Se a coluna percorrida estiver no intervalo [(colBase - soma), (colBase + soma)]
          Imprimir 1
        Senão
          Imprimir 0
  Pula uma linha
  Se a linha que está sendo percorrida for menor que a linha central
    Incrementa a variável soma
  Senão
    Decrementa a variável soma
```

A diferença entre o cone e o octaedro é que, no caso do último, o número de elementos com o valor 1 começa a reduzir em dois elementos, um em cada extremo, após a linha central.

Desta vez, identificamos o valor da linha central e a pusemos em uma estrutura condicional após a conclusão de um ciclo do loop interno.

A condicional verifica se o índice da linha é menor que o da linha central. Em caso positivo, o valor da variável `soma` é incrementado de forma a seguir expandindo a quantidade de valores unitários nas colunas da próxima linha que será preenchida.

Quando o valor do índice da linha for maior ou igual ao da linha central, então a variável `soma` é decrementada, começando então a redução gradual dos valores unitários preenchidos, gerando a forma de losango característica do octaedro.

O código base pode ser visto [aqui](./octaedro.c).

### Exemplo de saída de habilidade em octaedro numa matriz 3x5

```Plain Text
0 0 1 0 0

0 1 1 1 0

0 0 1 0 0
```

---

## Exemplo do código utilizado em [`batalhaNaval.c`](./batalhaNaval.c) para a matriz octaédrica

```C
soma = 0;
for (l = 0, lin = 4; l < LINHAS; l++, lin++)
{
  for (c = 0, col = 0; c < COLUNAS; c++, col++)
  {
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
      if ((c >= colBase - soma) && (c <= colBase + soma))
      {
        tabuleiro[lin][col] = 1;
      }
      else
      {
        tabuleiro[lin][col] = 0;
      }
    }
  }
  if (l < linhaCentral)
  {      
    soma++;
  } else
  {
    soma--;
  }    
}
```

---

### Exemplo de saída de habilidade em cruz

```Plain Text
0 0 1 0 0

1 1 1 1 1

0 0 1 0 0
```
