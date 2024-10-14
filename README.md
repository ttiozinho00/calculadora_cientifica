# Calculadora Científica

Este projeto é uma **calculadora científica** que implementa várias funções matemáticas utilizando séries de Taylor e o Método de Newton. O programa foi desenvolvido para calcular valores aproximados de funções comuns com precisão ajustável.

## Funcionalidades

A calculadora é capaz de calcular as seguintes funções:

1. **Seno (sin)**: para valores no intervalo [0, 90º] com até 5 casas decimais de precisão.
2. **Cosseno (cos)**: para valores no intervalo [0, 90º] com até 5 casas decimais de precisão.
3. **Logaritmo Natural (ln)**: para valores no intervalo [2, 100] com até 5 casas decimais de precisão.
4. **Raiz n-ésima**: para valores no intervalo [2, 5000] com até 10 casas decimais de precisão e valores inteiros de n no intervalo [2, 20].
5. **Exponencial (e^x)**: para valores no intervalo [2, 100] com até 5 casas decimais de precisão.
6. **Seno Hiperbólico (sinh)**: para valores no intervalo [0, 100] com até 3 casas decimais de precisão.

## Compilação e Execução

### Requisitos

- GCC (Compilador C)
- Sistema operacional compatível com C ANSI
- versão do mingw 4.7.2

### Compilar o programa

Para compilar o código, use o comando abaixo no terminal:

```bash
gcc -o calculadora calculadora_cientifica.c funcoes.c -Wall -pedantic -Wextra -Werror
