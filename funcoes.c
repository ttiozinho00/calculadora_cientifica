/*funcoes.c*/
#include <math.h>    /* M_PI e M_E: Bibliotecas matemáticas para constantes e funções matemáticas */
#include <stdio.h>   /* printf() e scanf(): Biblioteca para entrada e saída padrão */
#include <stdlib.h>  /* system(): Biblioteca para funções auxiliares como alocação de memória e controle de processos */
#include "funcoes.h" /* Cabeçalho das funções personalizadas: Inclui as definições das funções que são usadas neste arquivo */

/* Constantes para os limites de intervalo */
#define INTERVALO_SENO_COSSENO (M_PI / 2)    /* Limite máximo para seno e cosseno em radianos (π/2) */
#define INTERVALO_EXP_LN_MAX 100              /* Limite máximo para a função exponencial e logaritmo natural */
#define INTERVALO_EXP_LN_MIN 2                /* Limite mínimo para a função exponencial e logaritmo natural */
#define INTERVALO_RAIZ_MAX 5000               /* Limite máximo para a função raiz n-ésima */
#define INTERVALO_RAIZ_MIN 2                   /* Limite mínimo para a função raiz n-ésima */
#define INTERVALO_RAIZ_N_MIN 2                 /* Limite mínimo para a ordem da raiz n-ésima */
#define INTERVALO_RAIZ_N_MAX 20                /* Limite máximo para a ordem da raiz n-ésima */

/* Função para exibir o menu de opções */
void exibir_menu()
{
    printf("\n--- Menu da Calculadora Científica ---\n");  /* Título do menu */
    printf("Escolha uma função para calcular:\n");       /* Solicita que o usuário escolha uma função */
    printf("1: Seno (sin)\n");                          /* Opção 1: Calcular seno */
    printf("2: Cosseno (cos)\n");                       /* Opção 2: Calcular cosseno */
    printf("3: Logaritmo Natural (ln)\n");             /* Opção 3: Calcular logaritmo natural */
    printf("4: Raiz n-ésima\n");                        /* Opção 4: Calcular raiz n-ésima */
    printf("5: Exponencial (e^x)\n");                  /* Opção 5: Calcular exponencial */
    printf("6: Seno hiperbólico (sinh)\n");            /* Opção 6: Calcular seno hiperbólico */
    printf("0: Sair\n");                               /* Opção 0: Sair do programa */
    printf("-------------------------------------\n");    /* Linha de separação */
}

/* Função para limpar o buffer de entrada */
void limpar_buffer()
{
    int c;                             /* Variável para armazenar o caractere lido */
    int limite = 1000;                /* Limite máximo de caracteres para evitar loop infinito */

    /* Loop para ler caracteres até encontrar uma nova linha ou EOF */
    while ((c = getchar()) != '\n' && c != EOF && limite > 0)
    {
        limite--; /* Diminui o limite para cada caractere lido */
    }

    /* Se o limite foi excedido, pode haver um problema com o buffer */
    if (limite == 0)
    {
        printf("Aviso: O buffer de entrada pode não ter sido totalmente limpo.\n"); /* Aviso ao usuário */
    }
}

/* Função auxiliar para verificar intervalo */
int verifica_intervalo(double x, double min, double max, const char* mensagem_erro)
{
    /* Verifica se x está fora do intervalo permitido */
    if (x < min || x > max)
    {
        printf("%s\n", mensagem_erro);  /* Exibe mensagem de erro caso x esteja fora do intervalo */
        return 0;                        /* Retorna 0 indicando erro */
    }
    return 1;                            /* Retorna 1 indicando sucesso */
}

/* Função para calcular o seno usando série de Taylor */
double seno(double x, int precisao)
{
    double termo, soma;                /* Variáveis para armazenar os termos da série e a soma total */
    int n;                             /* Contador para os termos da série */

    /* Verifica se x está no intervalo [0, π/2] */
    if (!verifica_intervalo(x, 0, INTERVALO_SENO_COSSENO, "Erro: O valor de x deve estar no intervalo [0, π/2] (radianos)"))
    {
        return -1;                     /* Retorna -1 em caso de erro */
    }

    termo = x;                        /* Inicializa o primeiro termo da série */
    soma = x;                         /* Inicializa a soma com o primeiro termo */
    n = 1;                            /* Inicializa o contador de termos */

    /* Loop para calcular a soma da série de Taylor até atingir a precisão desejada */
    while (fabs(termo) > pow(10, -precisao))
    {
        termo = -termo * x * x / ((2 * n) * (2 * n + 1)); /* Calcula o próximo termo da série */
        soma += termo;           /* Adiciona o termo à soma total */
        n++;                     /* Incrementa o contador de termos */
    }

    return soma;                /* Retorna a soma total do seno */
}

