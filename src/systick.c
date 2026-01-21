#include "rtos.h"
#include "hardware/structs/systick.h"
__attribute__((weak)) uint32_t Configure_Systick(uint32_t micro_seconds)
{
    uint32_t count = micro_seconds * 125;

    if (count > 0xFFFFFF)
        return 1; 
    systick_hw->csr = 0;
    systick_hw->rvr = count - 1;
    systick_hw->cvr = 0;
    systick_hw->csr = 0x7;  // 0b00000111
    return 0;
}
