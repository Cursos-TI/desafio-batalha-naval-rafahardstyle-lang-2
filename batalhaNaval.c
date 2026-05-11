#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Aqui eu declaro a matriz 10x10 que vai representar o tabuleiro.
    int tabuleiro[10][10];

    // Aqui eu declaro os vetores dos navios.
    // Cada navio tem tamanho 3 e cada posição dele recebe o valor 3.
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};

    // Aqui eu defino o tamanho fixo dos navios.
    int tamanhoNavio = 3;

    // Aqui eu defino as coordenadas iniciais dos navios diretamente no código.
    // Navio horizontal começa na linha 2, coluna 4.
    int linhaHorizontal = 2;
    int colunaHorizontal = 4;

    // Navio vertical começa na linha 5, coluna 7.
    int linhaVertical = 5;
    int colunaVertical = 7;

    // Variáveis de controle para validação.
    int podePosicionarHorizontal = 1;
    int podePosicionarVertical = 1;

    // Aqui eu inicializo todo o tabuleiro com 0, representando água.
    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // Aqui eu valido se o navio horizontal cabe dentro do tabuleiro.
    // Como ele vai para a direita, eu verifico se a coluna inicial + tamanho não passa de 10.
    if (colunaHorizontal + tamanhoNavio > 10) {
        podePosicionarHorizontal = 0;
    }

    // Aqui eu valido se o navio vertical cabe dentro do tabuleiro.
    // Como ele vai para baixo, eu verifico se a linha inicial + tamanho não passa de 10.
    if (linhaVertical + tamanhoNavio > 10) {
        podePosicionarVertical = 0;
    }

    // Aqui eu posiciono o navio horizontal no tabuleiro, se ele for válido.
    if (podePosicionarHorizontal == 1) {
        for (int i = 0; i < tamanhoNavio; i++) {
            tabuleiro[linhaHorizontal][colunaHorizontal + i] = navioHorizontal[i];
        }
    } else {
        printf("Erro: o navio horizontal nao cabe dentro do tabuleiro.\n");
    }

    // Aqui eu verifico se o navio vertical vai sobrepor alguma posição já ocupada.
    if (podePosicionarVertical == 1) {
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaVertical + i][colunaVertical] == 3) {
                podePosicionarVertical = 0;
            }
        }
    }

    // Aqui eu posiciono o navio vertical no tabuleiro, se ele for válido e não se sobrepuser.
    if (podePosicionarVertical == 1) {
        for (int i = 0; i < tamanhoNavio; i++) {
            tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
        }
    } else {
        printf("Erro: o navio vertical nao pode ser posicionado por causa de limite ou sobreposicao.\n");
    }

    // Aqui eu exibo as coordenadas ocupadas pelo navio horizontal.
    printf("Coordenadas do navio horizontal:\n");
    for (int i = 0; i < tamanhoNavio; i++) {
        printf("(%d, %d)\n", linhaHorizontal, colunaHorizontal + i);
    }

    // Aqui eu exibo as coordenadas ocupadas pelo navio vertical,
    // mas somente se ele tiver sido posicionado corretamente.
    if (podePosicionarVertical == 1) {
        printf("\nCoordenadas do navio vertical:\n");
        for (int i = 0; i < tamanhoNavio; i++) {
            printf("(%d, %d)\n", linhaVertical + i, colunaVertical);
        }
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Aqui eu exibo o tabuleiro completo no console.
    printf("\nTabuleiro completo:\n");
    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}