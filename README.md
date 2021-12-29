# ProjetoASA

## Projeto 1:
###### DATAS: 03/12/2021 - ~~04/01/2022~~ 11/01/2022

- [ ] Problema 1
- [ ] Problema 2
- [ ] Relatório



* **Problema 1** (Maior subsequência crescente, **Complexidade quadrática**):
>
> *TODO description*
>



* **Problema 2** (Maior subsequência crescente comum, **Complexidade cúbica**):
> 
> No problema 2, a nossa abordagem foi bastante diferente da do problema 1. Inicialmente, pensamos em fazer uma matriz do tamanho das 2 sequências do *input* e aplicar um algoritmo de determinação da maior subsequência comum (LCS), ignorando a particularidade da subsequência comum ter de ser estritamente crescente, seguindo-se um processamento linear sobre os resultados obtidos na matriz, de modo a verificar o tamanho da maior subsequência comum por ordem crescente, com um algoritmo do género do proposto para o Problema 1.
No entanto, surgiu uma ideia de implementação mais original e compacta: em vez de irmos guardando na matriz os valores da maior subsequência comum, passamos a guardar os valores da maior subsequência estritamente crescente até aos índices considerados, alterando apenas o código na condição em que se encontram 2 valores idênticos. Após a introdução de mais um ciclo *for* e uma verificação que quebra com o ciclo, podemos assumir que a complexidade algorítmica da nossa sugestão de resolução do Problema 2 é **O(n<sup>3</sup>)**, sendo que se aproxima muito de O(n<sup>2</sup>).
>

---

## Projeto 2:
###### DATAS: *TBD*
