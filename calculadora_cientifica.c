/*gcc -o calculadora calculadora_cientifica.c -Wall -pedantic -Wextra -Werror */

#include <stdio.h>   /* printf() e scanf() */
#include <locale.h>  /* setlocale() */
#include "funcoes.h"


int main(int argc, char const *argv[])
{
    int func;
    double x;
    int precisao, n;
    char escolha;
    
    argc = argc;
    argv = argv;    

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
        printf("Digite o valor a ser calculado e a precis�o desejada: ");
        scanf("%lf %d", &x, &precisao);

        switch (func)
        {
            case 1:
                printf("\nResultado do Seno: %.5f\n", seno(x, precisao));
                break;
            case 2:
                printf("\nResultado do Cosseno: %.5f\n", cosseno(x, precisao));
                break;
            case 3:
                printf("Resultado do Logaritmo Natural: %.5f\n", logaritmo_natural(x, precisao));
                break;
            case 4:
                /* Lendo valor de n para a raiz n-�sima */
                printf("Digite o valor de n (ordem da raiz): ");
                scanf("%d", &n);
                printf("\nResultado da Raiz %d-�sima: %.10f\n", n, raiz(x, n, precisao));
                break;
            case 5:
                printf("\nResultado da Exponencial: %.5f\n", exponencial(x, precisao));
                break;
            case 6:
                printf("\nResultado do Seno Hiperb�lico: %.3f\n", seno_hiperbolico(x, precisao));
                break;
            default:
                printf("Op��o inv�lida! Por favor, selecione uma op��o v�lida.\n");
                break;
        }

        /* Perguntar se o usu�rio quer continuar */
        printf("\nDeseja calcular outra fun��o? (s/n): ");
        scanf(" %c", &escolha); /* O espa�o antes do %c ignora o enter deixado no buffer */

    } while (escolha == 's' || escolha == 'S');

    printf("\nObrigado por usar a calculadora! At� a pr�xima.\n");

    return 0;
}
