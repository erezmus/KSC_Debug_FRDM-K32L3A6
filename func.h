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

extern struct_t gStructFnc1;
extern struct_t gStructFnc2;
extern struct_t gStructFnc3;


    void eFnc_1 (void);
uint32_t eFnc_2 (uint32_t);
 int32_t eFnc_3 (int32_t, uint32_t);



__STATIC_FORCEINLINE int32_t sfiSSAT(int32_t val, uint32_t sat)
{
  if ((sat >= 1U) && (sat <= 32U))
  {
    const int32_t max = (int32_t)((1U << (sat - 1U)) - 1U);
    const int32_t min = -1 - max ;
    if (val > max)
    {
      return max;
    }
    else if (val < min)
    {
      return min;
    }
  }
  return val;
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
