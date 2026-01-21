
#include "rtos.h"
#include "shm.h"
// Points to the TCB of the currently active task
volatile TCB_t *CurrentTCB;
TCB_t Task_List[MAX_NUM_OF_TASKS];  // scheduler list data structure

// This pointer holds the address of the seven segment display.
// This address points to a block of 8 bytes.
// Each byte corresponds to a display digit.
// Each bit in the byte corresponds to a single segment. 
// See MAX7219 Datasheet for the bit to segment map. 

unsigned char *display_buffer;

 uint32_t Ticks=0 ;  // global variable to be used for system timing
// **************** Kernel ****************
int main(void)
{
     
    stdio_init_all(); // needed for the Pico stdio functions
    shm_init();
    
    // wait for the usb serial connections to be established
   while (!stdio_usb_connected()) {}
   while (!stdio_usb_init()) {}
    
    printf("\n\nStarting RTOS Kernel\n\n");
   
 
    // start the Hardware Abstraction Layer (HAL)    
    printf("\n\nStarting HAL\n");
    if (Hardware_Abstraction_Layer() < 0 ) {
        printf("Error: Failed to Launch HAL - malloc returned NULL\n" );
        while(1) ; // spin lock to trap error
    }
   
   
    // Initialise the scheduler elements to 0 or NULL    
    Init_Scheduler() ;
   
    printf("\n\nInital Configuration of RTOS\n\n");


    // load tasks
     
//    Load_Task(&Task1,1,0);  
//      Load_Task(&Task2,2,0);
// //    Load_Task(&Task3,3,1);
// //       Load_Task(&Task4,4,3);
// //      Load_Task(&Task5,5,2);
 Load_Task(&Task6,6,1);

    Configure_Systick(1000) ; // 1 millisecond (1,000us)

    /// Make current tcb pointer point to task0
    CurrentTCB = &Task_List[0];
    
    printf("\n\nLaunching RTOS\n\n");
    Start_RTOS();

    // Error Trap for failed RTOS
    while (true) {
        printf("\nError: Should never get here\n");
        sleep_ms(2000);
    }
    return 0;
}


