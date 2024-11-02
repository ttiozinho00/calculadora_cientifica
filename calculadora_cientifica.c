#include <locale.h>  /* setlocale() */
#include <stdio.h>   /* printf() e scanf() */
#include <stdlib.h>  /* system() */
#include "funcoes.h" /* Cabe�alho das fun��es personalizadas */

int main(int argc, char const *argv[])
{
    int func;
    double x;
    int precisao;

    /* Define a localidade para exibir caracteres conforme o idioma do sistema */
    setlocale(LC_CTYPE, "");

    /* Ignorando par�metros da linha de comando para evitar warnings */
    argv = argv;
    argc = argc;
    
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

        /* Solicita o valor e a precis�o ao usu�rio */
        printf("Digite o valor a ser calculado (em graus) e a precis�o desejada: ");
        scanf("%lf %d", &x, &precisao);

        /* Executa o c�lculo com base na escolha do usu�rio */
        executar_calculo(func, x, precisao);

    } while (1);

    printf("\nObrigado por usar a calculadora! At� a pr�xima.\n");

    return 0;
}
