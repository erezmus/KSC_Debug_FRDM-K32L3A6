#include "func.h"

struct_t gStructFnc3 = {
  .a = 31,
  .b = 32U,
  .c = 33U,
  .x = {34U, 35U}
};


int32_t eFnc_3 (int32_t pVarI32, uint32_t pVarU32)
{
  pVarU32 = eFnc_2(pVarU32);

  gStructFnc3 = gStructFnc1;

  return pVarI32 + (int32_t)pVarU32 + gStructFnc3.a;
}
