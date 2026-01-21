
#include "rtos.h"
#include <string.h>  

__attribute__((weak)) void Init_Scheduler(void) 
{
    memset(Task_List, 0, sizeof(Task_List));  
    for (int i = 0; i < MAX_NUM_OF_TASKS; i++) 
    {
        Task_List[i].Stack_Pointer = NULL;  
        Task_List[i].nextPt = NULL;         
    }

    CurrentTCB = NULL;  
    Ticks = 0;          
}