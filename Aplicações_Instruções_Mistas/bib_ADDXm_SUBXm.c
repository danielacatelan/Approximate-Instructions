//3. Modelo Binomial de Opções (versão 100% inteira – espírito do Black-Scholes)
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

inline int SUBX_M (int a, int b)
{
  int SUBX_M ; 
  asm volatile (
        "subx_m   %[z], %[x], %[y]\n\t"
        : [z] "=r" (SUBX_M ) 
        : [x] "r" (a), [y] "r" (b)
    );
  return (SUBX_M );
}

inline int ADDX_M  (int a, int b)
{
  int ADDX_M  ;
  asm volatile (
        "addx_m   %[z], %[x], %[y]\n\t"
        : [z] "=r" (ADDX_M  )
        : [x] "r" (a), [y] "r" (b)
    );
  return (ADDX_M  );
}



#define MAXN 32
#define SCALE 10000LL          // 4 casas decimais fixas

// Multiplicação de ponto fixo: (a * b) / SCALE
long long mul(long long a, long long b) {
    return (a * b) / SCALE;
}

// Exponenciação inteira simples (para u e d aproximados)
long long ipow(long long base, int exp) {
    long long r = SCALE;
    while (exp--) r = mul(r, base);
    return r;
}

long long binomial_call(long long S, long long K, int N,
                        long long u, long long d, long long p, long long disc) {
    long long preco[MAXN + 1];

    // Payoff no vencimento (só subtração)
    for (int i = 0; i <= N; i++) {
        long long ST = mul(S, mul(ipow(u, N - i), ipow(d, i)));
        preco[i] = (ST > K) ? ST - K : 0;
    }

    // Indução para trás (somas ponderadas)
    for (int step = N - 1; step >= 0; step--) {
        for (int i = 0; i <= step; i++) {
            //long long esperado = mul(p, preco[i]) + mul(SCALE - p, preco[i + 1]);//original       
           long long esperado = ADDX_M (mul(p, preco[i]) , mul(SUBX_M (SCALE, p) , preco[i + 1] ) );
           preco[i] = mul(disc, esperado);
        }
    }
    return preco[0];
}

int main(void) {
    // Exemplo: S=100, K=100, N=5
    // u ≈ 1.1, d ≈ 0.9, p ≈ 0.5, desconto ≈ 0.99 (valores já escalados)
    long long S    = 100 * SCALE;
    long long K    = 100 * SCALE;
    long long u    = 11000;     // 1.10
    long long d    =  9000;     // 0.90
    long long p    =  5000;     // 0.50
    long long disc =  9900;     // 0.99
    int N = 5;

    long long preco = binomial_call(S, K, N, u, d, p, disc);

    printf("Preço aproximado da Call (ponto fixo): %lld.%04lld\n",
           preco / SCALE, preco % SCALE);
    return 0;
}

