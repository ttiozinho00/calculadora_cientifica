#include <locale.h>  /* setlocale() */
#include <stdio.h>   /* printf() e scanf() */
#include <stdlib.h>  /* system() */
#include "funcoes.h" /* Cabeçalho das funções personalizadas */

int main(int argc, char const *argv[])
{
    int func;
    double x;
    int precisao;

    /* Define a localidade para exibir caracteres conforme o idioma do sistema */
    setlocale(LC_CTYPE, "");

    /* Ignorando parâmetros da linha de comando para evitar warnings */
    argv = argv;
    argc = argc;
    
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

        /* Solicita o valor e a precisão ao usuário */
        printf("Digite o valor a ser calculado (em graus) e a precisão desejada: ");
        scanf("%lf %d", &x, &precisao);

        /* Executa o cálculo com base na escolha do usuário */
        executar_calculo(func, x, precisao);

    } while (1);

    printf("\nObrigado por usar a calculadora! Até a próxima.\n");

    return 0;
}
