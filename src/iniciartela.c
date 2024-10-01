#include "biblio.h"

int menuInicial(){
    int destaque=0;
    int escolha;
    char a[] = "Menu:";
    char opcoes[5][10] = {"Jogar", "Continuar", "Recordes", "Creditos", "Sair"};    
    int x, y;  

    getmaxyx(stdscr,y,x);       
    WINDOW *janela = criarJanela(20, 2*sizeof(opcoes[1]) + 8, y/2 - 10, x/2 - 15); 

    keypad(janela, true);

    do{
        for(int i=0; i<5; i++){
            mvprintw(y/2 - 5,(x-sizeof(a))/2 - 1, a);
            if(i == destaque) attron(A_REVERSE);
            mvprintw(y/2 - 1 + i,(x-sizeof(opcoes[i]))/2 + 1, opcoes[i]);
            attroff(A_REVERSE);
        }
        move(0, 0);
        
        wrefresh(janela);
        escolha = getch();

        switch(escolha){
            case 'w':
                destaque--;
                if(destaque == -1)
                    destaque = 0;
                break;
            case 's':
                destaque++;
                if(destaque == 5)
                    destaque = 4;
                break;
            default:
                break;
        }

        if(escolha == 10){
            liberarJanela(janela);
            return destaque;;
        }

    }while(1);

    return 6;
}

int jogar(){
    int destaque=0;
    int escolha;
    char a[] = "Escolha a dificuldade:";
    char opcoes[3][10] = {"Facil", "Medio", "Dificil"};    
    int x, y;  

    getmaxyx(stdscr,y,x);       
    WINDOW *janela = criarJanela(20, 2*sizeof(opcoes[2]) + 8, y/2 - 10, x/2 - 15); 

    keypad(janela, true);

    do{
        for(int i=0; i<3; i++){
            mvprintw(y/2 - 3,(x-sizeof(a))/2, a);
            if(i == destaque) attron(A_REVERSE);
            mvprintw(y/2 + i,(x-sizeof(opcoes[i]))/2 + 1, opcoes[i]);
            attroff(A_REVERSE);
        }
        move(0, 0);

        
        wrefresh(janela);
        escolha = getch();

        switch(escolha){
            case 'w':
                destaque--;
                if(destaque == -1)
                    destaque = 0;
                break;
            case 's':
                destaque++;
                if(destaque == 3)
                    destaque = 2;
                break;
            default:
                break;
        }
        if(escolha == 10){
            liberarJanela(janela);
            return destaque;
        }
    }while(1);

    return 6;
}

void creditos(){
    int destaque=0;
    int escolha;
    char a[] = "Labirinto Selvagem", b[] = "Luis Henrique Hergesel", c[] = "Matheus Henrique da Silva", d[] = "Lucas Masaki Maeda", e[] = "Giancarlo Malfate Caprino", f[] = "Gabriel de Souza Dalcin", g[] = "2022";
    char opcoes[1][10] = {"Voltar"};    
    int x, y;  

    getmaxyx(stdscr,y,x);       
    WINDOW *janela = criarJanela(20, 4*sizeof(opcoes[0]) - 6, y/2 - 10, x/2 - 18); 

    keypad(janela, true);

    do{
        for(int i=0; i<1; i++){
            mvprintw(y/2 - 8,(x-sizeof(a))/2 - 1, a);
            mvprintw(y/2 - 5,(x-sizeof(b))/2 - 1, b);
            mvprintw(y/2 - 4,(x-sizeof(c))/2 - 1, c);
            mvprintw(y/2 - 3,(x-sizeof(d))/2 - 1, d);
            mvprintw(y/2 - 2,(x-sizeof(e))/2 - 1, e);
            mvprintw(y/2 - 1,(x-sizeof(f))/2 - 1, f);
            mvprintw(y/2 + 2,(x-sizeof(g))/2 - 1, g);
            if(i == destaque) attron(A_REVERSE);
            mvprintw(y - 6,(x-sizeof(opcoes[i]))/2, opcoes[i]);
            attroff(A_REVERSE);
        }
        move(0, 0);

        wrefresh(janela);
        escolha = getch();

        switch(escolha){
            case 'w':
                destaque--;
                if(destaque == -1)
                    destaque = 0;
                
                break;
            case 's':
                destaque++;
                if(destaque == 1)
                    destaque = 0;
                break;
            default:
                break;
        }
        if(escolha == 10){
            liberarJanela(janela);
            break;
        }

        
    }while(1);
}