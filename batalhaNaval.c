#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato / Aventureiro - Posicionamento dos Navios

    // Aqui eu declaro a matriz 10x10 que representa o tabuleiro.
    int tabuleiro[10][10];

    // Aqui eu defino o tamanho fixo dos navios.
    int tamanhoNavio = 3;

    // Aqui eu declaro os quatro navios, todos com valor 3.
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};
    int navioDiagonalPrincipal[3] = {3, 3, 3};
    int navioDiagonalSecundaria[3] = {3, 3, 3};

    // Aqui eu defino as coordenadas iniciais dos navios.
    // Navio horizontal
    int linhaHorizontal = 1;
    int colunaHorizontal = 2;

    // Navio vertical
    int linhaVertical = 5;
    int colunaVertical = 0;

    // Navio diagonal principal: linha e coluna aumentam juntas
    int linhaDiagonalPrincipal = 0;
    int colunaDiagonalPrincipal = 7;

    // Navio diagonal secundária: linha aumenta e coluna diminui
    int linhaDiagonalSecundaria = 7;
    int colunaDiagonalSecundaria = 9;

    // Variáveis de controle para validar se cada navio pode ser posicionado.
    int podeHorizontal = 1;
    int podeVertical = 1;
    int podeDiagonalPrincipal = 1;
    int podeDiagonalSecundaria = 1;

    // Aqui eu inicializo todo o tabuleiro com 0, representando água.
    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }


    // Validação e posicionamento do navio horizontal
    if (colunaHorizontal + tamanhoNavio > 10) {
        podeHorizontal = 0;
    }

    if (podeHorizontal == 1) {
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaHorizontal][colunaHorizontal + i] != 0) {
                podeHorizontal = 0;
            }
        }
    }

    if (podeHorizontal == 1) {
        for (int i = 0; i < tamanhoNavio; i++) {
            tabuleiro[linhaHorizontal][colunaHorizontal + i] = navioHorizontal[i];
        }
    } else {
        printf("Erro ao posicionar o navio horizontal.\n");
    }

  
    // Validação e posicionamento do navio vertical
    if (linhaVertical + tamanhoNavio > 10) {
        podeVertical = 0;
    }

    if (podeVertical == 1) {
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaVertical + i][colunaVertical] != 0) {
                podeVertical = 0;
            }
        }
    }

    if (podeVertical == 1) {
        for (int i = 0; i < tamanhoNavio; i++) {
            tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
        }
    } else {
        printf("Erro ao posicionar o navio vertical.\n");
    }


    // Validação e posicionamento do navio diagonal principal
    if (linhaDiagonalPrincipal + tamanhoNavio > 10 || colunaDiagonalPrincipal + tamanhoNavio > 10) {
        podeDiagonalPrincipal = 0;
    }

    if (podeDiagonalPrincipal == 1) {
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaDiagonalPrincipal + i][colunaDiagonalPrincipal + i] != 0) {
                podeDiagonalPrincipal = 0;
            }
        }
    }

    if (podeDiagonalPrincipal == 1) {
        for (int i = 0; i < tamanhoNavio; i++) {
            tabuleiro[linhaDiagonalPrincipal + i][colunaDiagonalPrincipal + i] = navioDiagonalPrincipal[i];
        }
    } else {
        printf("Erro ao posicionar o navio diagonal principal.\n");
    }

    // Validação e posicionamento do navio diagonal secundária
    if (linhaDiagonalSecundaria + tamanhoNavio > 10 || colunaDiagonalSecundaria - (tamanhoNavio - 1) < 0) {
        podeDiagonalSecundaria = 0;
    }

    if (podeDiagonalSecundaria == 1) {
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaDiagonalSecundaria + i][colunaDiagonalSecundaria - i] != 0) {
                podeDiagonalSecundaria = 0;
            }
        }
    }

    if (podeDiagonalSecundaria == 1) {
        for (int i = 0; i < tamanhoNavio; i++) {
            tabuleiro[linhaDiagonalSecundaria + i][colunaDiagonalSecundaria - i] = navioDiagonalSecundaria[i];
        }
    } else {
        printf("Erro ao posicionar o navio diagonal secundaria.\n");
    }

    // Aqui eu exibo o tabuleiro completo no console.
    printf("\nTabuleiro completo:\n\n");

    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}