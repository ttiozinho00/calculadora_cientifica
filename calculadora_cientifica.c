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

    /* Instruções iniciais para o usuário */
    printf("Bem-vindo à Calculadora Científica!\n");

    /* Loop principal do programa */
    do
    {
        exibir_menu();
        printf("Digite o número da função que deseja calcular: ");
        scanf("%d", &func);

        if (func == 0)
        {
            printf("Encerrando a calculadora...\n");
            break;
        }

        /* Solicitar o valor e a precisão ao usuário */
        printf("Digite o valor a ser calculado e a precisão desejada: ");
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
                /* Lendo valor de n para a raiz n-ésima */
                printf("Digite o valor de n (ordem da raiz): ");
                scanf("%d", &n);
                printf("\nResultado da Raiz %d-ésima: %.10f\n", n, raiz(x, n, precisao));
                break;
            case 5:
                printf("\nResultado da Exponencial: %.5f\n", exponencial(x, precisao));
                break;
            case 6:
                printf("\nResultado do Seno Hiperbólico: %.3f\n", seno_hiperbolico(x, precisao));
                break;
            default:
                printf("Opção inválida! Por favor, selecione uma opção válida.\n");
                break;
        }

        /* Perguntar se o usuário quer continuar */
        printf("\nDeseja calcular outra função? (s/n): ");
        scanf(" %c", &escolha); /* O espaço antes do %c ignora o enter deixado no buffer */

    } while (escolha == 's' || escolha == 'S');

    printf("\nObrigado por usar a calculadora! Até a próxima.\n");

    return 0;
}
