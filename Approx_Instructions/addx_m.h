//ADDX_M - InXA1
//Mixed integer instructions: (MBS - Approximate and LBS - Exact)
// Total 32 bits
//LBS = 0 a 15 - EXATO
//MBS = 16 a 31 - APPROX
//  ############# 
//       EXATO
//  S = A ^ B ^ Cin (XOR)
//  Cout = AB + ACin + BCin
//   #############
//       APPROX
// S = A ^ B ^ Cin (XOR)
// Cout = Cin

//NÃO FINALIZADA

WRITE_RD(sext_xlen(RS1 ^ RS2));
