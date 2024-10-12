/*gcc -o calculadora calculadora_cientifica.c -Wall -pedantic -Wextra -Werror */

#include <math.h>    /* M_PI e M_E */
#include <stdio.h>   /* printf() e scanf() */
#include <stdlib.h> /* system() */
#include <locale.h>  /* setlocale() */

/* Fun��o para converter graus para radianos */
double radianos(double graus)
{
    return graus * (M_PI / 180.0);
}

/* Fun��o para calcular o seno usando s�rie de Taylor */
double seno(double x, int precisao)
{
	double termo, soma;
    int n;
	
    if (x < 0 || x > 90)
    {
        printf("Erro: O valor de x deve estar no intervalo [0, 90�]\n");
        return -1;
    }

    x = radianos(x); /* Transformar em radianos */

    termo = x;
    soma = x;
    n = 1;
    
    while (fabs(termo) > pow(10, -precisao))
    {
        n++;
        termo = -termo * x * x / ((2 * n - 2) * (2 * n - 1));
        soma += termo;
    }
    
    return soma;
}

/* Fun��o para calcular o cosseno usando s�rie de Taylor */
double cosseno(double x, int precisao)
{
	double termo, soma;
    int n;
	
    if (x < 0 || x > 90)
    {
        printf("Erro: O valor de x deve estar no intervalo [0, 90�]\n");
        return -1;
    }

    x = radianos(x); /* Transformar em radianos */

    termo = 1;
    soma = 1;
    n = 0;
    
    while (fabs(termo) > pow(10, -precisao))
    {
        n++;
        termo = -termo * x * x / ((2 * n - 1) * (2 * n));
        soma += termo;
    }
    
    return soma;
}

/* Fun��o para calcular a exponencial e^x usando s�rie de Taylor */
double exponencial(double x, int precisao)
{
	double termo, soma;
    int n;
	
    if (x < 2 || x > 100)
    {
        printf("Erro: O valor de x deve estar no intervalo [2, 100]\n");
        return -1;
    }

    termo = 1;
    soma = 1;
    n = 1;
    
    while (fabs(termo) > pow(10, -precisao))
    {
        termo *= x / n;
        soma += termo;
        n++;
    }
    
    return soma;
}

/* Fun��o para calcular o logaritmo natural usando transforma��o e s�rie */
double logaritmo_natural(double x, int precisao)
{
	double y;
    double termo, soma, temp;
    int n;
	
    if (x < 2 || x > 100)
    {
        printf("Erro: O valor de x deve estar no intervalo [2, 100]\n");
        return -1;
    }

    /* Transforma��o para usar o intervalo entre -1 e 1 */
    y = (x - 1) / (x + 1);
    termo = y;
    soma = 2 * termo;
    temp = termo * termo;
    n = 1;
    
    while (fabs(termo) > pow(10, -precisao))
    {
        termo *= temp;
        soma += (2.0 / (2 * n + 1)) * termo;
        n++;
    }
    
    return soma;
}

/* Fun��o para calcular o seno hiperb�lico usando s�rie de Taylor */
double seno_hiperbolico(double x, int precisao)
{
	double termo, soma;
    int n;
	
    if (x < 0 || x > 100)
    {
        printf("Erro: O valor de x deve estar no intervalo [0, 100]\n");
        return -1;
    }

    termo = x;
    soma = x;
    n = 1;
    
    while (fabs(termo) > pow(10, -precisao))
    {
        n++;
        termo = termo * x * x / ((2 * n - 1) * (2 * n - 2));
        soma += termo;
    }
    
    return soma;
}

/* Fun��o para calcular a raiz n-�sima de um n�mero usando o M�todo de Newton */
double raiz(double A, int n, int precisao)
{
	double f_prime_x;
    double fx;
    double x0;
    double x1;
	
    if (A < 2 || A > 5000 || n < 2 || n > 20)
    {
        printf("Erro: O valor de x deve estar no intervalo [2, 5000] e n no intervalo [2, 20]\n");
        return -1;
    }

    /* Definindo o chute inicial */
    x0 = (A > 2) ? 3 : 2.1;
    
    while (1)
    {
        fx = pow(x0, n) - A;
        f_prime_x = n * pow(x0, n - 1);
        x1 = x0 - fx / f_prime_x;
        
        if (fabs(pow(x1, n) - A) < pow(10, -precisao))
        {
            break;
        }
        
        x0 = x1;  
    }
    
    return x1;
}

/* Fun��o para exibir o menu de op��es */
void exibir_menu()
{
    system("cls");
    printf("\n--- Menu da Calculadora Cient�fica ---\n");
    printf("Escolha uma fun��o para calcular:\n");
    printf("1: Seno (sin)\n");
    printf("2: Cosseno (cos)\n");
    printf("3: Logaritmo Natural (ln)\n");
    printf("4: Raiz n-d�sima\n");
    printf("5: Exponencial (e^x)\n");
    printf("6: Seno hiperb�lico (sinh)\n");
    printf("0: Sair\n");
    printf("-------------------------------------\n");
}

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
