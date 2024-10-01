# Labirinto Selvagem

## Descrição
Labirinto Selvagem é um jogo de labirinto desenvolvido em linguagem C, onde o jogador percorre um mapa labiríntico em busca da saída. Durante a exploração, o jogador enfrenta diversos desafios, como baús que fornecem pontos e vida, além de áreas perigosas que podem reduzir sua vida. O mapa é jogado "às cegas", ou seja, o jogador não tem uma visão completa do ambiente e deve confiar na exploração para encontrar a saída.

O jogo possui um menu inicial onde o jogador pode selecionar a dificuldade do labirinto e também oferece a opção de salvar o progresso, permitindo que o jogador continue de onde parou.

## Funcionalidades
- Seleção de Dificuldade: O jogador pode escolher entre diferentes níveis de dificuldade (Fácil, Médio e Difícil) ao iniciar o jogo. A dificuldade altera a quantidade de baús e áreas perigosas.

- Sistema de Pontuação e Vida: O jogador ganha pontos e vida ao encontrar baús escondidos pelo mapa e perde vida ao passar por áreas perigosas.

- Exploração "Às Cegas": O jogador não tem uma visão completa do mapa, devendo explorar passo a passo para encontrar a saída.

- Salvar e Carregar o Jogo: O jogador pode salvar o progresso e continuar o jogo em outro momento, garantindo que sua pontuação e posição no mapa sejam mantidas.

- Objetivo Final: O objetivo é encontrar a saída do labirinto antes que a vida acabe.

## Como Jogar
Início: Ao iniciar o jogo, o jogador será levado ao menu principal, onde pode:
- Selecionar a dificuldade do jogo.
- Carregar um jogo salvo.
- Ver o placar de líderes
- Sair do jogo.

## Exploração do Labirinto:
- O jogador inicia em um ponto aleatório do mapa.
- A cada movimento (usando as setas do teclado ou comandos específicos), o jogador explora uma nova área do labirinto.
- O jogador deve encontrar baús para ganhar vida e pontos.
- Áreas perigosas retiram vida do jogador, então é preciso evitá-las.
- O jogo termina quando o jogador encontra a saída ou quando sua vida chega a zero.

## Salvar o Progresso:
O jogador pode, a qualquer momento, salvar o progresso no menu de pausa e continuar posteriormente.

## Fim de Jogo:
O jogo termina se o jogador encontrar a saída ou perder toda a vida.

## Requisitos
- Compilador C: Certifique-se de ter um compilador C instalado (por exemplo, GCC).
- Sistema Operacional: O jogo pode ser executado em qualquer sistema operacional que suporte a linguagem C.