/* Função para calcular o cosseno usando série de Taylor */
double cosseno(double x, int precisao)
{
    double termo, soma;                /* Variáveis para armazenar os termos da série e a soma total */
    int n;                             /* Contador para os termos da série */

    /* Verifica se x está no intervalo [0, π] */
    if (!verifica_intervalo(x, 0, M_PI, "Erro: O valor de x deve estar no intervalo [0, π] (radianos)"))
    {
        return -1;                     /* Retorna -1 em caso de erro */
    }

    termo = 1;                        /* Inicializa o primeiro termo da série */
    soma = 1;                         /* Inicializa a soma com o primeiro termo */
    n = 1;                            /* Inicializa o contador de termos */

    /* Loop para calcular a soma da série de Taylor até atingir a precisão desejada */
    while (fabs(termo) > pow(10, -precisao))
    {
        termo = -termo * x * x / ((2 * n - 1) * (2 * n)); /* Calcula o próximo termo da série */
        soma += termo;           /* Adiciona o termo à soma total */
        n++;                     /* Incrementa o contador de termos */
    }

    return soma;                /* Retorna a soma total do cosseno */
}

/* Função para calcular a exponencial e^x usando série de Taylor */
double exponencial(double x, int precisao)
{
    double termo, soma;                /* Variáveis para armazenar os termos da série e a soma total */
    int n;                             /* Contador para os termos da série */

    /* Verifica se x está no intervalo [2, 100] */
    if (!verifica_intervalo(x, INTERVALO_EXP_LN_MIN, INTERVALO_EXP_LN_MAX, "Erro: O valor de x deve estar no intervalo [2, 100]"))
    {
        return -1;                     /* Retorna -1 em caso de erro */
    }

    termo = 1;                        /* Inicializa o primeiro termo da série */
    soma = 1;                         /* Inicializa a soma com o primeiro termo */
    n = 1;                            /* Inicializa o contador de termos */

    /* Loop para calcular a soma da série de Taylor até atingir a precisão desejada */
    while (fabs(termo) > pow(10, -precisao))
    {
        termo *= x / n;              /* Calcula o próximo termo da série */
        soma += termo;               /* Adiciona o termo à soma total */
        n++;                         /* Incrementa o contador de termos */
    }

    return soma;                /* Retorna a soma total da exponencial */
}

/* Função para calcular o logaritmo natural usando transformação e série */
double logaritmo_natural(double x, int precisao)
{
    double y;                        /* Variável para armazenar a transformação do logaritmo */
    double termo, soma, temp;       /* Variáveis para os termos da série e a soma total */
    int n;                           /* Contador para os termos da série */

    /* Verifica se x está no intervalo [2, 100] */
    if (!verifica_intervalo(x, INTERVALO_EXP_LN_MIN, INTERVALO_EXP_LN_MAX, "Erro: O valor de x deve estar no intervalo [2, 100]"))
    {
        return -1;                     /* Retorna -1 em caso de erro */
    }

    y = (x - 1) / (x + 1);          /* Calcula a transformação de x */
    termo = y;                      /* Inicializa o primeiro termo da série */
    soma = 2 * termo;               /* Inicializa a soma com o primeiro termo transformado */
    temp = termo * termo;           /* Armazena o quadrado do primeiro termo */
    n = 1;                          /* Inicializa o contador de termos */

    /* Loop para calcular a soma da série até atingir a precisão desejada */
    while (fabs(termo) > pow(10, -precisao))
    {
        n += 2;                     /* Incrementa n para a próxima iteração */
        termo *= temp;             /* Calcula o próximo termo */
        soma += termo / n;         /* Adiciona o termo à soma total */
    }

    return soma;                /* Retorna a soma total do logaritmo natural */
}

/* Função para calcular a raiz n-ésima */
double raiz(int n, double x)
{
    double resultado;                /* Variável para armazenar o resultado da raiz */
    double erro;                    /* Variável para armazenar o erro de aproximação */
    double temp;                    /* Variável para armazenar o valor temporário */
    
    /* Verifica se n está no intervalo [2, 20] e se x está no intervalo [2, 5000] */
    if (!verifica_intervalo(n, INTERVALO_RAIZ_N_MIN, INTERVALO_RAIZ_N_MAX, "Erro: n deve estar entre 2 e 20") || !verifica_intervalo(x, INTERVALO_RAIZ_MIN, INTERVALO_RAIZ_MAX, "Erro: x deve estar entre 2 e 5000"))
    {
        return -1;                     /* Retorna -1 em caso de erro */
    }

    resultado = x / 2.0;            /* Inicializa o resultado com um valor inicial */
    erro = resultado;                /* Inicializa o erro com o resultado inicial */
    
    /* Loop para calcular a raiz n-ésima usando o método de Newton */
    while (fabs(resultado - erro) > 0.0001)  /* Continua até a precisão desejada ser alcançada */
    {
        erro = resultado;                     /* Armazena o resultado anterior */
        temp = pow(erro, n - 1);             /* Eleva o resultado ao (n-1) */
        resultado = ((n - 1) * temp + x) / n; /* Aplica a fórmula de Newton */
    }

    return resultado;                /* Retorna o resultado da raiz n-ésima */
}

