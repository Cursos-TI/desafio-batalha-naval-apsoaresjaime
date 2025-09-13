#include <stdio.h>

int main() {
    /* 1) Tabuleiro 10x10 inicializado com 0 (água) */
    int tabuleiro[10][10];
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    /* 2) Vetores representando os navios (3 posições = valor 3) */
    int navH[3] = { 3, 3, 3 }; /* horizontal */
    int navV[3] = { 3, 3, 3 }; /* vertical   */

    /* 3) Coordenadas iniciais (0-based) — ajuste aqui se quiser testar */
    int linhaH = 2, colH = 3; /* H ocupa (2,3) (2,4) (2,5) */
    int linhaV = 5, colV = 6; /* V ocupa (5,6) (6,6) (7,6) */

    /* 4) Validação de limites para os dois navios (tamanho 3) */
    int ok_limites_H = 1, ok_limites_V = 1;

    if (linhaH < 0 || linhaH >= 10 || colH < 0 || colH >= 10) ok_limites_H = 0;
    if (colH + 3 - 1 >= 10) ok_limites_H = 0;

    if (linhaV < 0 || linhaV >= 10 || colV < 0 || colV >= 10) ok_limites_V = 0;
    if (linhaV + 3 - 1 >= 10) ok_limites_V = 0;

    if (!ok_limites_H) {
        printf("Erro: navio horizontal fora dos limites em (%d,%d).\n", linhaH, colH);
        return 1;
    }
    if (!ok_limites_V) {
        printf("Erro: navio vertical fora dos limites em (%d,%d).\n", linhaV, colV);
        return 1;
    }

    /* 5) Verificação de sobreposição antes de posicionar */
    {
        int sobrepoe = 0;
        int kH, kV, hL, hC, vL, vC;
        for (kH = 0; kH < 3; kH++) {
            hL = linhaH;
            hC = colH + kH;
            for (kV = 0; kV < 3; kV++) {
                vL = linhaV + kV;
                vC = colV;
                if (hL == vL && hC == vC) {
                    sobrepoe = 1;
                }
            }
        }
        if (sobrepoe) {
            printf("Erro: sobreposicao detectada entre os navios.\n");
            return 1;
        }
    }

    /* 6) Posiciona navio horizontal copiando o vetor para a matriz */
    {
        int k;
        for (k = 0; k < 3; k++) {
            tabuleiro[linhaH][colH + k] = navH[k];
        }
    }

    /* 7) Posiciona navio vertical copiando o vetor para a matriz */
    {
        int k;
        for (k = 0; k < 3; k++) {
            tabuleiro[linhaV + k][colV] = navV[k];
        }
    }

    /* 8) Exibição do tabuleiro com cabeçalhos */
    printf("\nTabuleiro (0 = agua, 3 = navio)\n\n");

    /* Cabeçalho de colunas */
    printf("    ");
    for (j = 0; j < 10; j++) printf("%d ", j);
    printf("\n");

    /* Linha separadora */
    printf("    ");
    for (j = 0; j < 10; j++) printf("--");
    printf("\n");

    for (i = 0; i < 10; i++) {
        printf("%2d | ", i);
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

