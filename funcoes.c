#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

#define INTERVALO_COSSENO M_PI
#define INTERVALO_EXP_LN_MAX 100
#define INTERVALO_EXP_LN_MIN 2
#define INTERVALO_RAIZ_MAX 5000
#define INTERVALO_RAIZ_MIN 2
#define INTERVALO_RAIZ_N_MAX 20
#define INTERVALO_RAIZ_N_MIN 2
#define INTERVALO_SENO (M_PI / 2)
#define INTERVALO_SINH_MAX 20 /* Limite reduzido para evitar overflow com fatoriais grandes */

void exibir_menu()
{
    printf("\n--- MENU DA CALCULADORA CIENTÍFICA ---\n");
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

void limpar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

int verifica_intervalo(double x, double min, double max, char* mensagem_erro)
{
    if (x < min || x > max)
    {
        printf("%s\n", mensagem_erro);
        return 0;
    }
    return 1;
}

double seno(double x, int precisao)
{
    double termo, soma;
    int n;
    double tolerancia = pow(10, -precisao);

    if (!verifica_intervalo(x, 0, INTERVALO_SENO, "Erro: O valor de x deve estar no intervalo [0, π/2] (radianos)"))
    {
        return -1;
    }

    termo = x;
    soma = x;
    n = 1;

    while (fabs(termo) > tolerancia)
    {
        termo = -termo * x * x / ((2 * n) * (2 * n + 1));
        soma += termo;
        n++;
    }
    return soma;
}

double cosseno(double x, int precisao)
{
    double termo, soma;
    int n;
    double tolerancia = pow(10, -precisao);

    if (!verifica_intervalo(x, 0, INTERVALO_COSSENO, "Erro: O valor de x deve estar no intervalo [0, π] (radianos)"))
    {
        return -1;
    }

    termo = 1;
    soma = 1;
    n = 1;

    while (fabs(termo) > tolerancia)
    {
        termo = -termo * x * x / ((2 * n - 1) * (2 * n));
        soma += termo;
        n++;
    }
    return soma;
}

double exponencial(double x, int precisao)
{
    double termo, soma;
    int n;
    double tolerancia = pow(10, -precisao);

    if (!verifica_intervalo(x, INTERVALO_EXP_LN_MIN, INTERVALO_EXP_LN_MAX, "Erro: O valor de x deve estar no intervalo [2, 100]"))
    {
        return -1;
    }

    termo = 1;
    soma = 1;
    n = 1;

    while (fabs(termo) > tolerancia)
    {
        termo *= x / n;
        soma += termo;
        n++;
    }
    return soma;
}

double logaritmo_natural(double x, int precisao)
{
    double y, termo, soma;
    int n;
    double tolerancia = pow(10, -precisao);

    if (!verifica_intervalo(x, INTERVALO_EXP_LN_MIN, INTERVALO_EXP_LN_MAX, "Erro: O valor de x deve estar no intervalo [2, 100]"))
    {
        return -1;
    }

    y = (x - 1) / (x + 1);
    termo = y;
    soma = 2 * termo;
    n = 1;

    while (fabs(termo) > tolerancia)
    {
        n += 2;
        termo *= y * y;
        soma += 2 * termo / n;
    }
    return soma;
}

double raiz(int n, double x, int precisao)
{
    double resultado, erro;
    double tolerancia = pow(10, -precisao);
    
    if (!verifica_intervalo(n, INTERVALO_RAIZ_N_MIN, INTERVALO_RAIZ_N_MAX, "Erro: n deve estar entre 2 e 20") || 
        !verifica_intervalo(x, INTERVALO_RAIZ_MIN, INTERVALO_RAIZ_MAX, "Erro: x deve estar entre 2 e 5000"))
    {
        return -1;
    }

    resultado = x / 2.0;
    erro = resultado;
    
    while (fabs(resultado - erro) > tolerancia || erro == resultado) 
    {
        erro = resultado;
        resultado = ((n - 1) * resultado + x / pow(erro, n - 1)) / n;
    }
    return resultado;
}

double seno_hiperbolico(double x, int precisao)
{
    double termo, soma;
    int n;
    double tolerancia = pow(10, -precisao);

    if (!verifica_intervalo(x, 0, INTERVALO_SINH_MAX, "Erro: O valor de x deve estar no intervalo [0, 20] para evitar overflow"))
    {
        return -1;
    }

    termo = x;
    soma = x;
    n = 1;

    while (fabs(termo) > tolerancia)
    {
        termo = termo * x * x / ((2 * n) * (2 * n + 1));
        soma += termo;
        n++;
    }
    return soma;
}

void executar_calculo(int func, double x, int n_raiz, int precisao)
{
    double resultado;
    double radianos = x * (M_PI / 180); 
    
    switch (func)
    {
        case 1:
        {
            resultado = seno(radianos, precisao);
            if (resultado != -1)
            {
                printf("\nResultado do Seno: %.*f\n", precisao, resultado);
            }
            break;
        }
        case 2:
        {
            resultado = cosseno(radianos, precisao);
            if (resultado != -1)
            {
                printf("\nResultado do Cosseno: %.*f\n", precisao, resultado);
            }
            break;
        }
        case 3:
        {
            resultado = logaritmo_natural(x, precisao);
            if (resultado != -1)
            {
                printf("\nResultado do Logaritmo Natural: %.*f\n", precisao, resultado);
            }
            break;
        }
        case 4:
        {
            resultado = raiz(n_raiz, x, precisao);
            if (resultado != -1)
            {
                printf("\nResultado da Raiz %d-ésima: %.*f\n", n_raiz, precisao, resultado);
            }
            break;
        }
        case 5:
        {
            resultado = exponencial(x, precisao);
            if (resultado != -1)
            {
                printf("\nResultado da Exponencial: %.*f\n", precisao, resultado);
            }
            break;
        }
        case 6:
        {
            resultado = seno_hiperbolico(x, precisao);
            if (resultado != -1)
            {
                printf("\nResultado do Seno Hiperbólico: %.*f\n", precisao, resultado);
            }
            break;
        }
    }
}
