//SUBX - APSC4
reg_t Cin = 0;
reg_t S;

//P0
reg_t mask = 1;
reg_t x0 = (RS1 & mask);
reg_t y0 = (RS2 & mask);
reg_t Cout0 = (((x0 ^ ~y0) & Cin) | (~x0 & y0));
Cout0 = (Cout0 << 1); 
reg_t S0 = ((~x0 & y0) | (y0 & Cin) | (~x0 & Cin) | (x0 & ~y0 & ~Cin));

//P1
mask = 2;
x0 = (RS1 & mask);
y0 = (RS2 & mask);
reg_t Cout1 = (((x0 ^ ~y0) & Cout0) | (~x0 & y0));
Cout1 = (Cout1 << 1);
reg_t S1 = ((~x0 & y0) | (y0 & Cout0) | (~x0 & Cout0) | (x0 & ~y0 & ~Cout0));

//P2
mask = 4;
x0 = (RS1 & mask);
y0 = (RS2 & mask);
reg_t Cout2 = (((x0 ^ ~y0) & Cout1) | (~x0 & y0));
Cout2 = (Cout2 << 1);
reg_t S2 = ((~x0 & y0) | (y0 & Cout1) | (~x0 & Cout1) | (x0 & ~y0 & ~Cout1));

//P3
mask = 8;
x0 = (RS1 & mask);
y0 = (RS2 & mask);
reg_t Cout3 = (((x0 ^ ~y0) & Cout2) | (~x0 & y0));
Cout3 = (Cout3 << 1);
reg_t S3 = ((~x0 & y0) | (y0 & Cout2) | (~x0 & Cout2) | (x0 & ~y0 & ~Cout2));
//------------------------
//P4
mask = 16;
x0 = (RS1 & mask);
y0 = (RS2 & mask);
reg_t Cout4 = (((x0 ^ ~y0) & Cout3) | (~x0 & y0));
Cout4 = (Cout4 << 1); 
reg_t S4 = ((~x0 & y0) | (y0 & Cout3) | (~x0 & Cout3) | (x0 & ~y0 & ~Cout3));

//P5
mask = 32;
x0 = (RS1 & mask);
y0 = (RS2 & mask);
reg_t Cout5 = (((x0 ^ ~y0) & Cout4) | (~x0 & y0));
Cout5 = (Cout5 << 1);
reg_t S5 = ((~x0 & y0) | (y0 & Cout4) | (~x0 & Cout4) | (x0 & ~y0 & ~Cout4));

//P6
mask = 64;
x0 = (RS1 & mask);
y0 = (RS2 & mask);
reg_t Cout6 = (((x0 ^ ~y0) & Cout5) | (~x0 & y0));
Cout6 = (Cout6 << 1);
reg_t S6 = ((~x0 & y0) | (y0 & Cout5) | (~x0 & Cout5) | (x0 & ~y0 & ~Cout5));

//P7
mask = 128;
x0 = (RS1 & mask);
y0 = (RS2 & mask);
reg_t Cout7 = (((x0 ^ ~y0) & Cout6) | (~x0 & y0));
Cout7 = (Cout7 << 1);
reg_t S7 = ((~x0 & y0) | (y0 & Cout6) | (~x0 & Cout6) | (x0 & ~y0 & ~Cout6));
//------------------------
//P8
mask = 256;
x0 = (RS1 & mask);
y0 = (RS2 & mask);
reg_t Cout8 = (((x0 ^ ~y0) & Cout7) | (~x0 & y0));
Cout8 = (Cout8 << 1); 
reg_t S8 = ((~x0 & y0) | (y0 & Cout7) | (~x0 & Cout7) | (x0 & ~y0 & ~Cout7));

//P9
mask = 512;
x0 = (RS1 & mask);
y0 = (RS2 & mask);
reg_t Cout9 = (((x0 ^ ~y0) & Cout8) | (~x0 & y0));
Cout9 = (Cout9 << 1);
reg_t S9 = ((~x0 & y0) | (y0 & Cout8) | (~x0 & Cout8) | (x0 & ~y0 & ~Cout8));

//P10
mask = 1024;
x0 = (RS1 & mask);
y0 = (RS2 & mask);
reg_t Cout10 = (((x0 ^ ~y0) & Cout9) | (~x0 & y0));
Cout10 = (Cout10 << 1);
reg_t S10 = ((~x0 & y0) | (y0 & Cout9) | (~x0 & Cout9) | (x0 & ~y0 & ~Cout9));

