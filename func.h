#include "RTE_Components.h"
#include CMSIS_device_header

typedef struct _struct_t
{
    int32_t a;
    uint32_t b;
    uint32_t c;
    struct
    {
        uint16_t x1;
        uint16_t x2;
    } x;
} struct_t;

typedef enum _enum_t
{
  yes = 0,
  maybe,
  sure,
  never,
  no
} enum_t;

extern struct_t  gStructFnc1;
extern struct_t  gStructFnc2;
extern struct_t  gStructFnc3;

extern float     gVarF32;
extern double    gVarD64;
extern int64_t   gVarS64;
extern int32_t   gVarS32;
extern uint32_t  gVarU32;
extern uint32_t *gVarU32_p;
extern uint16_t  gVarU16;
extern uint8_t   gVarU8;
extern char      gText[];
extern enum_t    gVarEnum;


    void eFnc_1 (void);
uint32_t eFnc_2 (uint32_t);
 int32_t eFnc_3 (int32_t, uint32_t);
int32_t  eFnc_add(int32_t, int32_t);



__STATIC_FORCEINLINE uint32_t sfiAdd(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __ASM ("add %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__STATIC_FORCEINLINE uint32_t sfiUSAT(int32_t val, uint32_t sat)
{
  if (sat <= 31U)
  {
    const uint32_t max = ((1U << sat) - 1U);
    if (val > (int32_t)max)
    {
      return max;
    }
    else if (val < 0)
    {
      return 0U;
    }
  }
  return (uint32_t)val;
}

__STATIC_FORCEINLINE int32_t sfiMax(int32_t a, int32_t b)
{
  return a > b ? a : b;
}
