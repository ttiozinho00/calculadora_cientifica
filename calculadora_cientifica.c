#include <math.h>    /* M_PI e M_E */
#include <locale.h>  /* setlocale() */
#include <stdio.h>   /* printf() e scanf() */
#include <stdlib.h>  /* system() */
#include "funcoes.h" /* Cabeçalho das funções personalizadas */

int main(int argc, char const *argv[]) {
    int func;      
    double x;      
    int precisao;  

    setlocale(LC_CTYPE, ""); /* Configura a localização para suportar caracteres especiais */

    /*silenciar parametro argc e argv*/
    argv = argv;
    argc = argc;

    system("cls"); /* Limpa a tela */
    /* Instruções iniciais para o usuário */
    printf("Bem-vindo à Calculadora Científica!\n");

    /* Loop principal do programa */
    do 
    {
        exibir_menu(); /* Exibe o menu de opções */
        printf("Digite o número da função que deseja calcular: ");
        scanf("%d", &func); /* Lê a opção do usuário */

        if (func == 0) 
        {
            printf("Encerrando a calculadora...\n");
            break; /* Sai do loop se o usuário escolher 0 */
        }

        /* Solicitar o valor e a precisão ao usuário */
        printf("Digite o valor a ser calculado (em graus): ");
        scanf("%lf", &x); /* Lê o valor a ser calculado */
        printf("Digite a precisão desejada (número de casas decimais): ");
        scanf("%d", &precisao); /* Lê a precisão desejada */

        /* Processar a opção escolhida pelo usuário */
        processar_opcao(func, x, precisao); /* Chama a função para processar a opção */

    } while (1); /* Continua até que o usuário escolha sair */

    printf("\nObrigado por usar a calculadora! Até a próxima.\n"); /* Mensagem de despedida */

    return 0; /* Indica que o programa terminou com sucesso */
}
