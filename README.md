# ProjetoASA

## Projeto 1:
###### DATAS: 03/12/2021 - ~~04/01/2022~~ 11/01/2022

- [ ] Problema 1
- [ ] Problema 2
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

> Finalmente, um último processamento linear permite determinar qual o maior elemento do `lss`, isto é, o tamanho da maior subsequência que queremos, e 
a soma dos elementos de `quant` cujos índices correspondem aos índices que contém esse tal tamanho em `lss`, isto é, a soma do número total de sequências de tamanho máximo.



* **Problema 2** (Maior subsequência crescente comum, **Complexidade cúbica**):

> No problema 2, a nossa abordagem foi bastante diferente da do problema 1. Inicialmente, pensamos em fazer uma matriz do tamanho das 2 sequências do *input* e aplicar um algoritmo de determinação da maior subsequência comum (LCS), ignorando a particularidade da subsequência comum ter de ser estritamente crescente, seguindo-se um processamento linear sobre os resultados obtidos na matriz, de modo a verificar o tamanho da maior subsequência comum por ordem crescente, com um algoritmo do género do proposto para o Problema 1.

> No entanto, surgiu uma ideia de implementação mais original e compacta: em vez de irmos guardando na matriz os valores da maior subsequência comum, passamos a guardar os valores da maior subsequência estritamente crescente até aos índices considerados, alterando apenas o código na condição em que se encontram 2 valores idênticos. Após a introdução de mais um ciclo *for* e uma verificação que quebra com o ciclo, podemos assumir que a complexidade algorítmica da nossa sugestão de resolução do Problema 2 é **O(n<sup>3</sup>)**, sendo que se aproxima muito de O(n<sup>2</sup>).
> 
> ***TODO***

---

## Projeto 2:
###### DATAS: *TBD*
