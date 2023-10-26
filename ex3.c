#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Veiculo {
    char chassi[20];
    char marca[30];
    char modelo[30];
    float preco;
};

struct Veiculo *alocarMemoria(int tamanho) {
    struct Veiculo *vetor = (struct Veiculo *)malloc(tamanho * sizeof(struct Veiculo));
    if (vetor == NULL) {
        printf("Falha na alocacao de memoria.\n");
        exit(1);
    }
    return vetor;
}

void preencherVeiculos(struct Veiculo *veiculos, int inicio, int tamanho) {
    for (int i = inicio; i < inicio + tamanho; i++) {
        printf("Digite o numero do chassi do veiculo %d: ", i + 1);
        scanf("%s", veiculos[i].chassi);

        printf("Digite a marca do veiculo %d: ", i + 1);
        scanf("%s", veiculos[i].marca);

        printf("Digite o modelo do veiculo %d: ", i + 1);
        scanf("%s", veiculos[i].modelo);

        printf("Digite o preço do veiculo %d: ", i + 1);
        scanf("%f", &veiculos[i].preco);
    }
}

void imprimirVeiculos(struct Veiculo *veiculos, int tamanho) {
    printf("Detalhes dos Veiculos:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Chassi: %s\n", veiculos[i].chassi);
        printf("Marca: %s\n", veiculos[i].marca);
        printf("Modelo: %s\n", veiculos[i].modelo);
        printf("Preco: %.2f\n", veiculos[i].preco);
    }
}

int main() {
    struct Veiculo *veiculos;
    int tamanho_inicial, novo_tamanho;

    printf("Digite o tamanho inicial do vetor de veiculos: ");
    scanf("%d", &tamanho_inicial);

    veiculos = alocarMemoria(tamanho_inicial);
    preencherVeiculos(veiculos, 0, tamanho_inicial);
    imprimirVeiculos(veiculos, tamanho_inicial);

    printf("Digite o novo tamanho do vetor de veiculos: ");
    scanf("%d", &novo_tamanho);

    veiculos = (struct Veiculo *)realloc(veiculos, novo_tamanho * sizeof(struct Veiculo));
    if (veiculos == NULL) {
        printf("Falha na realocacao de memoria.\n");
        return 1;
    }

    preencherVeiculos(veiculos, tamanho_inicial, novo_tamanho - tamanho_inicial);
    imprimirVeiculos(veiculos, novo_tamanho);

    free(veiculos);

    return 0;
}