//P11
mask = 2048;
x0 = (RS1 & mask);
y0 = (RS2 & mask);
reg_t Cout11 = (((x0 ^ ~y0) & Cout10) | (~x0 & y0));
Cout11 = (Cout11 << 1);
reg_t S11 = ((~x0 & y0) | (y0 & Cout10) | (~x0 & Cout10) | (x0 & ~y0 & ~Cout10));
//-----------------------------
//P12
mask = 4096;
x0 = (RS1 & mask);
y0 = (RS2 & mask);
reg_t Cout12 = (((x0 ^ ~y0) & Cout11) | (~x0 & y0));
Cout12 = (Cout12 << 1); 
reg_t S12 = ((~x0 & y0) | (y0 & Cout11) | (~x0 & Cout11) | (x0 & ~y0 & ~Cout11));

//P13
mask = 8192;
x0 = (RS1 & mask);
y0 = (RS2 & mask);
reg_t Cout13 = (((x0 ^ ~y0) & Cout12) | (~x0 & y0));
Cout13 = (Cout13 << 1);
reg_t S13 = ((~x0 & y0) | (y0 & Cout12) | (~x0 & Cout12) | (x0 & ~y0 & ~Cout12));

//P14
mask = 16384;
x0 = (RS1 & mask);
y0 = (RS2 & mask);
reg_t Cout14 = (((x0 ^ ~y0) & Cout13) | (~x0 & y0));
Cout14 = (Cout14 << 1);
reg_t S14 = ((~x0 & y0) | (y0 & Cout13) | (~x0 & Cout13) | (x0 & ~y0 & ~Cout13));

//P15
mask = 32768;
x0 = (RS1 & mask);
y0 = (RS2 & mask);
reg_t Cout15 = (((x0 ^ ~y0) & Cout14) | (~x0 & y0));
Cout15 = (Cout15 << 1);
reg_t S15 = ((~x0 & y0) | (y0 & Cout14) | (~x0 & Cout14) | (x0 & ~y0 & ~Cout14));
//-----------------------------
//P16
mask = 65536;
x0 = (RS1 & mask);
y0 = (RS2 & mask);
reg_t Cout16 = (((x0 ^ ~y0) & Cout15) | (~x0 & y0));
Cout16 = (Cout16 << 1); 
reg_t S16 = ((~x0 & y0) | (y0 & Cout15) | (~x0 & Cout15) | (x0 & ~y0 & ~Cout15));

//P17
mask = 131072;
x0 = (RS1 & mask);
y0 = (RS2 & mask);
reg_t Cout17 = (((x0 ^ ~y0) & Cout16) | (~x0 & y0));
Cout17 = (Cout17 << 1);
reg_t S17 = ((~x0 & y0) | (y0 & Cout16) | (~x0 & Cout16) | (x0 & ~y0 & ~Cout16));

//P18
mask = 262144;
x0 = (RS1 & mask);
y0 = (RS2 & mask);
reg_t Cout18 = (((x0 ^ ~y0) & Cout17) | (~x0 & y0));
Cout18 = (Cout18 << 1);
reg_t S18 = ((~x0 & y0) | (y0 & Cout17) | (~x0 & Cout17) | (x0 & ~y0 & ~Cout17));

//P19
mask = 262144;
x0 = (RS1 & mask);
y0 = (RS2 & mask);
reg_t Cout19 = (((x0 ^ ~y0) & Cout18) | (~x0 & y0));
Cout19 = (Cout19 << 1);
reg_t S19 = ((~x0 & y0) | (y0 & Cout18) | (~x0 & Cout18) | (x0 & ~y0 & ~Cout18));
//------------------------
//P20
mask = 1048576;
x0 = (RS1 & mask);
y0 = (RS2 & mask);
reg_t Cout20 = (((x0 ^ ~y0) & Cout19) | (~x0 & y0));
Cout20 = (Cout20 << 1); 
reg_t S20 = ((~x0 & y0) | (y0 & Cout19) | (~x0 & Cout19) | (x0 & ~y0 & ~Cout19));

//P21
mask = 2097152;
x0 = (RS1 & mask);
y0 = (RS2 & mask);
reg_t Cout21 = (((x0 ^ ~y0) & Cout20) | (~x0 & y0));
Cout21 = (Cout21 << 1);
reg_t S21 = ((~x0 & y0) | (y0 & Cout20) | (~x0 & Cout20) | (x0 & ~y0 & ~Cout20));

