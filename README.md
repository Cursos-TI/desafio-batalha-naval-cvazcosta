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
  Coluna Central = Total de colunas da matriz ÷ 2
  Soma = 0

2. Criar a estrutura de repetição para criar a matriz cônica
  Loop Externo - Percorre uma Linha por Repetição
    Loop Interno - Percorre uma Coluna por Repetição
        Se a coluna percorrida estiver no intervalo [(colunaCentral - soma), (colunaCentral + soma)]
          Imprimir 1
        Senão
          Imprimir 0
  Pula uma linha
  Incrementa a variável soma
```

Evidentemente, para que a forma geométrica tenha simetria, é preciso que (i) o número de colunas seja ímpar e que (ii) a cada linha incluída duas colunas devem ser adicionadas em relação a linha anterior. Para simplificar, determinei 3 linhas e 5 colunas.

A primeira grande ideia foi compreender que o índice da coluna a ser preenchida com o valor 1 na 1ª linha, a coluna central, equivaleria à **metade do total de colunas da matriz**. Chamamos este valor de `colunaCentral`.

Mas acredito que a ideia determinante foi encontrar uma relação entre a coluna base e a quantidade de repetições ocorridas, valor que foi armazenado na variável `soma`, na determinação do intervalo dos índices da coluna a serem preenchidos.

A relação é como segue: `[(colunaCentral - soma), (colunaCentral + soma)]`.

Na 1ª iteração ocorre o preenchimento da 1ª linha da matriz. Essa é a linha que tem apenas a coluna base preenchida.

O valor 1 será atribuído à coordenada apenas se a seguinte condição for verdadeira: `(c >= colunaCentral - soma) && (c <= (colunaCentral + soma))`. Supondo `colunaCentral = 2` isto significa que na 1ª iteração só deve-se imprimir 1 quando a coluna `c` que estiver sendo percorrida no loop estiver num intervalo fechado [2, 2]. Na prática, apenas a coluna central será preenchida.

Na 2ª iteração, o valor da variável `soma` é incrementado e temos a expansão do intervalo que irá admitir os valores unitários na lógica de 1 coluna à esquerda e 1 coluna à direita da coluna base. Assim o intervalo torna-se [1, 3] indicando que apenas as colunas com índices entre 1 e 3 terão 1 em suas coordenadas. O mesmo processo se dará para as linhas subsequentes.

Desta forma, garantimos que a forma cônica possa ser desenhada, considerando-se que foi definida uma quantidade proporcional de linhas e colunas no início do programa.

O código base pode ser visto [aqui](./cone.c).

---

### Exemplo de saída de um cone numa matriz 3x5

```Plain Text
0 0 1 0 0

0 1 1 1 0

