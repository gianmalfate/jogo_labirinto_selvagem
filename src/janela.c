#include "biblio.h"

void liberarJanela(WINDOW *janela){	
	wborder(janela, ' ', ' ', ' ',' ',' ',' ',' ',' ');  //pa fica bunito
	wrefresh(janela);            //atualiza
    delwin(janela);
}

WINDOW *criarJanela(int altura, int largura, int y, int x){
    WINDOW *janela = newwin(altura, largura, y, x);
    box(janela, 0, 0);
    wrefresh(janela);
    refresh();

    return janela;    
}

