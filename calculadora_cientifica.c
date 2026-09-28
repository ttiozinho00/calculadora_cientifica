#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main(int argc, char const *argv[])
{
    int func;
    double x;
    int n = 0;
    int precisao;

    setlocale(LC_CTYPE, "");

    /* Supressão de avisos de variáveis não utilizadas */
    (void)argc;
    (void)argv;
    
    printf("Bem-vindo à Calculadora Científica!\n");

    do
    {
        exibir_menu();
        printf("Digite o número da função que deseja calcular: ");
        
        /* Validação da entrada do utilizador para evitar ciclos infinitos */
        if (scanf("%d", &func) != 1)
        {
            limpar_buffer();
            printf("Erro: Entrada inválida. Por favor, digite um número inteiro.\n");
            continue;
        }

        if (func == 0)
        {
            printf("Encerrando a calculadora...\n");
            break;
        }

        if (func < 1 || func > 6)
        {
            printf("Opção inválida! Por favor, selecione uma opção válida.\n");
            continue;
        }

        /* Lógica de input contextual dependendo da função selecionada */
        if (func == 1 || func == 2)
        {
            printf("Digite o valor do ângulo (em graus): ");
            scanf("%lf", &x);
        }
        else
        {
            if (func == 4)
            {
                printf("Digite o valor de x (base): ");
                scanf("%lf", &x);
                printf("Digite o valor de n (índice da raiz): ");
                scanf("%d", &n);
            }
            else
            {
                printf("Digite o valor de x: ");
                scanf("%lf", &x);
            }
        }

        printf("Digite a precisão desejada (número de casas decimais): ");
        scanf("%d", &precisao);

        executar_calculo(func, x, n, precisao);

    } while (1);

    printf("\nObrigado por usar a calculadora! Até à próxima.\n");
    return 0;
}
