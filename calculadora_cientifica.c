#include <math.h>    /* M_PI e M_E */
#include <locale.h>  /* setlocale() */
#include <stdio.h>   /* printf() e scanf() */
#include <stdlib.h>  /* system() */
#include "funcoes.h" /* Cabe�alho das fun��es personalizadas */

int main(int argc, char const *argv[]) {
    int func;      
    double x;      
    int precisao;  

    setlocale(LC_CTYPE, ""); /* Configura a localiza��o para suportar caracteres especiais */

    /*silenciar parametro argc e argv*/
    argv = argv;
    argc = argc;

    system("cls"); /* Limpa a tela */
    /* Instru��es iniciais para o usu�rio */
    printf("Bem-vindo � Calculadora Cient�fica!\n");

    /* Loop principal do programa */
    do 
    {
        exibir_menu(); /* Exibe o menu de op��es */
        printf("Digite o n�mero da fun��o que deseja calcular: ");
        scanf("%d", &func); /* L� a op��o do usu�rio */

        if (func == 0) 
        {
            printf("Encerrando a calculadora...\n");
            break; /* Sai do loop se o usu�rio escolher 0 */
        }

        /* Solicitar o valor e a precis�o ao usu�rio */
        printf("Digite o valor a ser calculado (em graus): ");
        scanf("%lf", &x); /* L� o valor a ser calculado */
        printf("Digite a precis�o desejada (n�mero de casas decimais): ");
        scanf("%d", &precisao); /* L� a precis�o desejada */

        /* Processar a op��o escolhida pelo usu�rio */
        processar_opcao(func, x, precisao); /* Chama a fun��o para processar a op��o */

    } while (1); /* Continua at� que o usu�rio escolha sair */

    printf("\nObrigado por usar a calculadora! At� a pr�xima.\n"); /* Mensagem de despedida */

    return 0; /* Indica que o programa terminou com sucesso */
}
