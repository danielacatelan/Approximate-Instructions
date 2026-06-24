//SUBX_M - APSC4
//Mixed integer instructions: (MBS - Approximate and LBS - Exact)
// Total 32 bits
//LBS = 0 a 15 - EXATO
//MBS = 16 a 31 - APPROX
//  ############# 
//       EXATO
//  S = A ^ B ^ Cin (XOR)
//  Cout = A'B + A'Cin + BCin
//   #############
//       APPROX
// S = A'B + BCin + A'Cin + AB'Cin'
// Cout = (A ^ B')Cin + A'B

//NÃO FINALIZADA

WRITE_RD(sext_xlen(RS1 ^ RS2));

