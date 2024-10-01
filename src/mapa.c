#include "defs.h"
#include "biblio.h"


WINDOW *criarMapaTamanho( int tamMapa, int x, int y){       
    WINDOW *janela;

    if(tamMapa == 9) {   //caso pequeno
        janela = criarJanela(20,36,(y-20)/2,(x-36)/2); 
    }

    else if(tamMapa == 11)     //caso medio
        janela = criarJanela(23, 41, (y-23)/2, (x-41)/2); 
    else 
        janela = criarJanela(20, 60,(y-24)/2 + 2, (x-60)/2); 
    
    return janela;
}

void desenharMapa(char *str, int tamanhoMapa, int posx, int posy){
    
    int x, y; 
    char c = ' ', p = 'P';

    getmaxyx(stdscr, y, x);

    WINDOW *janela = criarMapaTamanho(tamanhoMapa, x, y);

    start_color();
    init_pair(1, COLOR_BLACK, COLOR_GREEN);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_YELLOW);

    wbkgd(janela, COLOR_PAIR(1));

    // Desenhando os mapas na janela
    if(tamanhoMapa == 9){
         for (int i = 0,j=0,w=0; i < strlen(str); i++){
            
            if(str[i] != 'C'&& str[i] != 'T') {
                
                mvwaddch(janela, 1+2*j, 3+3*w, str[i]) | COLOR_PAIR(3);
                mvwaddch(janela, 1+2*j, 3+3*w-1, c | COLOR_PAIR(3));
                mvwaddch(janela, 1+2*j, 3+3*w+1, c| COLOR_PAIR(3));
                
            }   

             if(posx == w && posy == j){
                mvwaddch(janela, 1+2*j, 3+3*w, p | COLOR_PAIR(2));
                mvwaddch(janela, 1+2*j, 3+3*w-1, c | COLOR_PAIR(2));
                mvwaddch(janela, 1+2*j, 3+3*w+1, c| COLOR_PAIR(2));

                if(str[w+j*tamanhoMapa] == 'B' || str[w+j*tamanhoMapa] == 'A'){
                    str[w+j*tamanhoMapa] = 'C';
                }
            }

            if(w!=tamanhoMapa-1){
                w++;
            }
            else {
                w=0;
                j++;
            }
        }
    }
    else if(tamanhoMapa == 11){
         for (int i = 0,j=0,w=0; i < strlen(str); i++){
            
            if(str[i] != 'C'&& str[i] != 'T') {
                
                mvwaddch(janela, 1+2*j, 5+3*w, str[i]) | COLOR_PAIR(3);
                mvwaddch(janela, 1+2*j, 5+3*w-1, c | COLOR_PAIR(3));
                mvwaddch(janela, 1+2*j, 5+3*w+1, c| COLOR_PAIR(3));
                
            }   

             if(posx == w && posy == j){
                mvwaddch(janela, 1+2*j, 5+3*w, p | COLOR_PAIR(2));
                mvwaddch(janela, 1+2*j, 5+3*w-1, c | COLOR_PAIR(2));
                mvwaddch(janela, 1+2*j, 5+3*w+1, c| COLOR_PAIR(2));

                if(str[w+j*tamanhoMapa] == 'B' || str[w+j*tamanhoMapa] == 'A'){
                    str[w+j*tamanhoMapa] = 'C';
                }
            }

            if(w!=tamanhoMapa-1){
                w++;
            }
            else {
                w=0;
                j++;
            }
        }
    }
    else {
        for (int i = 0,j=0,w=0; i < strlen(str); i++){
            
            if(str[i] != 'C'&& str[i] != 'T') {
                
                mvwaddch(janela, 2+j, 7+3*w, str[i]) | COLOR_PAIR(3);
                mvwaddch(janela, 2+j, 7+3*w-1, c | COLOR_PAIR(3));
                mvwaddch(janela, 2+j, 7+3*w+1, c| COLOR_PAIR(3));
                
            }   

             if(posx == w && posy == j){
                mvwaddch(janela, 2+j, 7+3*w, p | COLOR_PAIR(2));
                mvwaddch(janela, 2+j, 7+3*w-1, c | COLOR_PAIR(2));
                mvwaddch(janela, 2+j, 7+3*w+1, c| COLOR_PAIR(2));

                if(str[w+j*tamanhoMapa] == 'B' || str[w+j*tamanhoMapa] == 'A'){
                    str[w+j*tamanhoMapa] = 'C';
                }
            }

            if(w!=tamanhoMapa-1){
                w++;
            }
            else {
                w=0;
                j++;
            }
        }
    }


    
    refresh();

    wrefresh(janela);

    liberarJanela(janela);
 

}




