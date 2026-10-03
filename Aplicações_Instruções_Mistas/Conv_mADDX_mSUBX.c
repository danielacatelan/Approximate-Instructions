#include <stdio.h>

static inline int M_ADDX(int a, int b) {
    int result;
    asm volatile (
        "m_addx %0, %1, %2"
        : "=r" (result)
        : "r" (a), "r" (b)
    );
    return result;
}

static inline int M_SUBX(int a, int b) {
    int result;
    asm volatile (
        "m_subx %0, %1, %2"
        : "=r" (result)
        : "r" (a), "r" (b)
    );
    return result;
}

#define MAXN 32

void zerar(long long *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = 0;
    }
}

long long soma_sucessiva(long long valor, long long vezes) {
    long long acc = 0;
    if (vezes >= 0) {
        for (long long k = 0; k < vezes; k++) {
            acc = M_ADDX(acc, valor);
        }
    } else {
        for (long long k = 0; k < -vezes; k++) {
            acc = M_SUBX(acc, valor);
        }
    }
    return acc;
}

void convolucao(long long *a, int n, long long *b, int m, long long *res) {
    zerar(res, n + m - 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            long long parcela = soma_sucessiva(a[i], b[j]);
            res[i + j] = res[i + j] + parcela;
        }
    }
}

void imprimir(long long *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%lld ", vetor[i]);
    }
    printf("\n");
}

int main(void) {
    long long A[MAXN] = {1, 2, 3, 4, 5};
    long long B[MAXN] = {2, 1, 3};
    long long R[MAXN] = {0};

    int n = 5;
    int m = 3;

    convolucao(A, n, B, m, R);

    printf("Resultado da convolucao:\n");
    imprimir(R, n + m - 1);

    return 0;
}
