`hyperfine --warmup 10 --min-runs 50 --export-markdown ./analysis/p1_p1_65536.md './random_k 1 1000 0.999 65536 | ./p1'`

<div align="center">

| Tamanho do input | Mean [ms] | Min [ms] | Max [ms] | 
|:---|---:|---:|---:|
| ***128*** | 1.6 ± 0.4 | 1.3 | 10.3 |
| ***256*** | 1.7 ± 0.8 | 1.4 | 23.9 |
| ***512*** | 1.8 ± 0.4 | 1.5 | 8.0 |
| ***1024*** | 2.2 ± 0.5 | 1.9 | 8.9 | 
| ***2048*** | 3.6 ± 0.5 | 3.2 | 10.5 |
| ***4096*** | 8.7 ± 0.7 | 8.0 | 15.3 |
| ***8192*** | 27.5 ± 1.6 | 26.0 | 36.8 |
| ***16384*** | 102.3 ± 1.5 | 100.0 | 108.5 |
| ***32768*** | 428.4 ± 119.5 | 393.0 | 1232.3 |
| ***65536*** | 1620 ± 0.021 | 1577 | 1663 |

</div>

<div align="center">
<img align="center"  width="500px" src="https://svgshare.com/i/dPb.svg" alt="Análise ao tempo de execução do Problema 1" />
</div>
