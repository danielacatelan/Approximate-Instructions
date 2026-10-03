# Aplicações

Esta pasta reúne aplicações de teste desenvolvidas para o projeto **RISC-V Approximate Instructions**.

## Objetivo

Concentrar os programas em C utilizados nos experimentos com instruções mistas, permitindo avaliar o comportamento das 
instruções aproximadas em diferentes cenários de uso.

## Conteúdo

Os testes incluem variações de operações aritméticas (soma e subtração) e suas versões com suporte a aproximação:

- `add` / `add_SP` — soma vetorial EXATA com 1000 dados aleatórios de entrada / versão sem o printf
- `addx` / `addx_SP` — soma vetorial APROXIMADA com 1000 dados aleatórios de entrada / versão sem o printf
- `m_addx` / `m_addx_SP` — soma vetorial MISTA com 1000 dados aleatórios de entrada / versão sem o printf
- `addx_m` / `addx_m_SP` — soma vetorial MISTA com 1000 dados aleatórios de entrada / versão sem o printf
- `sub` / `sub_SP` — subtração vetorial EXATA com 1000 dados aleatórios de entrada / versão sem o printf
- `subx` / `subx_SP` — subtração vetorial APROXIMADA com 1000 dados aleatórios de entrada / versão sem o printf
- `m_subx` / `m_subx_SP` — subtração vetorial MISTA com 1000 dados aleatórios de entrada / versão sem o printf
- `subx_m` / `subx_m_SP` — subtração vetorial MISTA com 1000 dados aleatórios de entrada / versão sem o printf
- Bank_variante.c - aplicações do Algoritmo do Banqueiro, com todas as variantes utilizadas
- Bin_variante.c - aplicações do Binomial, com todas as variantes utilizadas
- Conv_variante.c - aplicações da Convolução, com todas as variantes utilizadas
- Hada_variante.c - aplicações da Transformada Rápida de Walsh--Hadamard, com todas as variantes utilizadas

## Estrutura

Cada arquivo `.c` possui seu correspondente compilado e a saída gerada pela execução no simulador, armazenada em arquivos `.txt`.

## Como executar

Os testes são executados através do script `script_instrucao.sh`, que realiza as etapas de compilação, simulação com Spike e análise com PROF5.

```bash
./script_instrucao.sh

