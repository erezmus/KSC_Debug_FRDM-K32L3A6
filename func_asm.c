

#include "func.h"

int32_t eFnc_add(int32_t op1, int32_t op2)
{
  int32_t result;

  __ASM ("add %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}
