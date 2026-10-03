/*Conclusão: O Algoritmo do Banqueiro (Banker's Algorithm) é provavelmente o mais adequado às suas necessidades. Foi proposto por Dijkstra em 1965 e é utilizado em inúmeros artigos sobre sistemas operacionais e algoritmos de prevenção de deadlock, sendo uma "aplicação famosa" com forte respaldo acadêmico. Seu núcleo é inteiramente baseado em inteiros, e as operações principais consistem em comparação, adição e subtração — satisfazendo perfeitamente a sua exigência de "apenas inteiros, apenas adição e subtração".

Por que o Algoritmo do Banqueiro é adequado
O objetivo central do Algoritmo do Banqueiro é: antes de o sistema alocar recursos, primeiro determinar se o estado após a alocação é "seguro". Se for seguro, aloca; caso contrário, faz o processo esperar

*/


#include <stdio.h>
#include <stdbool.h>

#define P 5
#define R 3

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

void calcular_necessidade(int need[P][R], int max[P][R], int aloc[P][R]) {
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            need[i][j] = M_SUBX(max[i][j], aloc[i][j]);
        }
    }
}

bool verificar_seguranca(int avail[R], int aloc[P][R], int need[P][R], int seq[P]) {
    int work[R];
    bool finish[P] = {false};
    int count = 0;

    for (int i = 0; i < R; i++) {
        work[i] = avail[i];
    }

    while (count < P) {
        bool encontrado = false;

        for (int i = 0; i < P; i++) {
            if (!finish[i]) {
                bool pode = true;

                for (int j = 0; j < R; j++) {
                    if (need[i][j] > work[j]) {
                        pode = false;
                        break;
                    }
                }

                if (pode) {
                    for (int j = 0; j < R; j++) {
                        work[j] = M_ADDX(work[j], aloc[i][j]);
                    }
                    seq[count++] = i;
                    finish[i] = true;
                    encontrado = true;
                }
            }
        }

        if (!encontrado) {
            return false;
        }
    }
    return true;
}

void imprimir_sequencia(int seq[P]) {
    printf("Estado seguro. Sequencia segura: ");
    for (int i = 0; i < P; i++) {
        printf("P%d ", seq[i]);
    }
    printf("\n");
}

int main(void) {
    int aloc[P][R] = {
        {0,1,0},
        {2,0,0},
        {3,0,2},
        {2,1,1},
        {0,0,2}
    };

    int max[P][R] = {
        {7,5,3},
        {3,2,2},
        {9,0,2},
        {2,2,2},
        {4,3,3}
    };

    int avail[R] = {3,3,2};
    int need[P][R];
    int seq[P];

    calcular_necessidade(need, max, aloc);

    if (verificar_seguranca(avail, aloc, need, seq)) {
        imprimir_sequencia(seq);
    } else {
        printf("Estado inseguro (pode ocorrer deadlock)\n");
    }

    return 0;
}
