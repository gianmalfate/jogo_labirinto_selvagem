#ifndef BI_H
#define BI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <curses.h>


WINDOW *criarJanela(int altura, int largura, int y, int x);
void liberarJanela(WINDOW *local_win);


//iniciar tela
int menuInicial();
int jogar();
void dificuldade(int x);
void creditos();


static int highscoreComparator(const void *a, const void *b);
int calculascore(int vida, int moedas, int movimentos);
void  tabelahighscorefinal(int vida, int moedas, int movimentos);
void tabelainicial();

//mapa
WINDOW *criarMapaTamanho(int, int, int);
void desenharMapa(char *,int tamanhoMapa, int, int);
char *leituraMapa(int rand,  int tamanho);



#endif
