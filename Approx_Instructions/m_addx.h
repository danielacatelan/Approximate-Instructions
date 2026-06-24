//M_ADDX - InXA1
// Mixed integer instructions: (MBS - Exact and LBS - Approximate)
// Total 32 bits
// LBS = 0 a 15 - APPROX 
// MBS = 16 a 31 - EXATO
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

