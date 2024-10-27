#ifndef FUNCOES_H
#define FUNCOES_H

/* Funções para cálculos matemáticos */
double seno();                    /* Cálculo do seno usando série de Taylor */
double cosseno();                 /* Cálculo do cosseno usando série de Taylor */
double exponencial();             /* Cálculo da exponencial e^x usando série de Taylor */
double logaritmo_natural();       /* Cálculo do logaritmo natural usando série de Taylor */
double seno_hiperbolico();        /* Cálculo do seno hiperbólico usando série de Taylor */
double raiz();             		  /* Cálculo da raiz n-ésima usando o Método de Newton */
double graus_para_radianos();     /* Conversão de graus para radianos */

/* Funções auxiliares */
void exibir_menu();               /* Exibe o menu de opções */
void calcular_funcao();           /* Realiza o cálculo conforme a função escolhida */

#endif 
