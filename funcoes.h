#ifndef FUNCOES_H
#define FUNCOES_H

/* Funções para cálculos matemáticos */
double cosseno(double x, int precisao);
double exponencial(double x, int precisao);
double logaritmo_natural(double x, int precisao);
double raiz(int n, double x, int precisao);
double seno(double x, int precisao);
double seno_hiperbolico(double x, int precisao);

/* Funções de utilidade */
void executar_calculo(int func, double x, int n_raiz, int precisao);
void exibir_menu();
void limpar_buffer();
int verifica_intervalo(double x, double min, double max, char* mensagem_erro);

#endif /* FUNCOES_H */
