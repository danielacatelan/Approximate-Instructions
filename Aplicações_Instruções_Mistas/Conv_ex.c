/*A aplicação implementa a convolução linear discreta de duas sequências
finitas pelo método direto, calculando os produtos entre pares de
elementos e acumulando-os nas posições correspondentes do vetor de saída
\cite{Pierre1996}. Para duas sequências de comprimentos $n$ e $m$, o
resultado possui $n+m-1$ elementos.

@article{Pierre1996,
  author  = {Pierre, John W.},
  title   = {A Novel Method for Calculating the Convolution Sum of Two
             Finite Length Sequences},
  journal = {IEEE Transactions on Education},
  volume  = {39},
  number  = {1},
  pages   = {77--80},
  year    = {1996},
  doi     = {10.1109/13.485235}
}


*/

#include <stdio.h>

static inline int ADD(int a, int b) {
    int result;
    asm volatile (
        "add %0, %1, %2"
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
            acc = ADD(acc, valor);
        }
    } else {
        for (long long k = 0; k < -vezes; k++) {
            acc = SUB(acc, valor);
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
