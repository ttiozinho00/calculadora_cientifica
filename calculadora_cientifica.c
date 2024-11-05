/* 
   Programa: Calculadora Científica com Funções Avançadas
   Descrição: Este programa implementa uma calculadora científica que realiza cálculos avançados, incluindo seno,
              cosseno, logaritmo natural, exponencial, seno hiperbólico e raízes n-ésimas, utilizando métodos de
              séries de Taylor e o Método de Newton para precisão. O programa permite ao usuário especificar um valor 
              para o cálculo e a precisão desejada (número de casas decimais), além de verificar se os valores estão
              dentro dos intervalos válidos para cada operação.

   Funcionalidades:
   - Exibe um menu de opções, permitindo que o usuário selecione entre seis operações matemáticas:
     (1) Seno (2) Cosseno (3) Logaritmo Natural (4) Raiz n-ésima (5) Exponencial (6) Seno hiperbólico
   - Solicita ao usuário que informe o valor a ser calculado (em graus, exceto onde especificado) e o número
     de casas decimais de precisão
   - Calcula e exibe o resultado com a precisão especificada pelo usuário
   - Verifica e garante que os valores de entrada estejam dentro dos intervalos apropriados:
     - Seno e Cosseno: [0, π/2] e [0, π] (respectivamente, em radianos)
     - Logaritmo Natural e Exponencial: [2, 100]
     - Raiz n-ésima: x entre [2, 5000] e n entre [2, 20]
     - Seno hiperbólico: [0, 100]
   - Limpa o buffer de entrada para evitar erros de leitura entre os cálculos
   - Exibe uma mensagem de erro se os valores de entrada estiverem fora dos intervalos permitidos
   - Permite que o usuário continue calculando até escolher a opção de sair

   Exemplos de uso:
   - Cálculo de seno (sin) de um valor em graus: O usuário informa o valor e a precisão; o programa retorna o valor do seno.
   - Cálculo do logaritmo natural (ln) de um valor: O usuário fornece o valor de entrada e a precisão, e o programa exibe o logaritmo natural do valor.
   - Raiz n-ésima: O usuário especifica um valor para o qual deseja a raiz e o valor de "n"; o programa calcula e exibe a raiz com a precisão especificada.

   Observações:
   - O programa utiliza funções matemáticas implementadas manualmente para realizar os cálculos com precisão.
   - O programa exibe mensagens de erro para valores fora dos intervalos permitidos, evitando cálculos incorretos.
   - O programa é compatível com ANSI C e pode ser compilado em diversos ambientes, incluindo aqueles com restrições de conformidade com o padrão ANSI.
   - A entrada de valores inválidos resulta em mensagens informativas ao usuário, e a calculadora permanece no loop principal até que o usuário escolha sair.

   Programador: []
   RGM: []
   Data da última modificação: []

   Para compilar: gcc -o calculadora.exe calculadora_cientifica.c funcoes.c -Wall -pedantic -Wextra -Werror
*/


#include <locale.h>  /* Biblioteca para funções de localização, como setlocale() */
#include <stdio.h>   /* Biblioteca para funções de entrada e saída, como printf() e scanf() */
#include <stdlib.h>  /* Biblioteca para funções gerais, como system() */
#include "funcoes.h" /* Inclui o cabeçalho das funções personalizadas */

int main(int argc, char const *argv[])
{
    int func;        /* Variável para armazenar a escolha da função do usuário */
    double x;       /* Variável para armazenar o valor a ser calculado */
    int precisao;   /* Variável para armazenar o número de casas decimais de precisão desejada */

    /* Define a localidade para exibir caracteres conforme o idioma do sistema */
    setlocale(LC_CTYPE, "");

    /* Ignorando parâmetros da linha de comando para evitar warnings */
    argv = argv; /* Este comando é usado para evitar warnings de variáveis não utilizadas */
    argc = argc; /* Este comando é usado para evitar warnings de variáveis não utilizadas */
    
    printf("Bem vindo a Calculadora Cientifica!\n"); /* Mensagem de boas-vindas ao usuário */

    /* Loop principal do programa */
    do
    {
        exibir_menu(); /* Chama a função que exibe o menu de opções */
        printf("Digite o número da função que deseja calcular: "); /* Solicita ao usuário que escolha uma função */
        scanf("%d", &func); /* Lê a escolha do usuário e a armazena em 'func' */

        if (func == 0) /* Verifica se o usuário deseja encerrar o programa */
        {
            printf("Encerrando a calculadora...\n"); /* Mensagem de encerramento */
            break; /* Sai do loop e encerra o programa */
        }

        /* Solicita o valor e a precisão ao usuário */
        printf("Digite o valor a ser calculado (em graus): "); /* Solicita valor a ser calculado*/
        scanf("%lf", &x); /* Lê o valor e a precisão fornecidos pelo usuário */
        printf("Digite a precisao desejada: "); /* Solicita a precisão */
        scanf("%d", &precisao); /* Lê o valor e a precisão fornecidos pelo usuário */

        /* Executa o cálculo com base na escolha do usuário */
        executar_calculo(func, x, precisao); /* Chama a função para executar o cálculo com os parâmetros fornecidos */

    } while (1); /* Loop que continua até que o usuário decida encerrar */

    printf("\nObrigado por usar a calculadora! Ate a proxima.\n"); /* Mensagem de despedida ao usuário */

    return 0; /* Retorna 0, indicando que o programa foi executado com sucesso */
}
