#!/bin/bash
# ============================================================
# Script de compilacao + simulacao + profiling
# Apenas inteiros, apenas soma e subtracao
#
# Estrutura: 3 grupos (Bank, Hada, NTT) x 10 variantes cada
# Total: 30 binarios
# ============================================================

export PATH=$PATH:/opt/riscv/bin

DIR_TESTES=/home/daniela/Documentos/TESTES/Teste_Mistas
DIR_PROF5=/home/daniela/PROF5
SPIKE_PK=/opt/riscv/riscv32-unknown-elf/bin/pk
MODELO=$DIR_PROF5/models/APPROX.json

# ------------------------------------------------------------
# Grupos e variantes
# ------------------------------------------------------------
GRUPOS="Bank Hada bib FIR Floyd Conv"

VARIANTES="ex ADDX SUBX ADDX_SUBX ADDXm SUBXm ADDXm_SUBXm  mADDX mSUBX mADDX_mSUBX "

# ------------------------------------------------------------
# Loop principal
# ------------------------------------------------------------
TOTAL=0
OK=0
FALHAS=0

for grupo in $GRUPOS; do
    for var in $VARIANTES; do
        nome="${grupo}_${var}"
        TOTAL=$((TOTAL + 1))

        echo "=================================================="
        echo " Processando: $nome"
        echo "=================================================="

        # 1) Compilar
        cd "$DIR_TESTES" || { echo "ERRO: $DIR_TESTES nao existe"; exit 1; }

        if [ ! -f "$nome.c" ]; then
            echo "AVISO: $nome.c nao encontrado, pulando..."
            FALHAS=$((FALHAS + 1))
            continue
        fi

        riscv32-unknown-elf-gcc "$nome.c" -O1 -march=rv32imafdc -o "$nome"
        if [ $? -ne 0 ]; then
            echo "ERRO ao compilar $nome.c"
            FALHAS=$((FALHAS + 1))
            continue
        fi

        # 2) Simular com spike
        spike --isa=rv32imafdc "$SPIKE_PK" "$nome" > "$nome.txt"
        if [ $? -ne 0 ]; then
            echo "ERRO ao simular $nome"
            FALHAS=$((FALHAS + 1))
            continue
        fi

        # 3) Profiling com prof5
        cd "$DIR_PROF5" || { echo "ERRO: $DIR_PROF5 nao existe"; exit 1; }
        ./prof5 -i RV32IMAFDC "$DIR_TESTES/$nome" -m "$MODELO"

        echo "----------FIM-$nome------------------------"
        echo

        OK=$((OK + 1))
    done
done

# ------------------------------------------------------------
# Resumo final
# ------------------------------------------------------------
echo "=================================================="
echo " RESUMO FINAL"
echo "=================================================="
echo " Total de testes : $TOTAL"
echo " Concluidos OK   : $OK"
echo " Falhas          : $FALHAS"
echo "=================================================="
