#include "RTE_Components.h"
#include CMSIS_device_header

#include <math.h>

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

static float    gVarF32_1 = 1.51f;
extern float    gVarF32_2;
       float    gVarF32_2 = 0.5f;
extern int32_t  gVarS32_1;
       int32_t  gVarS32_1 = 1;
extern uint32_t gVarU32_1;
       uint32_t gVarU32_1 = 33U;


int main (void)
{
  volatile float    lVarF32 = 1.0f;
  volatile int32_t  lVarS32 = 2;
  volatile double   lVarS64 = 3;
  volatile uint32_t lVarU32 = 4U;

  SystemCoreClockUpdate();

  lVarF32 = gVarF32_1 * gVarF32_2;
  lVarF32 = lVarF32 + gVarF32_2 + gVarF32_1;

  gVarS32_1 = INT32_MIN;
  lVarS32   = sfiSSAT(gVarS32_1, 8U);
  
  lVarS32 = INT32_MAX;
  lVarU32 = sfiUSAT(lVarS32, 8U);

  
  lVarS32 = gVarS32_1;
  lVarS64 = (double)lVarS32 * lVarS32;
  lVarS64 = sqrt(lVarS64);

  eFnc_1();
  gVarU32_1 = eFnc_2(gVarU32_1);
  gVarS32_1 = eFnc_3(gVarS32_1, gVarU32_1);

//SysTick_Config(SystemCoreClock / 1000);

  while (1)
  {
    delay(20);
    __NOP();    
  }
}