1 1 1 1 1
```

### Trecho do código utilizado em [`batalhaNaval.c`](./batalhaNaval.c) para o cone

```C
soma = 0;
for (l = 0, lin = 0; l < LINHAS; l++, lin++)
{
  for (c = 0, col = 5; c < COLUNAS; c++, col++)
  {
    // Determinando o intervalo dos índices das colunas para os quais os valores devem ser 1 ou 0
    if ((c >= colunaCentral - soma) && (c <= colunaCentral + soma))
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
```

No código utilizado no programa [`batalhaNaval.c`](./batalhaNaval.c) a diferença é que o valor 0 ou 1 é atribuído à coordenada (linha, coluna) da matriz `tabuleiro` em vez de ser apenas impresso no console.

Na prática, fiz uso da **forma avançada** de declaração de loops, incluindo as variáveis `lin` e `col` para possibilitar o controle da linha e coluna base onde a matriz cônica será colocada, a fim de garantir que no final as três formas geométricas possam ocupar um determinado espaço do tabuleiro sem se sobrepor.

---

## Algoritmo do Octaedro

```Plain Text
1. Determinar o índice da coluna base e da linha central e inicializar a soma em zero
  Coluna Central = Total de colunas da matriz ÷ 2
  Linha Central = Total de linhas da matriz ÷ 2
  Soma = 0

2. Criar a estrutura de repetição para criar a matriz cônica
  Loop Externo - Percorre uma Linha por Repetição
    Loop Interno - Percorre uma Coluna por Repetição
      Se a coluna percorrida estiver no intervalo [(colunaCentral - soma), (colunaCentral + soma)]
        Imprimir 1
      Senão
        Imprimir 0
    Pula uma linha
    Se a linha que está sendo percorrida for menor que a linha central
      Incrementa a variável soma
    Senão
      Decrementa a variável soma
```

A diferença entre o cone e o octaedro é que, no  último, o número de elementos com o valor 1 começa a reduzir em dois elementos, um em cada índice na extremidade, **após a linha central**.

Desta vez, identificamos o valor da linha central dividindo o total de linhas por 2 e atribuímos à variável `linhaCentral`. Em seguida a pusemos em uma estrutura condicional após cada repetição de preenchimento de todas as colunas de uma linha.

A condicional verifica se o índice da linha que foi percorrida é menor que o da linha central. Em caso positivo, o valor da variável `soma` é incrementado de forma a seguir expandindo a quantidade de valores unitários nas colunas da próxima linha que será preenchida, da mesma forma que no cone.

Quando os valores dos índices da linha percorrida passam a ser igual ou maiores ao da linha central, então a variável `soma` é decrementada. Inicia-se então a redução gradual dos valores unitários preenchidos, gerando a forma de losango característica do octaedro.

O código base pode ser visto [aqui](./octaedro.c).

---

### Exemplo de saída de um octaedro numa matriz 3x5

```Plain Text
0 0 1 0 0

0 1 1 1 0

0 0 1 0 0
```

---

### Trecho do código utilizado em [`batalhaNaval.c`](./batalhaNaval.c) para o octaedro

```C
soma = 0;
for (l = 0, lin = 4; l < LINHAS; l++, lin++)
{
  for (c = 0, col = 0; c < COLUNAS; c++, col++)
  {
    if ((c >= colunaCentral - soma) && (c <= colunaCentral + soma))
    {
      tabuleiro[lin][col] = 1;
    }
    else
    {
      tabuleiro[lin][col] = 0;
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

## Algoritmo da cruz

```Plain Text
1. Determinar o índice da coluna base e da linha central e inicializar a soma em zero
  Coluna Central = Dividir o total de colunas da matriz por 2
  Linha Central = Divisão do total de linhas da matriz por 2

2. Criar a estrutura de repetição para criar a matriz cônica
  Loop Externo - Percorre uma Linha por Repetição
    Se a linha que está sendo percorrida for igual a linha central
      Soma = colunaCentral
    Senão
      Soma = 0
    Loop Interno - Percorre uma Coluna por Repetição
      Se a coluna percorrida estiver no intervalo [(colunaCentral - soma), (colunaCentral + soma)]
        Imprimir 1
      Senão
        Imprimir 0
    Fim Loop Interno
    Pula uma linha
    Se a linha que está sendo percorrida for menor que a linha central
      Incrementa a variável soma
    Senão
      Decrementa a variável soma
  Fim Loop Externo
```

Assim como no octaedro seria necessário usar os valores da coluna e da linha central.

A diferença é que seria necessário fazer uma validação logo no início do loop de cada linha. Se a linha a ser percorrida fosse a linha central, o valor da variável `soma` seria igual ao da coluna central.

Isso serve para garantir que o intervalo das colunas a serem preenchidas na **linha central** com o valor 1 na validação do loop interno seja o máximo possível `[0, n]`, sendo `n` o valor do maior índice da coluna da matriz.

Para qualquer outra linha, apenas a coluna com índice igual ao da coluna base será preenchido com 1, formando a imagem da cruz.

---

### Exemplo de saída de uma cruz numa matriz 3x5

```Plain Text
0 0 1 0 0

1 1 1 1 1

0 0 1 0 0
```

---

### Trecho do código utilizado em [`batalhaNaval.c`](./batalhaNaval.c) para a cruz

```C
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
```
