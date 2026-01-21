#ifndef RTOS_H
#define RTOS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "pico/stdlib.h"
#include "hardware/structs/systick.h" 	// systick registers
#include "pico/malloc.h"     			// dynamic memory functions
#include "pico/mem_ops.h"   			// memset etc


/// For simpilicity we will assume only two tasks
#define MAX_NUM_OF_TASKS   10
#define STACK_SIZE         1024


/// Task control block, implemented as a linked list to point to the TCB of the next task.
struct tcb{
  uint32_t      *Stack_Pointer;
  uint32_t		  id;               // zero id means empty task postion. Non-zero id means task in this position
  uint32_t		  priority;
  uint32_t      TCB_Stack[STACK_SIZE] ;
  struct tcb    *nextPt;
};

typedef struct tcb TCB_t; // Define tcb_t datatype

// display_buffer points to the shared memory between cores that represents
//     the display. ( 8 bytes for 8 digits ). 
// Each byte corresponds to a digit
// Each bit in the byte corresponds to the segment. See MAX7219 Datasheet
extern unsigned char *display_buffer;


/// Points to the TCB of the currently active task
extern volatile TCB_t *CurrentTCB;
extern TCB_t Task_List[MAX_NUM_OF_TASKS];

extern  uint32_t Ticks ; // global Tick for System Timing

// scheduler functionality
extern uint32_t Configure_Systick(uint32_t timer_value) ;
extern void Init_Scheduler();
extern void Scheduler(void) ;
extern void Start_RTOS(void) ;

// OS Operation functions
extern int Load_Task(void (*Task)(void),uint32_t Task_ID, uint32_t Task_Priority) ;
extern int Remove_Task(uint32_t id) ;

// HAL to drive the SPI for the 7seg board
int Hardware_Abstraction_Layer(void); 
extern unsigned char *display_buffer; // check in the main file of the project

// task functions

extern void Task1(void) ;
 extern void Task2(void) ;
extern void Task3(void) ;
extern void Task4(void) ;
extern void Task5(void) ;
extern void Task6(void) ;

#endif
