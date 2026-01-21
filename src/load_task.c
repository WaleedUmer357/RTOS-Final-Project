
#include "rtos.h"
#include "hardware/irq.h" 
#include "hardware/sync.h" 

__attribute__((weak)) int Load_Task(void (*Task)(void), uint32_t Task_ID, uint32_t Task_Priority) {
      if (Task == NULL || Task_ID == 0) {
        return 0;
    }
    uint32_t irq_state = save_and_disable_interrupts();
    int empty_slot = -1;
    for (int i = 0; i < MAX_NUM_OF_TASKS; i++) {
        if (Task_List[i].id == 0) { 
            empty_slot = i;
            break;
        }
    }
    if (empty_slot == -1) { 
        restore_interrupts(irq_state);
        return 0; 
    }
    Task_List[empty_slot].id = Task_ID;
    Task_List[empty_slot].priority = Task_Priority;
    Task_List[empty_slot].nextPt = NULL;
    uint32_t* stack_ptr = &Task_List[empty_slot].TCB_Stack[STACK_SIZE];
    stack_ptr = (uint32_t *)((uint32_t)(stack_ptr) & ~0x7);
    *(--stack_ptr) = 0x01000000;         
    *(--stack_ptr) = (uint32_t)Task;     
    *(--stack_ptr) = 0;         
    *(--stack_ptr) = 0;                 
    *(--stack_ptr) = 0;                
    *(--stack_ptr) = 0;               
    *(--stack_ptr) = 0;                 
    *(--stack_ptr) = 0;                
    *(--stack_ptr) = 0; 
    *(--stack_ptr) = 0; 
    *(--stack_ptr) = 0; 
    *(--stack_ptr) = 0; 
    *(--stack_ptr) = 0; 
    *(--stack_ptr) = 0;
    *(--stack_ptr) = 0; 
    *(--stack_ptr) = 0; 
    Task_List[empty_slot].Stack_Pointer = stack_ptr;
    if (CurrentTCB == NULL) {
        CurrentTCB = &Task_List[empty_slot];
    }
    restore_interrupts(irq_state);
    return Task_ID; 
}
