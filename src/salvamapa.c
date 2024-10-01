#include "biblio.h"

void escrever (int tamapa, char *mapa, int vida, int moeda, int posicaox, int posicaoy){

    FILE *pont_arq;
    pont_arq = fopen("arquivo.txt", "w");

    fprintf(pont_arq, "%d %s %d %d %d %d", tamapa, mapa, vida, moeda, posicaox, posicaoy);

    fclose(pont_arq);

}


char *continuamapa(int *vida, int *dificuldade, int *moeda, int *posicaox, int *posicaoy){
    FILE *pont_arq;
    pont_arq = fopen("arquivo.txt", "r");
    int tamapa;
    char *mapa;

    fscanf(pont_arq, "%d", &tamapa);

    if(tamapa*tamapa<90){
        mapa = (char*) malloc(82*sizeof(char));
        *dificuldade = 0;
    }
    if(tamapa*tamapa==121){
        mapa = (char*) malloc(122*sizeof(char));
        *dificuldade = 1;
    }
    if(tamapa*tamapa>250){
        mapa = (char*) malloc(257*sizeof(char));
        *dificuldade = 2;
    }

    fscanf(pont_arq, "%s %d %d %d %d", mapa, vida, moeda, posicaox, posicaoy);

    fclose(pont_arq);

    return mapa;

}