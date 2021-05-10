#include "RTE_Components.h"
#include CMSIS_device_header

#include <math.h>
#include <stdlib.h>

#include "func.h"

#if defined USE_SYSTICK__
static volatile uint32_t msTicks;
void SysTick_Handler(void);
void SysTick_Handler(void)
{
  msTicks++;
}

static void delay (int32_t dlyTicks)
{
  uint32_t curTicks;

  curTicks = msTicks;
  while ((msTicks - curTicks) < dlyTicks)
  {
    __NOP();
  }
}
#else
static void delay (int32_t dlyTicks)
{
  dlyTicks <<= 8;
  while (dlyTicks--)
  {
    __NOP();
  }
}
#endif

static float     gVarF32_s = 1.32f;
       float     gVarF32   = 0.32f;
       double    gVarD64   = 0.64;
       int64_t   gVarS64   = 64;
       int32_t   gVarS32   = 32;
       uint32_t  gVarU32   = 32U;
       uint32_t *gVarU32_p = &gVarU32;
       uint16_t  gVarU16   = 16U;
       uint8_t   gVarU8    = 8U;
       char      gText[]   = "Hello World.";
       enum_t    gVarEnum  = never;


int main (void)
{
  volatile float     lVarF32   = gVarF32;
  volatile double    lVarD64   = gVarD64;
  volatile int64_t   lVarS64   = gVarS64;
  volatile int32_t   lVarS32   = gVarS32;
  volatile uint32_t  lVarU32   = gVarU32;
  volatile uint32_t *lVarU32_p = gVarU32_p;
  volatile uint16_t  lVarU16   = gVarU16;
  volatile uint8_t   lVarU8    = gVarU8;
  volatile size_t    lVarST    = 0;
  volatile char      lText[20];
  volatile enum_t    lVarEnum;

 __DSB();

//SystemCoreClockUpdate();
//SysTick_Config(SystemCoreClock / 1000);

  lVarF32 = gVarF32_s * gVarF32;
  gVarF32 = lVarF32 / gVarF32_s;

  gVarS32 = INT32_MAX;
  lVarU32 = sfiUSAT(gVarS32, 8U);

  lVarU32_p = &lVarU32;
  *gVarU32_p = *lVarU32_p;

  lVarS64 = lVarS32 = gVarS32;
  lVarS64 = lVarS64 * lVarS32;
  lVarD64 = sqrt((double)lVarS64);

  lVarU8 = sizeof(lVarS64);

  lVarST  = sizeof(gText);
  lText[lVarST - 1] = 0;
  for (lVarS32 = 0; lVarS32 < (int32_t)(lVarST - 1); lVarS32++) {
    lText[lVarS32] = gText[lVarS32];
    gText[lVarS32] = lText[lVarS32] + 1;
  }

  for (lVarEnum = yes; lVarEnum <= no; lVarEnum++)
  {
    gVarEnum = lVarEnum;
  }
  
  gVarU32 = lVarU16 + lVarU8 - gVarU8;

  lVarU32 = 1000U;
  gVarU32 = sfiAdd(lVarU32, 10U);
  lVarS32 = 1000;
  gVarS32 = eFnc_add(lVarS32, 10);

  eFnc_1();
  gVarU32 = eFnc_2(gVarU32);
  gVarS32 = eFnc_3(gVarS32, gVarU32);

  while (1)
  {
    __NOP();
    delay(20);
  }
}
