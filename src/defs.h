#ifndef DEFS_H
#define DEFS_H

#define PEQUENO 9
#define MEDIO 11
#define GRANDE 16 

typedef struct{
    int vida;
    int moedas;
    int movimentos;
    int x, y;
}per; 


typedef struct{
    int recent;
    int score;
} Highscores;


#endif