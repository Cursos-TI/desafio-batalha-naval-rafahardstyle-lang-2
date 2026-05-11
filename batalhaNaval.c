#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Aqui eu declaro a matriz 10x10 que representa o tabuleiro principal.
    int tabuleiro[10][10];

    // Aqui eu defino o tamanho fixo dos navios.
    int tamanhoNavio = 3;

    // Aqui eu declaro os quatro navios com valor 3.
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};
    int navioDiagonalPrincipal[3] = {3, 3, 3};
    int navioDiagonalSecundaria[3] = {3, 3, 3};

    // Aqui eu defino as coordenadas iniciais dos quatro navios.
    int linhaHorizontal = 1;
    int colunaHorizontal = 2;

    int linhaVertical = 5;
    int colunaVertical = 0;

    int linhaDiagonalPrincipal = 0;
    int colunaDiagonalPrincipal = 7;

    int linhaDiagonalSecundaria = 7;
    int colunaDiagonalSecundaria = 9;

    // Variáveis de controle dos navios.
    int podeHorizontal = 1;
    int podeVertical = 1;
    int podeDiagonalPrincipal = 1;
    int podeDiagonalSecundaria = 1;

    // Aqui eu declaro três matrizes de habilidade 5x5.
    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

    // Aqui eu defino os pontos de origem das habilidades no tabuleiro.
    int origemConeLinha = 2;
    int origemConeColuna = 2;

    int origemCruzLinha = 6;
    int origemCruzColuna = 5;

    int origemOctaedroLinha = 4;
    int origemOctaedroColuna = 8;

    // Aqui eu inicializo todo o tabuleiro com 0.
    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // Posicionamento dos navios

    // Navio horizontal
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

    // Navio vertical
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

    // Navio diagonal principal
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

    // Navio diagonal secundária
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

    // ==============================
    // Construção das matrizes de habilidade
    // ==============================

    // Aqui eu inicializo as três matrizes de habilidade com 0.
    for (int linha = 0; linha < 5; linha++) {
        for (int coluna = 0; coluna < 5; coluna++) {
            cone[linha][coluna] = 0;
            cruz[linha][coluna] = 0;
            octaedro[linha][coluna] = 0;
        }
    }

    // Aqui eu construo a habilidade Cone.
    // A ideia é começar com 1 ponto no topo e ir aumentando para baixo.
    for (int linha = 0; linha < 5; linha++) {
        for (int coluna = 0; coluna < 5; coluna++) {
            if (coluna >= 2 - linha && coluna <= 2 + linha) {
                cone[linha][coluna] = 1;
            }
        }
    }

    // Aqui eu construo a habilidade Cruz.
    // A cruz ocupa a linha central e a coluna central.
    for (int linha = 0; linha < 5; linha++) {
        for (int coluna = 0; coluna < 5; coluna++) {
            if (linha == 2 || coluna == 2) {
                cruz[linha][coluna] = 1;
            }
        }
    }

    // Aqui eu construo a habilidade Octaedro.
    // O formato é de losango usando a distância até o centro.
    for (int linha = 0; linha < 5; linha++) {
        for (int coluna = 0; coluna < 5; coluna++) {
            int distanciaLinha = linha - 2;
            if (distanciaLinha < 0) {
                distanciaLinha = -distanciaLinha;
            }

            int distanciaColuna = coluna - 2;
            if (distanciaColuna < 0) {
                distanciaColuna = -distanciaColuna;
            }

            if (distanciaLinha + distanciaColuna <= 2) {
                octaedro[linha][coluna] = 1;
            }
        }
    }

    // Sobreposição das habilidades no tabuleiro

    // Aqui eu sobreponho o Cone no tabuleiro.
    for (int linha = 0; linha < 5; linha++) {
        for (int coluna = 0; coluna < 5; coluna++) {
            int linhaTabuleiro = origemConeLinha - 2 + linha;
            int colunaTabuleiro = origemConeColuna - 2 + coluna;

            if (linhaTabuleiro >= 0 && linhaTabuleiro < 10 &&
                colunaTabuleiro >= 0 && colunaTabuleiro < 10) {

                if (cone[linha][coluna] == 1 && tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0) {
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                }
            }
        }
    }

    // Aqui eu sobreponho a Cruz no tabuleiro.
    for (int linha = 0; linha < 5; linha++) {
        for (int coluna = 0; coluna < 5; coluna++) {
            int linhaTabuleiro = origemCruzLinha - 2 + linha;
            int colunaTabuleiro = origemCruzColuna - 2 + coluna;

            if (linhaTabuleiro >= 0 && linhaTabuleiro < 10 &&
                colunaTabuleiro >= 0 && colunaTabuleiro < 10) {

                if (cruz[linha][coluna] == 1 && tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0) {
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                }
            }
        }
    }

    // Aqui eu sobreponho o Octaedro no tabuleiro.
    for (int linha = 0; linha < 5; linha++) {
        for (int coluna = 0; coluna < 5; coluna++) {
            int linhaTabuleiro = origemOctaedroLinha - 2 + linha;
            int colunaTabuleiro = origemOctaedroColuna - 2 + coluna;

            if (linhaTabuleiro >= 0 && linhaTabuleiro < 10 &&
                colunaTabuleiro >= 0 && colunaTabuleiro < 10) {

                if (octaedro[linha][coluna] == 1 && tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0) {
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                }
            }
        }
    }

    // Exibição do tabuleiro final

    printf("\nTabuleiro completo com navios e habilidades:\n\n");

    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
            if (tabuleiro[linha][coluna] == 0) {
                printf("0 ");
            } else if (tabuleiro[linha][coluna] == 3) {
                printf("3 ");
            } else if (tabuleiro[linha][coluna] == 5) {
                printf("5 ");
            }
        }
        printf("\n");
    }

    return 0;
}