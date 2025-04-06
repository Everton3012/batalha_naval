#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void limparTabuleiro(int matriz[TAM][TAM]) {
    for(int i = 0; i < TAM; i++)
        for(int j = 0; j < TAM; j++)
            matriz[i][j] = 0;
}

void exibirTabuleiro(int matriz[TAM][TAM]) {
    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Cone
void habilidadeCone(int matriz[TAM][TAM], int centroX, int centroY, int altura) {
    for(int i = 0; i < altura; i++) {
        for(int j = -i; j <= i; j++) {
            int x = centroX + i;
            int y = centroY + j;
            if(x >= 0 && x < TAM && y >= 0 && y < TAM)
                matriz[x][y] = 1;
        }
    }
}

// Cruz
void habilidadeCruz(int matriz[TAM][TAM], int centroX, int centroY, int alcance) {
    for(int i = centroX - alcance; i <= centroX + alcance; i++) {
        if(i >= 0 && i < TAM)
            matriz[i][centroY] = 1;
    }
    for(int j = centroY - alcance; j <= centroY + alcance; j++) {
        if(j >= 0 && j < TAM)
            matriz[centroX][j] = 1;
    }
}

// Octaedro
void habilidadeOctaedro(int matriz[TAM][TAM], int centroX, int centroY, int alcance) {
    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {
            if(abs(i - centroX) + abs(j - centroY) <= alcance)
                matriz[i][j] = 1;
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int centroX = 5, centroY = 5;
    int escolha;

    printf("=== BATALHA NAVAL - HABILIDADES ESPECIAIS ===\n");
    printf("1 - Cone\n2 - Cruz\n3 - Octaedro\n");
    printf("Escolha a habilidade (1 a 3): ");
    scanf("%d", &escolha);

    limparTabuleiro(tabuleiro);

    switch(escolha) {
        case 1:
            habilidadeCone(tabuleiro, centroX, centroY, 3);
            printf("\nHabilidade: Cone (altura = 3)\n");
            break;
        case 2:
            habilidadeCruz(tabuleiro, centroX, centroY, 3);
            printf("\nHabilidade: Cruz (alcance = 3)\n");
            break;
        case 3:
            habilidadeOctaedro(tabuleiro, centroX, centroY, 2);
            printf("\nHabilidade: Octaedro (alcance = 2)\n");
            break;
        default:
            printf("Opção inválida!\n");
            return 0;
    }

    exibirTabuleiro(tabuleiro);

    return 0;
}