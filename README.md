# ProjetoASA

## Projeto 1:
###### DATAS: 03/12/2021 - ~~04/01/2022~~ 11/01/2022

- [ ] Problema 1
- [X] Problema 2
- [ ] Relatório



* **Problema 1** (Maior subsequência crescente, **Complexidade quadrática**):

> No problema 1, a nossa primeira ideia foi implementar uma função recursiva, que fosse iterando pela sequência, do último elemento para o primeiro, com diversos parâmetros que permitissem a continuação do estado, caso se encontrasse um elemento menor do que o considerado ou a iniciação de um novo, caso contrário. No entanto, nem foi preciso analisar o tempo de execução para rapidamente percebermos que era uma má forma de solucionar o problema.

> Optámos, então, por uma solução dinâmica, que fosse armazenando valores para evitar o uso de recursões desnecessárias. Assim, a nossa implementação itera pelos elementos da sequência do início para o fim e, para cada um deles, itera pelos elementos anteriores, também do início para o fim, sem exceções ou saídas dos ciclos, o que nos garante que estamos na presença de um Limite Assimptótico Apertado de grandeza **n<sup>2</sup>**.
O que permite que esta solução funcione para o problema considerado é a existência, em memória, de 2 vetores da mesma dimensão da sequência: o `lss` (*longest subsequence size*) e o `quant` (*quantity*). O primeiro, como o nome indica, mantém o tamanho da maior subsequência estritamente crescente que contém o elemento do índice considerado, e o segundo regista a quantidade de sequências desse mesmo tamanho que contêm o elemento, tal como no seguinte exemplo:

<div align="center">

| ***seq*** | **1** | **2** | **6** | **3** | **7** |
|:---------:|:-----:|:-----:|:-----:|:-----:|:-----:|
|   *lss*   |   1   |   2   |   3   |   3   |   4   |
|  *quant*  |   1   |   1   |   1   |   1   |   2   |

</div>

> Por cada iteração pelos elementos da sequência, é atualizada uma variável que contém o maior elemento do `lss`, isto é, o tamanho da maior subsequência que queremos, caso necessário, e é também atualizado o valor da soma dos elementos de `quant` cujos índices correspondem aos índices que contém esse tal tamanho em `lss`, isto é, a soma do número total de sequências de tamanho máximo.
Finalmente, é devolvido o output desejado nas especificações do problema.



* **Problema 2** (Maior subsequência crescente comum, **Complexidade quadrática**):

> No problema 2, a nossa abordagem foi bastante diferente da do problema 1. Inicialmente, pensamos em fazer uma matriz do tamanho das 2 sequências do *input* e aplicar um algoritmo de determinação da maior subsequência comum (LCS), ignorando a particularidade da subsequência comum ter de ser estritamente crescente, seguindo-se um processamento linear sobre os resultados obtidos na matriz, de modo a verificar o tamanho da maior subsequência comum por ordem crescente, com um algoritmo do género do proposto para o Problema 1. Posteriormente, surgiu uma outra ideia mais original e compacta: passarmos a guardar, nos índices da matriz, os valores da maior subsequência estritamente crescente até aos índices considerados. No entanto, obtivemos diversos problemas de memória e tempo de execução, nas diversas implementações que testávamos. Assim, fomos obrigados a desistir da nossa ideia e a pensar, novamente, fora da caixa.

> Chegamos, então, a uma solução diferente, mas que não deixava de ser dinâmica. Por cada elemento da `seq1`, iterávamos também por todos os elementos da `seq2` do início para o fim, sem exceções ou saídas dos ciclos, o que nos garante que estamos na presença de um Limite Assimptótico Apertado de grandeza **n<sup>2</sup>**, assim como no problema 1. Foi utilizada uma array da mesma dimensão da `seq2` que, para cada índice, guardasse o tamanho da maior subsequência estritamente crescente comum entre as 2 sequências que acabasse nesse elemento da `seq2`. Com resurso a uma variável local, por cada elemento percorrido da `seq2`:
> - se for menor que o da `seq1`, a variável assume o valor do índice da `lcis` considerado, caso seja maior do que se encontra lá;
> - se for igual ao da `seq1`, o índice da `lcis` toma o valor da variável incrementado numa unidade, caso seja maior do que se encontra lá.

> Para o seguinte exemplo, a array `lcis`, após cada iteração pelos elementos da `seq1`, é a seguinte:

<div align="center">

| ***seq1*** | **1** | **2** | **6** | **3** | **7** |
|:----------:|:-----:|:-----:|:-----:|:-----:|:-----:|
| ***seq2*** | **1** | **2** | **4** | **7** | **3** |

|   *lcis*   |   1   |   0   |   0   |   0   |   0   |
|:----------:|:-----:|:-----:|:-----:|:-----:|:-----:|
|   *lcis*   |   1   |   2   |   0   |   0   |   0   |
|   *lcis*   |   1   |   2   |   0   |   0   |   0   |
|   *lcis*   |   1   |   2   |   0   |   0   |   3   |
| ***lcis*** | **1** | **2** | **0** | **3** | **3** |

</div>

> Notámos que poderíamos tornar o algoritmo ainda mais eficiente, pois será previsível, à partida e antes da execução do algoritmo, que haverá índices da `lcis` que irão conter `0` (os índices dos elementos da `seq2` que não estão presentes na `seq1`). Esta solução foi, então, posteriormente otimizada com recurso a um pré-processamento que, na leitura da 2ª linha para o vetor `seq2`, apenas escrevesse os elementos que também estivessem presentes na `seq1`. Com recurso a um mapa desses elementos, fizemos com que a procura fosse O(1), na maioria dos casos. Por fim, é feita uma última procura linear pelo elemento máximo da `lcis`, o resultado que queremos.

---

## Projeto 2:
###### DATAS: *TBD*