/* Função para calcular o seno hiperbólico */
double seno_hiperbolico(double x, int precisao)
{
    double termo, soma;                /* Variáveis para armazenar os termos da série e a soma total */
    int n;                             /* Contador para os termos da série */

    /* Verifica se x está no intervalo [0, 5000] */
    if (!verifica_intervalo(x, 0, 5000, "Erro: O valor de x deve estar no intervalo [0, 5000]"))
    {
        return -1;                     /* Retorna -1 em caso de erro */
    }

    termo = x;                        /* Inicializa o primeiro termo da série */
    soma = x;                         /* Inicializa a soma com o primeiro termo */
    n = 1;                            /* Inicializa o contador de termos */

    /* Loop para calcular a soma da série de Taylor até atingir a precisão desejada */
    while (fabs(termo) > pow(10, -precisao))
    {
        termo = termo * x * x / ((2 * n) * (2 * n + 1)); /* Calcula o próximo termo da série */
        soma += termo;           /* Adiciona o termo à soma total */
        n++;                     /* Incrementa o contador de termos */
    }

    return soma;                /* Retorna a soma total do seno hiperbólico */
}

/* Função para executar o cálculo com base na opção selecionada */
void executar_calculo(int func, double x, int precisao)
{
    /* Declaração das variáveis para armazenar o valor em radianos, o resultado do cálculo e o valor de 'n' para raiz */
    double radianos, resultado;
    int n;
    
    /* Converte o valor 'x' de graus para radianos */
    radianos = x * (M_PI / 180);

    /* Estrutura de seleção 'switch' para escolher o cálculo com base na opção 'func' */
    switch (func)
    {
        /* Caso 1: Cálculo do Seno */
        case 1:
        {
            /* Chama a função 'seno' passando o valor em radianos e a precisão desejada */
            resultado = seno(radianos, precisao);
            /* Exibe o resultado formatado com o número de casas decimais especificado */
            printf("\nResultado do Seno: %.*f\n", precisao, resultado);
            break;
        }
        
        /* Caso 2: Cálculo do Cosseno */
        case 2:
        {
            /* Chama a função 'cosseno' passando o valor em radianos e a precisão desejada */
            resultado = cosseno(radianos, precisao);
            /* Exibe o resultado formatado com o número de casas decimais especificado */
            printf("\nResultado do Cosseno: %.*f\n", precisao, resultado);
            break;
        }
        
        /* Caso 3: Cálculo do Logaritmo Natural */
        case 3:
        {
            /* Chama a função 'logaritmo_natural' passando o valor em graus e a precisão desejada */
            /* logaritmo_natural espera x em graus, então não convertemos para radianos */
            resultado = logaritmo_natural(x, precisao);
            /* Exibe o resultado formatado com o número de casas decimais especificado */
            printf("\nResultado do Logaritmo Natural: %.*f\n", precisao, resultado);
            break;
        }
        
        /* Caso 4: Cálculo da Raiz */
        case 4:
        {
            /* Solicita ao usuário que insira o valor de 'n' (ordem da raiz) */
            printf("Digite o valor de n (ordem da raiz): ");
            scanf("%d", &n);
            /* Chama a função 'raiz' passando o valor e o valor de 'n' */
            resultado = raiz(x, n); /* Removido o parâmetro 'precisao'*/
            /* Verifica se a função retornou um valor válido antes de exibir o resultado */
            if (resultado != -1)
            {
                printf("\nResultado da Raiz %d-ésima: %.*f\n", n, precisao, resultado);
            }
            break;
        }
        
        /* Caso 5: Cálculo da Exponencial */
        case 5:
        {
            /* Chama a função 'exponencial' passando o valor em graus e a precisão desejada */
            /* exponencial espera x em graus, então não convertemos para radianos */
            resultado = exponencial(x, precisao);
            /* Exibe o resultado formatado com o número de casas decimais especificado */
            printf("\nResultado da Exponencial: %.*f\n", precisao, resultado);
            break;
        }
        
        /* Caso 6: Cálculo do Seno Hiperbólico */
        case 6:
        {
            /* Chama a função 'seno_hiperbolico' passando o valor em graus e a precisão desejada */
            /* seno_hiperbolico espera x em graus, então não convertemos para radianos */
            resultado = seno_hiperbolico(x, precisao);
            /* Exibe o resultado formatado com o número de casas decimais especificado */
            printf("\nResultado do Seno Hiperbólico: %.*f\n", precisao, resultado);
            break;
        }
        
        /* Caso padrão: Opção inválida */
        default:
        {
            /* Exibe uma mensagem de erro informando que a opção é inválida */
            printf("Opção inválida! Por favor, selecione uma opção válida.\n");
            break;
        }
    }
}


