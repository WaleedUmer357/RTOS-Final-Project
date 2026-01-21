#include "rtos.h"

static uint32_t last_switch_tick = 0;
static int current_index = -1;

const uint32_t BASE_QUANTUM_TICKS = 500;  // 0.1 sec if tick = 1ms

__attribute__((weak)) void Scheduler(void) {
    Ticks++;

    if (CurrentTCB == NULL) return;

    uint32_t priority=CurrentTCB->priority;
   if(priority>1 && priority<3){
    priority=2;
   } else if (priority<2){
    priority=1;
   } else {
    priority=3;
   }
   uint32_t allowed_time_slice = BASE_QUANTUM_TICKS * (4 - priority);

    if ((Ticks - last_switch_tick) < allowed_time_slice) {
        return;
    }

    last_switch_tick = Ticks;

    int start_index = (current_index == -1) ? 0 : current_index;
    int next_index = -1;

    for (int i = 1; i <= MAX_NUM_OF_TASKS; i++) {
        int check_index = (start_index + i) % MAX_NUM_OF_TASKS;

        if (Task_List[check_index].id != 0) {
            next_index = check_index;
            break;
        }
    }

    if (next_index != -1) {
        current_index = next_index;
        CurrentTCB = &Task_List[current_index];
    } else {
        CurrentTCB = NULL; 
    }
}