//P22
mask = 4194304;
x0 = (RS1 & mask);
y0 = (RS2 & mask);
reg_t Cout22 = (((x0 ^ ~y0) & Cout21) | (~x0 & y0));
Cout22 = (Cout22 << 1);
reg_t S22 = ((~x0 & y0) | (y0 & Cout21) | (~x0 & Cout21) | (x0 & ~y0 & ~Cout21));

//P23
mask = 8388608;
x0 = (RS1 & mask);
y0 = (RS2 & mask);
reg_t Cout23 = (((x0 ^ ~y0) & Cout22) | (~x0 & y0));
Cout23 = (Cout23 << 1);
reg_t S23 = ((~x0 & y0) | (y0 & Cout22) | (~x0 & Cout22) | (x0 & ~y0 & ~Cout22));
//------------------------
//P24
mask = 16777216;
x0 = (RS1 & mask);
y0 = (RS2 & mask);
reg_t Cout24 = (((x0 ^ ~y0) & Cout23) | (~x0 & y0));
Cout24 = (Cout24 << 1); 
reg_t S24 = ((~x0 & y0) | (y0 & Cout23) | (~x0 & Cout23) | (x0 & ~y0 & ~Cout23));

//P25
mask = 33554432;
x0 = (RS1 & mask);
y0 = (RS2 & mask);
reg_t Cout25 = (((x0 ^ ~y0) & Cout24) | (~x0 & y0));
Cout25 = (Cout25 << 1);
reg_t S25 = ((~x0 & y0) | (y0 & Cout24) | (~x0 & Cout24) | (x0 & ~y0 & ~Cout24));

//P26
mask = 67108864;
x0 = (RS1 & mask);
y0 = (RS2 & mask);
reg_t Cout26 = (((x0 ^ ~y0) & Cout25) | (~x0 & y0));
Cout26 = (Cout26 << 1);
reg_t S26 = ((~x0 & y0) | (y0 & Cout25) | (~x0 & Cout25) | (x0 & ~y0 & ~Cout25));

//P27
mask = 134217728;
x0 = (RS1 & mask);
y0 = (RS2 & mask);
reg_t Cout27 = (((x0 ^ ~y0) & Cout26) | (~x0 & y0));
Cout27 = (Cout27 << 1);
reg_t S27 = ((~x0 & y0) | (y0 & Cout26) | (~x0 & Cout26) | (x0 & ~y0 & ~Cout26));
//-----------------------------
//P28
mask = 268435456;
x0 = (RS1 & mask);
y0 = (RS2 & mask);
reg_t Cout28 = (((x0 ^ ~y0) & Cout27) | (~x0 & y0));
Cout28 = (Cout28 << 1); 
reg_t S28 = ((~x0 & y0) | (y0 & Cout27) | (~x0 & Cout27) | (x0 & ~y0 & ~Cout27));

//P29
mask = 536870912;
x0 = (RS1 & mask);
y0 = (RS2 & mask);
reg_t Cout29 = (((x0 ^ ~y0) & Cout28) | (~x0 & y0));
Cout29 = (Cout29 << 1);
reg_t S29 = ((~x0 & y0) | (y0 & Cout28) | (~x0 & Cout28) | (x0 & ~y0 & ~Cout28));

//P30
mask = 1073741824;
x0 = (RS1 & mask);
y0 = (RS2 & mask);
reg_t Cout30 = (((x0 ^ ~y0) & Cout29) | (~x0 & y0));
Cout30 = (Cout30 << 1);
reg_t S30 = ((~x0 & y0) | (y0 & Cout29) | (~x0 & Cout29) | (x0 & ~y0 & ~Cout29));

//P31
mask = 2147483648;
x0 = (RS1 & mask);
y0 = (RS2 & mask);
reg_t Cout31 = (((x0 ^ ~y0) & Cout30) | (~x0 & y0));
Cout31 = (Cout31 << 1);
reg_t S31 = ((~x0 & y0) | (y0 & Cout30) | (~x0 & Cout30) | (x0 & ~y0 & ~Cout30));
//-----------------------------
S = ((S31) | (S30) | (S29) | (S28) | (S27) | (S26) | (S25) | (S24) | (S23) | (S22) | (S21) | (S20) | (S19) | (S18) | (S17) | (S16) | (S15) | (S14) | (S13) | (S12) | (S11) | (S10) | (S9) | (S8) | (S7) | (S6) | (S5) | (S4) | (S3) | (S2) | (S1) | (S0));

WRITE_RD(sext_xlen(S));

