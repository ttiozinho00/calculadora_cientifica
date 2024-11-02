#include <math.h>    /* M_PI e M_E */
#include <stdio.h>   /* printf() e scanf() */
#include <stdlib.h>  /* system() */
#include "funcoes.h" /* Cabeçalho das funções personalizadas */

/* Constantes para os limites de intervalo */
#define INTERVALO_SENO_COSSENO (M_PI / 2)
#define INTERVALO_EXP_LN_MAX 100
#define INTERVALO_EXP_LN_MIN 2
#define INTERVALO_RAIZ_MAX 5000
#define INTERVALO_RAIZ_MIN 2
#define INTERVALO_RAIZ_N_MIN 2
#define INTERVALO_RAIZ_N_MAX 20

/* Função para exibir o menu de opções */
void exibir_menu()
{
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

/* Função para limpar o buffer de entrada */
void limpar_buffer()
{
    int c;
    int limite = 1000;  /* Limite máximo de caracteres para evitar loop infinito */

    while ((c = getchar()) != '\n' && c != EOF && limite > 0)
    {
        limite--; /* Diminui o limite para cada caractere lido */
    }

    /* Se o limite foi excedido, pode haver um problema com o buffer */
    if (limite == 0)
    {
        printf("Aviso: O buffer de entrada pode não ter sido totalmente limpo.\n");
    }
}

/* Função auxiliar para verificar intervalo */
int verifica_intervalo(double x, double min, double max, const char* mensagem_erro)
{
    if (x < min || x > max)
    {
        printf("%s\n", mensagem_erro);
        return 0;
    }
    return 1;
}

/* Função para calcular o seno usando série de Taylor */
double seno(double x, int precisao)
{
    double termo, soma;
    int n;

    if (!verifica_intervalo(x, 0, INTERVALO_SENO_COSSENO, "Erro: O valor de x deve estar no intervalo [0, π/2] (radianos)"))
    {
        return -1;
    }

    termo = x;
    soma = x;
    n = 1;

    while (fabs(termo) > pow(10, -precisao))
    {
        termo = -termo * x * x / ((2 * n) * (2 * n + 1));
        soma += termo;
        n++;
    }

    return soma;
}

/* Função para calcular o cosseno usando série de Taylor */
double cosseno(double x, int precisao)
{
    double termo, soma;
    int n;

    if (!verifica_intervalo(x, 0, INTERVALO_SENO_COSSENO, "Erro: O valor de x deve estar no intervalo [0, π/2] (radianos)"))
    {
        return -1;
    }

    termo = 1;
    soma = 1;
    n = 1;

    while (fabs(termo) > pow(10, -precisao))
    {
        termo = -termo * x * x / ((2 * n - 1) * (2 * n));
        soma += termo;
        n++;
    }

    return soma;
}

/* Função para calcular a exponencial e^x usando série de Taylor */
double exponencial(double x, int precisao)
{
    double termo, soma;
    int n;

    if (!verifica_intervalo(x, INTERVALO_EXP_LN_MIN, INTERVALO_EXP_LN_MAX, "Erro: O valor de x deve estar no intervalo [2, 100]"))
    {
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

    if (!verifica_intervalo(x, INTERVALO_EXP_LN_MIN, INTERVALO_EXP_LN_MAX, "Erro: O valor de x deve estar no intervalo [2, 100]"))
    {
        return -1;
    }

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

    if (!verifica_intervalo(x, 0, INTERVALO_EXP_LN_MAX, "Erro: O valor de x deve estar no intervalo [0, 100]"))
    {
        return -1;
    }

    termo = x;
    soma = x;
    n = 1;

    while (fabs(termo) > pow(10, -precisao))
    {
        termo = termo * x * x / ((2 * n) * (2 * n - 1));
        soma += termo;
        n++;
    }

    return soma;
}

/* Função para calcular a raiz n-ésima de um número usando o Método de Newton */
double raiz(double A, int n, int precisao)
{
    double fx, f_prime_x,x0, x1;
    
    if (!verifica_intervalo(A, INTERVALO_RAIZ_MIN, INTERVALO_RAIZ_MAX, "Erro: O valor de x deve estar no intervalo [2, 5000]") || !verifica_intervalo(n, INTERVALO_RAIZ_N_MIN, INTERVALO_RAIZ_N_MAX, "Erro: O valor de n deve estar no intervalo [2, 20]"))
    {
        return -1;
    }

    x0 = A > 2 ? 3 : 2.1;

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

/* Função para executar o cálculo com base na opção selecionada */
void executar_calculo(int func, double x, int precisao)
{
    double radianos, resultado;
    int n;
    
    radianos = x * (M_PI / 180);

    switch (func)
    {
        case 1:
        {
            resultado = seno(radianos, precisao);
            printf("\nResultado do Seno: %.*f\n", precisao, resultado);
            break;
        }
        case 2:
        {
            resultado = cosseno(radianos, precisao);
            printf("\nResultado do Cosseno: %.*f\n", precisao, resultado);
            break;
        }
        case 3:
        {
            resultado = logaritmo_natural(radianos, precisao);
            printf("\nResultado do Logaritmo Natural: %.*f\n", precisao, resultado);
            break;
        }
        case 4:
        {
            printf("Digite o valor de n (ordem da raiz): ");
            scanf("%d", &n);
            resultado = raiz(radianos, n, precisao);
            if (resultado != -1)
            {
                printf("\nResultado da Raiz %d-ésima: %.*f\n", n, precisao, resultado);
            }
            break;
        }
        case 5:
        {
            resultado = exponencial(radianos, precisao);
            printf("\nResultado da Exponencial: %.*f\n", precisao, resultado);
            break;
        }
        case 6:
        {
            resultado = seno_hiperbolico(radianos, precisao);
            printf("\nResultado do Seno Hiperbólico: %.*f\n", precisao, resultado);
            break;
        }
        default:
        {
            printf("Opção inválida! Por favor, selecione uma opção válida.\n");
            break;
        }
    }
}
