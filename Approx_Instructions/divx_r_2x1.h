//DIVX_R 2X1 - APSC4

reg_t Bin = 0;
reg_t Q = 0;

//B0
reg_t mask1 = 1;
reg_t mask2 = 2;

reg_t x0 = (RS1 & mask1);
reg_t y   = (RS2 & mask1);

reg_t Bout = ((~(x0 ^ (y ^ Q)) & Bin) | (~x0 & (y ^ Q)));

reg_t R = ((~x0 & (y ^ Q)) | ((y ^ Q) & Bin) | (~x0 & Bin) | (x0 & ~(y ^ Q) & ~Bin));

reg_t x1 = (RS1 & mask2);

reg_t Quoc = ~(x1 ^ Bout ^ Q);

WRITE_RD(sext_xlen(R));
