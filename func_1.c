#include "func.h"

struct_t gStructFnc1 = {
  .a = 11,
  .b = 12U,
  .c = 13U,
  .x = {14U, 15U}
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
          struct_t lStructFnc1 = {1000, 2000U, 3000U,  {4000U, 5000U}};

  lStructFnc1.a += gStructFnc2.a;
  lStructFnc1.b += gStructFnc2.b;
  lStructFnc1.c += gStructFnc2.c;
  lStructFnc1.x.x1 += gStructFnc2.x.x1;
  lStructFnc1.x.x2 += gStructFnc2.x.x2;

  __DSB();

  gStructFnc1 = lStructFnc1;

  __DSB();

  lVarU32_1 = sFnc (lVarU32_1 + 2);

  for (lVarI32_1 = 0; lVarI32_1 < 2; lVarI32_1++)
  {
    lVarI32_3 = eFnc_3 (lVarI32_2, lVarU32_1);
  }

}
