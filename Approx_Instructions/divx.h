//MULX COM TRUNCAMENTO
reg_t rs1 = (RS1 >> 6) << 6;
reg_t rs2 = (RS2 >> 6) << 6;

WRITE_RD(sext_xlen(rs1 * rs2));
