#include <locale.h>  /* setlocale() */
#include <stdio.h>   /* printf() e scanf() */
#include "funcoes.h" /* Cabe�alho das fun��es personalizadas */

int main(int argc, char const *argv[])
{
    int func;
    double x;
    int precisao, n;

    setlocale(LC_CTYPE, "");

    /* Instru��es iniciais para o usu�rio */
    printf("Bem-vindo � Calculadora Cient�fica!\n");

    /* Loop principal do programa */
    do
    {
        exibir_menu();
        printf("Digite o n�mero da fun��o que deseja calcular: ");
        scanf("%d", &func);

        if (func == 0)
        {
            printf("Encerrando a calculadora...\n");
            break;
        }

        /* Solicitar o valor e a precis�o ao usu�rio */
        printf("Digite o valor a ser calculado (em graus) e a precis�o desejada: ");
        scanf("%lf %d", &x, &precisao);
        
        /* Converter o valor de graus para radianos */
        double radianos = x * (M_PI / 180);

        switch (func)
        {
            case 1:
                printf("\nResultado do Seno: %.*f\n", precisao, seno(radianos, precisao));
                break;
            case 2:
                printf("\nResultado do Cosseno: %.*f\n", precisao, cosseno(radianos, precisao));
                break;
            case 3:
                printf("Resultado do Logaritmo Natural: %.*f\n", precisao, logaritmo_natural(radianos, precisao));
                break;
            case 4:
                /* Lendo valor de n para a raiz n-�sima */
                printf("Digite o valor de n (ordem da raiz): ");
                scanf("%d", &n);
                if (raiz(radianos, n, precisao) != -1)
                {
                    printf("\nResultado da Raiz %d-�sima: %.*f\n", n, precisao, raiz(radianos, n, precisao));
                }
                break;
            case 5:
                printf("\nResultado da Exponencial: %.*f\n", precisao, exponencial(radianos, precisao));
                break;
            case 6:
                printf("\nResultado do Seno Hiperb�lico: %.*f\n", precisao, seno_hiperbolico(radianos, precisao));
                break;
            default:
                printf("Op��o inv�lida! Por favor, selecione uma op��o v�lida.\n");
                break;
        }

    } while (1);

    printf("\nObrigado por usar a calculadora! At� a pr�xima.\n");

    return 0;
}
