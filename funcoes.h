#ifndef FUNCOES_H
#define FUNCOES_H

/* Fun��es para c�lculos matem�ticos */
double seno();                  /* C�lculo do seno usando s�rie de Taylor */
double cosseno();               /* C�lculo do cosseno usando s�rie de Taylor */
double exponencial();           /* C�lculo da exponencial e^x usando s�rie de Taylor */
double logaritmo_natural();     /* C�lculo do logaritmo natural usando s�rie de Taylor */
double seno_hiperbolico();      /* C�lculo do seno hiperb�lico usando s�rie de Taylor */
double raiz();                  /* C�lculo da raiz n-�sima usando o M�todo de Newton */

/* Fun��es de utilidade */
void exibir_menu();              /* Exibe o menu de op��es */
void limpar_buffer();            /* Limpa o buffer de entrada */
void executar_calculo();         /* Executa o c�lculo com base na op��o selecionada */

#endif /* FUNCOES_H */
