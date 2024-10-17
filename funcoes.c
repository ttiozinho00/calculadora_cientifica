#include <math.h>    /* M_PI e M_E */
#include <stdio.h>   /* printf() e scanf() */
#include <stdlib.h>  /* system() */
#include "funcoes.h" /* Cabeçalho das funções personalizadas */

/* Função para exibir o menu de opções */
void exibir_menu()
{
    system("cls");
    printf("\n--- Menu da Calculadora Científica ---\n");
    printf("Escolha uma função para calcular:\n");
    printf("1: Seno (sin)\n");
    printf("2: Cosseno (cos)\n");
    printf("3: Logaritmo Natural (ln)\n");
    printf("4: Raiz n-ésima\n");
    printf("5: Exponencial (e^x)\n");
    printf("6: Seno hiperbólico (sinh)\n");
    printf("0: Sair\n");
    printf("-------------------------------------\n");
}

/* Função para calcular o seno usando série de Taylor */
double seno(double x, int precisao)
{
    double termo, soma;
    int n;

    if (x < 0 || x > (M_PI / 2))  /* Intervalo alterado para aceitar valores em radianos (0 a pi/2) */
    {
        printf("Erro: O valor de x deve estar no intervalo [0, p/2] (radianos)\n");
        return -1;
    }

    termo = x;
    soma = x;
    n = 1;

    while (fabs(termo) > pow(10, -precisao))
    {
        n++;
        termo = -termo * x * x / ((2 * n - 2) * (2 * n - 1));
        soma += termo;
    }

    return soma;
}

/* Função para calcular o cosseno usando série de Taylor */
double cosseno(double x, int precisao)
{
    double termo, soma;
    int n;

    if (x < 0 || x > (M_PI / 2))  /* Ajustado para aceitar valores em radianos de 0 a p/2 */
    {
        printf("Erro: O valor de x deve estar no intervalo [0, p/2] (radianos)\n");
        return -1;
    }

    termo = 1;
    soma = 1;
    n = 0;

    while (fabs(termo) > pow(10, -precisao))
    {
        n++;
        termo = -termo * x * x / ((2 * n - 1) * (2 * n));
        soma += termo;
    }

    return soma;
}

/* Função para calcular a exponencial e^x usando série de Taylor */
double exponencial(double x, int precisao)
{
    double termo, soma;
    int n;

    if (x < 2 || x > 100)
    {
        printf("Erro: O valor de x deve estar no intervalo [2, 100]\n");
        return -1;
    }

    termo = 1;
    soma = 1;
    n = 1;

    while (fabs(termo) > pow(10, -precisao))
    {
        termo *= x / n;
        soma += termo;
        n++;
    }

    return soma;
}

/* Função para calcular o logaritmo natural usando transformação e série */
double logaritmo_natural(double x, int precisao)
{
    double y;
    double termo, soma, temp;
    int n;

    if (x < 2 || x > 100)
    {
        printf("Erro: O valor de x deve estar no intervalo [2, 100]\n");
        return -1;
    }

    /* Transformação para usar o intervalo entre -1 e 1 */
    y = (x - 1) / (x + 1);
    termo = y;
    soma = 2 * termo;
    temp = termo * termo;
    n = 1;

    while (fabs(termo) > pow(10, -precisao))
    {
        termo *= temp;
        soma += (2.0 / (2 * n + 1)) * termo;
        n++;
    }

    return soma;
}

/* Função para calcular o seno hiperbólico usando série de Taylor */
double seno_hiperbolico(double x, int precisao)
{
    double termo, soma;
    int n;

    if (x < 0 || x > 100)
    {
        printf("Erro: O valor de x deve estar no intervalo [0, 100]\n");
        return -1;
    }

    termo = x;
    soma = x;
    n = 1;

    while (fabs(termo) > pow(10, -precisao))
    {
        n++;
        termo = termo * x * x / ((2 * n - 1) * (2 * n - 2));
        soma += termo;
    }

    return soma;
}

/* Função para calcular a raiz n-ésima de um número usando o Método de Newton */
double raiz(double A, int n, int precisao)
{
    double f_prime_x;
    double fx;
    double x0;
    double x1;

    if (A < 2 || A > 5000 || n < 2 || n > 20)
    {
        printf("Erro: O valor de x deve estar no intervalo [2, 5000] e n no intervalo [2, 20]\n");
        return -1;
    }

    /* Definindo o chute inicial */
    x0 = (A > 2) ? 3 : 2.1;

    while (1)
    {
        fx = pow(x0, n) - A;
        f_prime_x = n * pow(x0, n - 1);
        x1 = x0 - fx / f_prime_x;

        if (fabs(pow(x1, n) - A) < pow(10, -precisao))
        {
            break;
        }

        x0 = x1;
    }

    return x1;
}