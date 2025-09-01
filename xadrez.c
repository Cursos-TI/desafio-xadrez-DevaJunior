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

// Função: Movimentos lineares
void moverLinear(Peca peca) {
    printf("%s:\n", peca.nome);
    
    if (strcmp(peca.nome, "Bispo") == 0) {
        for (int i = 0; i < peca.movimentos; i++) {
            printf("%s\n", peca.direcao1);
            printf("%s\n", peca.direcao2);
        }
    } else if (strcmp(peca.nome, "Torre") == 0) {
        int j = 0;
        while (j < peca.movimentos) {
            printf("%s\n", peca.direcao1);
            j++;
        }
    } else if (strcmp(peca.nome, "Rainha") == 0) {
        int k = 0;
        do {
            printf("%s\n", peca.direcao1);
            k++;
        } while (k < peca.movimentos);
    }
    printf("\n");
}

// Função: Movimento em L (cavalo)
void moverCavalo(Cavalo cavalo) {
    printf("%s:\n", cavalo.nome);
    for (int i = 0; i < cavalo.movBaixo; i++) {
        printf("Baixo\n");

        if (i == cavalo.movBaixo - 1) {
            int m = 0;
            while (m < cavalo.movEsquerda) {
                printf("Esquerda\n");
                m++;
            }
        }
    }
    printf("\n");
}

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

    printf("=== Nível Mestre - Movimentação das Peças ===\n\n");

    int escolha;
    do {
        printf("Escolha uma peça para movimentar:\n");
        printf("1 - Bispo\n2 - Torre\n3 - Rainha\n4 - Cavalo\n0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                moverLinear(bispo);
                break;
            case 2:
                moverLinear(torre);
                break;
            case 3:
                moverLinear(rainha);
                break;
            case 4:
                moverCavalo(cavalo);
                break;
            case 0:
                printf("Saindo do jogo...\n");
                break;
            default:
                printf("Opção inválida!\n\n");
        }
    } while (escolha != 0);

    printf("\n=== Fim do Nível Mestre ===\n");

    return 0;
}
