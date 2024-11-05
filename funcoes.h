#ifndef FUNCOES_H
#define FUNCOES_H

/* Funções para calculos matematicos */
double seno(double, int);                  /* Calculo do seno usando serie de Taylor */
double cosseno(double, int);               /* Calculo do cosseno usando serie de Taylor */
double exponencial(double, int);           /* Calculo da exponencial e^x usando serie de Taylor */
double logaritmo_natural(double, int);     /* Calculo do logaritmo natural usando serie de Taylor */
double seno_hiperbolico(double, int);      /* Calculo do seno hiperb�lico usando serie de Taylor */
double raiz(int, double);                  /* Calculo da raiz n-esima usando o Metodo de Newton */

/* Funções de utilidade */
void exibir_menu();              /* Exibe o menu de opoees */
void limpar_buffer();            /* Limpa o buffer de entrada */
void executar_calculo(int, double, int);         /* Executa o calculo com base na opçao selecionada */

#endif /* FUNCOES_H */
