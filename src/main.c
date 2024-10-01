#include "biblio.h"
#include "defs.h"
#include <time.h>

per pers;

int main(){

    srand(time(NULL));

    initscr();
    cbreak();
    noecho(); 

    pers.x = pers.y = pers.moedas = pers.movimentos = 0;
    pers.vida = 100;

    int opcao;
    
    do{
        opcao = menuInicial();
        refresh();

        switch(opcao){
            case 0:
                dificuldade(jogar());
                break;
            case 1:
                dificuldade(-1);
                break;
            case 2:
                tabelainicial();
                break;
            case 3:
                creditos();
                break;
        }

        system("clear");


    }while (opcao != 4);

    endwin();
                                                                                                
    return 0;
}

FILE *abrirFile(char *local, char *tipo){
    FILE *f = fopen(local, tipo); 

    if (f == NULL){
        printf("FILE NAO FOI ABERTO\n");
        exit(-1);    
    }

    return f;
}

void dificuldade(int diff){
    refresh();

    char *salvar;

    if(diff==0){
        salvar = (char*) malloc(82);
        strcpy(salvar,leituraMapa(rand()%2, PEQUENO));
        pers.x = pers.y = 0;
        pers.vida = 100;
        pers.movimentos = 0;
    } 
    if(diff==1){
        salvar = (char*) malloc(122);
        strcpy(salvar,leituraMapa(rand()%3, MEDIO));
        pers.x = pers.y = 0;
        pers.vida = 100;
        pers.movimentos = 0;
    } 
    if(diff==2){
        salvar = (char*) malloc(257);
        strcpy(salvar,leituraMapa(rand()%2, GRANDE));
        pers.x = pers.y = 0;
        pers.vida = 100;
        pers.movimentos = 0;
    } 
    if(diff==-1){ 
        salvar = continuamapa(&pers.vida, &diff, &pers.moedas, &pers.x, &pers.y);
    }
    
    int x, y;

    getmaxyx(stdscr, y, x);

    char mov;
     
    switch(diff){
        case 0:
            do{
                desenharMapa(salvar,PEQUENO, pers.x, pers.y);
                move(0,0); 

                mov = getch();
                pers.movimentos++;

                if(mov == 'w' && pers.y-1 >= 0){
                    pers.y -= 1;
                }
                else if(mov == 's' && pers.y + 1 < PEQUENO){
                    pers.y += 1;
                }
                else if(mov == 'a' && pers.x-1 >= 0){
                    pers.x -= 1;
                }
                else if(mov == 'd' && pers.x+1 < PEQUENO){
                    pers.x += 1;
                }
                system("clear");


                if(salvar[pers.x + pers.y*PEQUENO] == 'B'){
                    pers.moedas+=7;
                }
                if(salvar[pers.x + pers.y*PEQUENO] == 'T'){
                    pers.vida -= 20;
                }

                if (salvar[pers.x + pers.y*PEQUENO] == 'S'){
                    mvprintw(y/2, x/2, "VOCE GANHOU!");
                    getch();
                    tabelahighscorefinal(pers.vida, pers.moedas, pers.movimentos);
                    break;
                }
                if(pers.vida <= 0){
                    mvprintw(y/2, x/2, "VOCE PERDEU!");
                    break;
                }
                escrever (PEQUENO, salvar, pers.vida, pers.moedas, pers.x, pers.y);

            }while(1);
           
            break;
        case 1:
            do{
                desenharMapa(salvar,MEDIO, pers.x, pers.y);
                move(0,0);

                mov = getch();
                pers.movimentos++;

                if(mov == 'w' && pers.y-1 >= 0){
                    pers.y -= 1;
                }
                else if(mov == 's' && pers.y + 1 < MEDIO){
                    pers.y += 1;
                }
                else if(mov == 'a' && pers.x-1 >= 0){
                    pers.x -= 1;
                }
                else if(mov == 'd' && pers.x+1 < MEDIO){
                    pers.x += 1;
                }
                system("clear");

                if(salvar[pers.x + pers.y*MEDIO] == 'B'){
                    pers.moedas+=5;
                }
                if(salvar[pers.x + pers.y*MEDIO] == 'T'){
                    pers.vida -= 20;
                }

                if (salvar[pers.x + pers.y*MEDIO] == 'S'){
                    mvprintw(y/2, x/2, "VOCE GANHOU!");
                    getch();
                    tabelahighscorefinal(pers.vida, pers.moedas, pers.movimentos);
                    break;
                    
                }
                if(pers.vida <= 0){
                    mvprintw(y/2, x/2, "VOCE PERDEU!");
                    break;
                }
                escrever (MEDIO, salvar, pers.vida, pers.moedas, pers.x, pers.y);
            }while(1);

            break;
        case 2:
            do{
                desenharMapa(salvar,GRANDE, pers.x, pers.y);
                move(0,0);
                

                mov = getch();
                pers.movimentos++;

                if(mov == 'w' && pers.y-1 >= 0){
                    pers.y -= 1;
                }
                else if(mov == 's' && pers.y + 1 < GRANDE){
                    pers.y += 1;
                }
                else if(mov == 'a' && pers.x-1 >= 0){
                    pers.x -= 1;
                }
                else if(mov == 'd' && pers.x+1 < GRANDE){
                    pers.x += 1;
                }
                system("clear");

                if(salvar[pers.x + pers.y*GRANDE] == 'B'){
                    pers.moedas+=4;
                }
                if(salvar[pers.x + pers.y*GRANDE] == 'T'){
                    pers.vida -= 20;
                }

                if (salvar[pers.x + pers.y*GRANDE] == 'S'){
                    mvprintw(y/2, x/2, "VOCE GANHOU!");
                    getch();
                    tabelahighscorefinal(pers.vida, pers.moedas, pers.movimentos );
                    break;
                    
                }
                if(pers.vida <= 0){
                    mvprintw(y/2, x/2, "VOCE PERDEU!");
                    break;
                }
                escrever (GRANDE, salvar, pers.vida, pers.moedas, pers.x, pers.y);
            }while(1);
            break;
    }

    free(salvar);
}
