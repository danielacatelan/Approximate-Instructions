//Transformada de Hadamard

#include <stdio.h>

#define N 8

static inline int ADDX_M(int a, int b) {
    int result;
    asm volatile (
        "addx_m %0, %1, %2"
        : "=r" (result)
        : "r" (a), "r" (b)
    );
    return result;
}

static inline int SUB(int a, int b) {
    int result;
    asm volatile (
        "sub %0, %1, %2"
        : "=r" (result)
        : "r" (a), "r" (b)
    );
    return result;
}

void copiar(int dest[], int src[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

void hadamard(int x[], int y[], int n) {
    int temp[64];
    copiar(temp, x, n);

    for (int h = 1; h < n; h *= 2) {
        for (int i = 0; i < n; i += 2 * h) {
            for (int j = 0; j < h; j++) {
                int a = temp[i + j];
                int b = temp[i + j + h];

                temp[i + j]     = ADDX_M(a, b);
                temp[i + j + h] = SUB(a, b);
            }
        }
    }

    copiar(y, temp, n);
}

void imprimir(int vetor[], int n) {
    printf("Resultado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main(void) {
    int x[N] = {1, 2, 3, 4, 5, 6, 7, 8};
    int y[N];

    hadamard(x, y, N);
    imprimir(y, N);

    return 0;
}
