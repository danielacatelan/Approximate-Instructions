// M_SUBX - APSC4
// Mixed integer instructions: (MBS - Exact and LBS - Approximate)
// Total 32 bits
// LBS = 0 a 15 - APPROX 
// MBS = 16 a 31 - EXATO
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

