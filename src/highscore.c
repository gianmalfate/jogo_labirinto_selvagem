#include "defs.h"
#include "biblio.h"

// função que a tabelahighscore chama 

Highscores highscore[5];

static int highscoreComparator(const void *a, const void *b){
	Highscores *h1 = ((Highscores*)a);
	Highscores *h2 = ((Highscores*)b);

	return h2->score - h1->score;
}

// lógica do score
int calculascore(int vida, int moedas, int movimentos){ 
    int score=(moedas*vida - 5*movimentos);
    return score;
}

void  tabelahighscorefinal(int vida, int moedas, int movimentos){ 
    // lendo os highscores
    FILE *f = abrirFile("pontuacao.txt","r"); 
    for (int i=0;i<5;i++){
     fscanf(f,"%d ",&highscore[i].score);
    }
    fclose(f);
    
    // calculando o highscore     
     int score = calculascore(vida, moedas,movimentos);

    if (score<0){
        score=0;
    }
    
    // recebendo os valores antigos e colocando nos novos 
    Highscores novohighscore[6];
    for (int i=0; i<5 ;i++){
        novohighscore[i].score = highscore[i].score;
        novohighscore[i].recent = 0;
    }

    // atribui a score mais nova e só ela tem recent=1 e ordena todos de acordo com o maior ou menor 
    novohighscore[5].score = score; 
    novohighscore[5].recent = 1; 
    qsort(novohighscore, 6, sizeof(Highscores), highscoreComparator); 

    // todos os novos passam a ser "antigos" pra poder ser usado na inithightscore 
	for (int i = 0 ; i < 5 ; i++){
		highscore[i].score = novohighscore[i].score;  
        highscore[i].recent = novohighscore[i].recent;  
	}

//  -- printando na tela  -- // 

    //configurando a box
    int x,y;
    getmaxyx(stdscr,y,x); 

    WINDOW *janela = criarJanela(16, 22 , y/2-10, x/2 - 12);  

    do{
        mvprintw(y/2-13,x/2- 10,"TABELA DE HIGHSCORE");
        
        // printando as highscores de dentro
        for (int i=0;i<5;i++){
            if(highscore[i].recent==0){
                mvprintw(y/2-9+2*i,x/2-7,"#%d ----- %d",i+1,highscore[i].score);
            }
            else {
                mvprintw(y/2-9+2*i,x/2-7,"#%d ----- %d",i+1,highscore[i].score);
                mvprintw(y/2-9+2*i,x/2+12,"-> NEW SCORE");
            }
        } 

        // mostrando a pontuação 
        mvprintw(y/2+2,x/2-10,"SEU SCORE FOI %d",score);    
        mvprintw(y/2+8,x/2-13,"<APERTE ENTER PARA MENU>");

        move(0,0);
        wrefresh(janela);

        // salvando os valores na highscore.txt 

        f = abrirFile("pontuacao.txt","w"); 
        for (int i=0;i<5;i++)
        fprintf(f,"%d ",highscore[i].score);
        fclose(f);

        if(getch() == 10){
            liberarJanela(janela);
            return;
        }
    
    
    }while(1);
}


void tabelainicial(){
    
    // lendo os highscores
    FILE *f = fopen("pontuacao.txt","r"); 
    for (int i=0;i<5;i++){
        fscanf(f,"%d ",&highscore[i].score);
    }
    fclose(f);
    
    //printando na tela   
    //configurando a box
    int x,y;
    getmaxyx(stdscr,y,x); 
    WINDOW *janela = criarJanela(14, 22 , y/2-11, x/2 - 12); 

    
    do {
        mvprintw(y/2-14,x/2- 10,"TABELA DE HIGHSCORE");


        // printando as highscores de dentro
        for (int i=0;i<5;i++){
                mvprintw(y/2-9+2*i,x/2-7,"#%d ----- %d",i+1,highscore[i].score);
            }
        
        mvprintw(y/2+8,x/2-13,"<APERTE ENTER PARA MENU>");
        move(0,0);
        wrefresh(janela);

        // salvando os valores na highscore.txt 
        f = fopen("pontuacao.txt","r"); 
            for (int i=0;i<5;i++)
            fprintf(f,"%d ",highscore[i].score);

        fclose(f);
        if(getch() == 10){
            liberarJanela(janela);
            return;
        }

    }while(1);
}
