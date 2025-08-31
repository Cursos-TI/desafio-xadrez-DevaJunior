#include <stdio.h>

// Estrutura para peças lineares (Bispo, Torre, Rainha)
typedef struct {
    char nome[20];
    int movimentos;
    char direcao1[20];
    char direcao2[20]; // Usado em movimentos diagonais
} Peca;

// Estrutura específica para o Cavalo
typedef struct {
    char nome[20];
    int movBaixo;
    int movEsquerda;
} Cavalo;

int main() {

    // Constantes para os movimentos
    const int BISPO_MOV = 5;
    const int TORRE_MOV = 5;
    const int RAINHA_MOV = 8;
    const int CAVALO_BAIXO = 2;
    const int CAVALO_ESQUERDA = 1;

    // Peças
    Peca bispo  = {"Bispo", BISPO_MOV, "Cima", "Direita"};
    Peca torre  = {"Torre", TORRE_MOV, "Direita", ""};
    Peca rainha = {"Rainha", RAINHA_MOV, "Esquerda", ""};
    Cavalo cavalo = {"Cavalo", CAVALO_BAIXO, CAVALO_ESQUERDA};

    printf("=== Nível Aventureiro - Movimentação das Peças ===\n\n");

    // Bispo: 5 casas em diagonal sup. direita
    printf("%s:\n", bispo.nome);
    for (int i = 0; i < bispo.movimentos; i++) {
        printf("%s\n", bispo.direcao1); // "Cima"
        printf("%s\n", bispo.direcao2); // "Direita"
    }
    printf("\n");

    // Torre: 5 casas para direita
    printf("%s:\n", torre.nome);
    int j = 0;
    while (j < torre.movimentos) {
        printf("%s\n", torre.direcao1); // "Direita"
        j++;
    }
    printf("\n");

    // Rainha: 8 casas para esquerda
    printf("%s:\n", rainha.nome);
    int k = 0;
    do {
        printf("%s\n", rainha.direcao1); // "Esquerda"
        k++;
    } while (k < rainha.movimentos);
    printf("\n");

    // Cavalo: Movimento em L
    printf("%s:\n", cavalo.nome);

    /* Movimento em L:
       - 2 casas para baixo
       - 1 casa para a esquerda
    */
    for (int i = 0; i < cavalo.movBaixo; i++) {
        printf("Baixo\n");

        // Ao terminar de descer, move para a esquerda
        if (i == cavalo.movBaixo - 1) {
            int m = 0;
            while (m < cavalo.movEsquerda) {
                printf("Esquerda\n");
                m++;
            }
        }
    }

    printf("\n=== Fim do Nível Aventureiro ===\n");

    return 0;
}
