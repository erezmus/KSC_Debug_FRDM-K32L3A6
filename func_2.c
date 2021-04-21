#include "func.h"

struct_t gStructFnc2 = {
  .a = 21,
  .b = 22U,
  .c = 23U,
  .x = {24U, 25U}
};


static uint32_t sfunc (uint32_t pVarU32)
{
  return pVarU32 << 2;
}

uint32_t eFnc_2 (uint32_t pVarU32)
{
  uint32_t lVarU32 = 0;

  lVarU32 = sfunc (pVarU32);
  lVarU32 = lVarU32 + sfiUSAT((int32_t)pVarU32, 6);

  gStructFnc2.a = gStructFnc3.a;
  gStructFnc2.b = gStructFnc3.b;
  gStructFnc2.c = gStructFnc3.c;
  gStructFnc2.x.x1 = gStructFnc3.x.x1;
  gStructFnc2.x.x2 = gStructFnc3.x.x2;

  return lVarU32 + pVarU32;
}
