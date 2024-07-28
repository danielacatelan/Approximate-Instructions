#####################################################################

Author: Daniela Luiza Catelan \
Professor at Federal University of Mato Grosso do Sul

#####################################################################

Este repositório, apresenta como inserir instruções aproximadas no conjunto de instruções do RISC-V e do SPIKE.

O projeto de instruções aproximadas do tipo inteiro (addx, subx, mulx, divx) e de ponto flutuante (faddx, fsubx, fmulx, fdivx) fazem parte do meu projeto de doutorado, cujo o tema é: Exploração do Espaço de Projeto com Computação Aproximada.

# Instruções Aproximadas

## Descrição:
  > Este repositório mostrará o projeto de desenvolvimento das instruções aproximadas de inteiro e ponto flutuante e o passo a passo para a inserção das mesmas no RISC-V e SPIKE.

## Ferramentas
> Para a utilização da instrução aproximada é preciso ter as ferramentas abaixo, devidamente instaladas.

  1. **RISC-V Toolchain**
   - Disponível em: [RISC-V Toolchain](https://github.com/riscv-collab/riscv-gnu-toolchain).      
   - OBS: procedimentos utilizados por mim para a instalação, baseando-me no repositório original.

    $ sudo apt-get install autoconf automake autotools-dev curl python3 libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev libexpat-dev git

    $ git clone https://github.com/riscv/riscv-gnu-toolchain
     
    $ cd riscv-gnu-toolchain
     
    $ ./configure --prefix=/opt/riscv --with-arch=rv32i --with-abi=ilp32
     
    $ sudo make
     
    $ cd ..
     
    $ export PATH=$PATH:/opt/riscv/bin

  2. **RISCV-OPCODES**
     
     Acesse o site: https://github.com/riscv/riscv-opcodes.git \
     Faça o download. Copie o conteúdo para a pasta riscv-opcodes (substitui o arquivo encoding.h existente) \
     https://github.com/riscv/riscv-opcodes/tree/7c3db437d8d3b6961f8eb2931792eaea1c469ff3

   4. **RISCV-OPENOCD**
      
     git clone https://github.com/riscv/riscv-openocd.git
        
   4. **RISCV-FERSV**
     
	$ cd riscv-fesvr

	$ mkdir build && cd build
 
	$ ../configure --prefix=/opt/riscv
 
	$ sudo make install
 
	$ cd ../..

   5. **RISCV-PK**
     
	$ cd riscv-pk

	$ mkdir build && cd build
 
	$ ../configure --prefix=/opt/riscv --host=riscv32-unknown-elf
 
        OBS: pode ser que precise colocar:
	
	    -> $ ../configure --prefix=/opt/riscv --host=riscv32-unknown-elf --with-arch=rv32imafdc_zicsr_zifencei
     
	$ make
 
	$ sudo make install
 
	$ cd ../..

  6. **RISCV-ISA-SIM (SPIKE)**
      
	$ cd riscv-isa-sim

	$ sudo apt-get install device-tree-compiler
 
	$ mkdir build && cd build
 
	$ ../configure --prefix=/opt/riscv 
 
	$ make
 
	$ sudo make install
       
## Instrução Aproximada

   - Após a instalação das ferramentas, é preciso adicionar a instrução aproximada.     
   - Será preciso adicionar a instrução aproximada no RISC-V Toolchain e no SPIKE, seguindo corretamente o passo a passo a seguir. 
  
1. **Inserção das Instruções Aproximadas no RISCV-TOOLCHAIN**
   
  a: Acesse o diretório riscv-opcodes e adicione os opcodes (riscv-opcodes/opcodes)  
-> inteiro \
addx    rd rs1 rs2 31..25=1  14..12=0 6..2=0x0A 1..0=3 \
subx    rd rs1 rs2 31..25=1  14..12=0 6..2=0x0B 1..0=3 \
mulx    rd rs1 rs2 31..25=1  14..12=0 6..2=0x1C 1..0=3 \
divx    rd rs1 rs2 31..25=1  14..12=0 6..2=0x1D 1..0=3 

-> ponto flutuante \
faddx.s   rd rs1 rs2      31..27=0x10 rm       26..25=0 6..2=0x14 1..0=3 \
fsubx.s   rd rs1 rs2      31..27=0x11 rm       26..25=0 6..2=0x14 1..0=3 \
fmulx.s   rd rs1 rs2      31..27=0x12 rm       26..25=0 6..2=0x14 1..0=3 \
fdivx.s   rd rs1 rs2      31..27=0x13 rm       26..25=0 6..2=0x14 1..0=3  
     
     $ cd riscv-opcodes
     $ cat /home/dani/riscv-opcodes/opcodes | /home/dani/riscv-opcodes/parse-opcodes -c > /home/dani/riscv-opcodes/instructionInfo.h

b: Abra o arquivo instructionInfo.h e verifique se as linhas abaixos foram inseridas:

#define MATCH_ADDX 0x200002b \
#define MASK_ADDX  0xfe00707f \
#define MATCH_SUBX 0x200002f \
#define MASK_SUBX  0xfe00707f \
#define MATCH_MULX 0x2000073 \
#define MASK_MULX  0xfe00707f \
#define MATCH_DIVX 0x2000077 \
#define MASK_DIVX  0xfe00707f \
... \
DECLARE_INSN(addx, MATCH_ADDX, MASK_ADDX) \
DECLARE_INSN(subx, MATCH_SUBX, MASK_SUBX) \
DECLARE_INSN(mulx, MATCH_MULX, MASK_MULX) \
DECLARE_INSN(divx, MATCH_DIVX, MASK_DIVX) 

-> ponto flutuante \
#define MATCH_FADDX_S 0x80000053 \
#define MASK_FADDX_S  0xfe00007f \
#define MATCH_FSUBX_S 0x88000053 \
#define MASK_FSUBX_S  0xfe00007f \
#define MATCH_FMULX_S 0x90000053 \
#define MASK_FMULX_S  0xfe00007f \
#define MATCH_FDIVX_S 0x98000053 \
#define MASK_FDIVX_S  0xfe00007f \
... \
DECLARE_INSN(faddx_s, MATCH_FADDX_S, MASK_FADDX_S) \
DECLARE_INSN(fsubx_s, MATCH_FSUBX_S, MASK_FSUBX_S) \
DECLARE_INSN(fmulx_s, MATCH_FMULX_S, MASK_FMULX_S) \
DECLARE_INSN(fdivx_s, MATCH_FDIVX_S, MASK_FDIVX_S)

      $ make install

c: Entre nos diretórios seguintes e adicione: 

riscv-gnu-toolchain/riscv-gdb/include/opcode/riscv-opc.h \
riscv-gnu-toolchain/riscv-binutils/include/opcode/riscv-opc.h

#define MATCH_ADDX 0x200002b \
#define MASK_ADDX  0xfe00707f \
#define MATCH_SUBX 0x200002f \
#define MASK_SUBX  0xfe00707f \
#define MATCH_MULX 0x2000073 \
#define MASK_MULX  0xfe00707f \
#define MATCH_DIVX 0x2000077 \
#define MASK_DIVX  0xfe00707f \
... \
DECLARE_INSN(addx, MATCH_ADDX, MASK_ADDX) \
DECLARE_INSN(subx, MATCH_SUBX, MASK_SUBX) \
DECLARE_INSN(mulx, MATCH_MULX, MASK_MULX) \
DECLARE_INSN(divx, MATCH_DIVX, MASK_DIVX)

-> ponto flutuante \
#define MATCH_FADDX_S 0x80000053 \
#define MASK_FADDX_S  0xfe00007f \
#define MATCH_FSUBX_S 0x88000053 \
#define MASK_FSUBX_S  0xfe00007f \
#define MATCH_FMULX_S 0x90000053 \
#define MASK_FMULX_S  0xfe00007f \
#define MATCH_FDIVX_S 0x98000053 \
#define MASK_FDIVX_S  0xfe00007f \
... \
DECLARE_INSN(faddx_s, MATCH_FADDX_S, MASK_FADDX_S) \
DECLARE_INSN(fsubx_s, MATCH_FSUBX_S, MASK_FSUBX_S) \
DECLARE_INSN(fmulx_s, MATCH_FMULX_S, MASK_FMULX_S) \
DECLARE_INSN(fdivx_s, MATCH_FDIVX_S, MASK_FDIVX_S) \

d: Entre nos diretorios seguintes e adicione: 

riscv-gnu-toolchain/riscv-gdb/opcodes/riscv-opc.c \
riscv-gnu-toolchain/riscv-binutils/opcodes/riscv-opc.c

{"addx",	 0, INSN_CLASS_I, "d,s,t", MATCH_ADDX, MASK_ADDX, match_opcode, 0}, \
{"subx",	 0, INSN_CLASS_I, "d,s,t", MATCH_SUBX, MASK_SUBX, match_opcode, 0}, \
{"mulx",	 0, INSN_CLASS_I, "d,s,t", MATCH_MULX, MASK_MULX, match_opcode, 0}, \
{"divx",	 0, INSN_CLASS_I, "d,s,t", MATCH_DIVX, MASK_DIVX, match_opcode, 0},

-> ponto flutuante (em riscv-gdb remova _OR_ZFINX)

{"faddx.s",     0, INSN_CLASS_F_OR_ZFINX,   "D,S,T",     MATCH_FADDX_S|MASK_RM, MASK_FADDX_S|MASK_RM, match_opcode, 0 }, \
{"faddx.s",     0, INSN_CLASS_F_OR_ZFINX,   "D,S,T,m",   MATCH_FADDX_S, MASK_FADDX_S, match_opcode, 0 }, \
{"fsubx.s",     0, INSN_CLASS_F_OR_ZFINX,   "D,S,T",     MATCH_FSUBX_S|MASK_RM, MASK_FSUBX_S|MASK_RM, match_opcode, 0 }, \
{"fsubx.s",     0, INSN_CLASS_F_OR_ZFINX,   "D,S,T,m",   MATCH_FSUBX_S, MASK_FSUBX_S, match_opcode, 0 }, \
{"fmulx.s",    0, INSN_CLASS_F_OR_ZFINX,   "D,S,T",     MATCH_FMULX_S|MASK_RM, MASK_FMULX_S|MASK_RM, match_opcode, 0 }, \
{"fmulx.s",    0, INSN_CLASS_F_OR_ZFINX,   "D,S,T,m",   MATCH_FMULX_S, MASK_FMULX_S, match_opcode, 0 }, \
{"fdivx.s",    0, INSN_CLASS_F_OR_ZFINX,   "D,S,T",     MATCH_FDIVX_S|MASK_RM, MASK_FDIVX_S|MASK_RM, match_opcode, 0 }, \
{"fdivx.s",    0, INSN_CLASS_F_OR_ZFINX,   "D,S,T,m",   MATCH_FDIVX_S, MASK_FDIVX_S, match_opcode, 0 },

e: Rebuild RISCV-GNU-TOOLCHAIN

    $ cd riscv-gnu-toolchain
    $ make clean
    $ ./configure --prefix=/opt/riscv --with-arch=rv32i --with-abi=ilp32
      OR
    $ ./configure --prefix=/opt/riscv --with-arch=rv32imafdc --with-abi=ilp32
    $ sudo make

f: Teste da instalação da instrução aproximada no RISCV-Toolchain:

Crie um arquivo:
    
    $ cd test/addx.c 

A instrução aproximada é chamada por meio do comando *_asm volatile_*, e [x], [y] e [z] representam os registradores de dados e destino.

    #include <stdio.h>
     int main(){
     int a,b,addx, subx;
     a = 5;
     b = 2;
    asm volatile
    (
      "addx   %[z], %[x], %[y]\n\t"
      : [z] "=r" (addx)
      : [x] "r" (a), [y] "r" (b)
    );
    asm volatile
    ( 
      "subx   %[z], %[x], %[y]\n\t"
      : [z] "=r" (subx)
      : [x] "r" (a), [y] "r" (b)
    );
    printf("ADDX => 5+2=%d\n",addx);
    printf("SUBX => 5-2=%d\n",subx);
    return 0;
    }

Compile:

    $ riscv32-unknown-elf-gcc addx.c -O1 -march=rv32im -o addx 
    $ riscv32-unknown-elf-objdump -dC addx > addx.dump


2. **Inserção das Instruções Aproximadas no SPIKE**

   a: No diretório riscv-isa-sim/riscv/encoding.h adicione as linhas abaixo:
   
      a.1: Verificar se no arquivo encoding.h do PK (riscv-pk/machine/encoding.h) foi atualizado, caso não: atualizar e rebutar o riscv-pk
  
#define MATCH_ADDX 0x200002b \
#define MASK_ADDX  0xfe00707f \
#define MATCH_SUBX 0x200002f \
#define MASK_SUBX  0xfe00707f \
#define MATCH_MULX 0x2000073 \
#define MASK_MULX  0xfe00707f \
#define MATCH_DIVX 0x2000077 \
#define MASK_DIVX  0xfe00707f \
... \
DECLARE_INSN(addx, MATCH_ADDX, MASK_ADDX) \
DECLARE_INSN(subx, MATCH_SUBX, MASK_SUBX) \
DECLARE_INSN(mulx, MATCH_MULX, MASK_MULX) \
DECLARE_INSN(divx, MATCH_DIVX, MASK_DIVX)

-> ponto flutuante \
#define MATCH_FADDX_S 0x80000053 \
#define MASK_FADDX_S  0xfe00007f \
#define MATCH_FSUBX_S 0x88000053 \
#define MASK_FSUBX_S  0xfe00007f \
#define MATCH_FMULX_S 0x90000053 \
#define MASK_FMULX_S  0xfe00007f \
#define MATCH_FDIVX_S 0x98000053 \
#define MASK_FDIVX_S  0xfe00007f \
... \
DECLARE_INSN(faddx_s, MATCH_FADDX_S, MASK_FADDX_S) \
DECLARE_INSN(fsubx_s, MATCH_FSUBX_S, MASK_FSUBX_S) \
DECLARE_INSN(fmulx_s, MATCH_FMULX_S, MASK_FMULX_S) \
DECLARE_INSN(fdivx_s, MATCH_FDIVX_S, MASK_FDIVX_S) \

b: Criar um arquivo .h com a definição de funcionalidade de cada uma das instruções aproximadas. 

   OBS: os arquivos estão disponibilizados na pasta chamada **[Approx_Instructions](Approx_Instructions)**. 
   
   Os arquivos precisam ser inseridos na pasta do SPIKE: riscv-isa-sim/riscv/insns/addx.h subx.h ......  
   
   Exemplo do arquivo da instrução de soma aproximada addx.h: 

     WRITE_RD(sext_xlen(RS1 ^ RS2 ^ 00000000000000000000000000000000)); //ADDX com adder InXA1 

-> **PARA O PONTO FLUTUANTE** 
   - cria a instrução fxxx_s.h em riscv-isa-sim/riscv/insns (disponível na pasta **[Approx_Instructions](Approx_Instructions)**) 
   - os arquivos .c devem ser modificados na pasta riscv-isa-sim/softfloat (disponível na pasta **[Approx_Instructions](Approx_Instructions)**)

   A seguir estão descriminados os arquivos que foram alterados para o projeto das instruções aproximadas de ponto flutuante. 
   
- faddx_s.h
  - f32_addx.c
    - s_subMagsF32x.c
    - s_addMagsF32x.c
    
- fsubx_s.h
  - f32_subx.c
    - s_subMagsF32x.c
    - s_addMagsF32x.c
    
- fmulx_s.h
  - f32_mulx.c
    - s_roundPackToF32x.c    ( signZ, expZ, sigZ ) //mudei
    - s_shortShiftRightJam64x //mudei
    
- fdivx_s.h
  - f32_divx.c

c: Adicone as linhas abaixo no arquivo: riscv-isa-sim/riscv/riscv.mk.in

riscv_insn_ext_i = \
      ...
      addx \
      subx \
      mulx \
      divx \
      ...
  
riscv_insn_ext_f = \
      faddx_s \
      fsubx_s \
      fmulx_s \
      fdivx_s \
      ...

d: Acrescentar no arquivo: riscv-isa-sim/softfloat/softfloat.mk.in

  f32_addx.c \
  f32_subx.c \
  s_addMagsF32x.c \
  s_subMagsF32x.c 
  
  f32_mulx.c \
  s_roundPackToF32x.c \
  s_shortShiftRightJam64x 
  
  f32_divx.c 

e: Acrescentar no arquivo: riscv-isa-sim/softfloat/internals.h

-> para faddx e fsubx: \
  float32_t softfloat_addMagsF32x( uint_fast32_t, uint_fast32_t ); \
  float32_t softfloat_subMagsF32x( uint_fast32_t, uint_fast32_t );
  
-> para fmulx:   \
  float32_t softfloat_roundPackToF32x( bool, int_fast16_t, uint_fast32_t );

f: Acrescentar no arquivo: riscv-isa-sim/softfloat/softfloat.h \
  float32_t f32_addx( float32_t, float32_t ); \
  float32_t f32_subx( float32_t, float32_t ); \
  float32_t f32_mulx( float32_t, float32_t ); \
  float32_t f32_divx( float32_t, float32_t );

g: Rebuild SPIKE/build

    $ cd riscv-isa-sim/build 
    $ sudo make install

-->> SE DER ERRO NO REBUILD: \
ex: HGATP_MODE_SV57X4 (fora do escopo) 
   - está faltando alguma coisa, alguma declaração na nova instrução.

h: Teste o SPIKE

    $ spike --isa=RV32I /opt/riscv/riscv32-unknown-elf/bin/pk addx

Para testar o exemplo disponivel no seção do RISC-V (.c) no SPIKE, utilizar os comandos: 

    $ riscv32-unknown-elf-gcc test.c -O1 -march=rv32im -o test
    $ riscv32-unknown-elf-objdump -dC test > test.dump
    $ spike --isa=RV32I /opt/riscv/riscv32-unknown-elf/bin/pk test







## Contact
Daniela Luiza Catelan
daniela.catelan@ufms.br


