#include "rtos.h"
#include "hardware/sync.h" 

__attribute__((weak)) int Remove_Task(uint32_t id) {
    if (id == 0) return 0;  
    uint32_t irq_state = save_and_disable_interrupts();

    for (int i = 0; i < MAX_NUM_OF_TASKS; i++) {
        if (Task_List[i].id == id) {
            Task_List[i].id = 0;
            Task_List[i].priority = 0;
            Task_List[i].Stack_Pointer = NULL;
            Task_List[i].nextPt = NULL;
            memset(Task_List[i].TCB_Stack, 0, sizeof(Task_List[i].TCB_Stack));
            if (CurrentTCB == &Task_List[i]) {
                CurrentTCB = NULL;
            }
            restore_interrupts(irq_state);
            return id; 
        }
    }
    restore_interrupts(irq_state);
    return 0;
}
