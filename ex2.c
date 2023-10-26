#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa {
    char CPF[12];
    char nome[50];
    float salario;
};

struct Pessoa *alocarMemoria(int n) {
    struct Pessoa *array = (struct Pessoa *)calloc(n, sizeof(struct Pessoa));
    if (array == NULL) {
        printf("Falha na alocacao de memoria.\n");
        exit(1);
    }
    return array;
}

void preencherPessoas(struct Pessoa *pessoas, int n) {
    for (int i = 0; i < n; i++) {

        printf("Digite o CPF da pessoa %d: ", i + 1);
        scanf("%s", pessoas[i].CPF);

        printf("Digite o nome da pessoa %d: ", i + 1);
        scanf("%s", pessoas[i].nome);

        printf("Digite o salario da pessoa %d: ", i + 1);
        scanf("%f", &pessoas[i].salario);
    }
}

void imprimirPessoas(struct Pessoa *pessoas, int n) {
    printf("Detalhes das Pessoas:\n");
    for (int i = 0; i < n; i++) {
        printf("CPF: %s\n", pessoas[i].CPF);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Salario: %.2f\n", pessoas[i].salario);
    }
}

int main() {
    struct Pessoa *pessoas;
    int n;

    printf("Digite o numero de pessoas: ");
    scanf("%d", &n);

    pessoas = alocarMemoria(n);
    preencherPessoas(pessoas, n);
    imprimirPessoas(pessoas, n);

    free(pessoas);

    return 0;
}
