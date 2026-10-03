#!/bin/bash

# ============================================================
# Script de testes RISC-V com Spike + PROF5
# Pasta de testes: Documentos/TESTES/Vetor_1000
# ============================================================

export PATH=$PATH:/opt/riscv/bin

# ---------- Configuração de caminhos ----------
TEST_DIR="/home/daniela/Documentos/TESTES/Vetor_1000"
PROF_DIR="/home/daniela/PROF5"
PROF_BIN="./prof5"
MODEL="${PROF_DIR}/models/APPROX.json"
ISA="rv32imafdc"
ARCH="rv32imafdc"
PK="/opt/riscv/riscv32-unknown-elf/bin/pk"
CC="riscv32-unknown-elf-gcc"

# ---------- Lista de testes ----------
# Cada nome corresponde a <nome>.c na pasta de testes
TESTES=(
    add
    add_SP
    addx
    addx_SP
    m_addx
    m_addx_SP
    addx_m
    addx_m_SP
    sub
    sub_SP
    subx
    subx_SP
    m_subx
    m_subx_SP
    subx_m
    subx_m_SP
)

# ---------- Função que executa 1 teste ----------
run_test() {
    local nome="$1"

    echo "=========================================================="
    echo ">>> Iniciando teste: $nome"
    echo "=========================================================="

    # 1) Compila
    cd "$TEST_DIR" || { echo "ERRO: não achei $TEST_DIR"; return 1; }
    $CC "${nome}.c" -O1 -march=${ARCH} -o "${nome}" || {
        echo "ERRO ao compilar ${nome}.c"; return 1;
    }

    # 2) Roda no Spike
    spike --isa=${ISA} ${PK} "${nome}" > "${nome}.txt" || {
        echo "ERRO no Spike para ${nome}"; return 1;
    }

    # 3) Roda no PROF5
    cd "$PROF_DIR" || { echo "ERRO: não achei $PROF_DIR"; return 1; }
    ${PROF_BIN} -i ${ISA^^} "${TEST_DIR}/${nome}" -m "$MODEL" || {
        echo "ERRO no PROF5 para ${nome}"; return 1;
    }

    echo "----------FIM-${nome}------------------------"
    echo ""
}

# ---------- Loop principal ----------
for t in "${TESTES[@]}"; do
    run_test "$t"
done

echo "=========================================================="
echo ">>> TODOS OS TESTES CONCLUÍDOS"
echo "=========================================================="
