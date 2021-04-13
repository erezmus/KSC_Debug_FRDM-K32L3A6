#include "func.h"

struct_t gStructFnc1 = {
  .a = 1,
  .b = 2U,
  .c = 3U,
  .x = {11U, 12U}
};


static uint32_t sFnc (uint32_t pVarU32)
{
  return pVarU32 + 2;
}

void eFnc_1 (void)
{
           int32_t lVarI32_1;
           int32_t lVarI32_2 = 1;
volatile   int32_t lVarI32_3 = 2;
          uint32_t lVarU32_1 = 3U;

  lVarU32_1 = sFnc (lVarU32_1 + 2);

  for (lVarI32_1 = 0; lVarI32_1 < 2; lVarI32_1++)
  {
    lVarI32_3 = eFnc_3 (lVarI32_2, lVarU32_1);
  }

  gStructFnc1.a = gStructFnc2.a;
  gStructFnc1.b = gStructFnc2.b;
  gStructFnc1.c = gStructFnc2.c;
  gStructFnc1.x.x1 = gStructFnc2.x.x1;
  gStructFnc1.x.x2 = gStructFnc2.x.x2;

}
