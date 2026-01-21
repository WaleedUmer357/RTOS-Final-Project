#include "rtos.h"
#include "shm.h"
#define LED_PIN 25  
const unsigned char seg7_lut[16] = {
    0b01111110, 
    0b00110000, 
    0b01101101, 
    0b01111001, 
    0b00110011, 
    0b01011011, 
    0b01011111, 
    0b01110000, 
    0b01111111, 
    0b01111011, 
    0b01110111, 
    0b00011111, 
    0b01001110, 
    0b00111101, 
    0b01001111, 
    0b01000111  
};

void delay_ms(uint32_t ms) {
    uint32_t start = *(volatile uint32_t*)&Ticks;
    while ((*(volatile uint32_t*)&Ticks - start) < ms) {
       
    }
}

void Task1(void) {
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    void* shm = shm_attach();
    
    while (1) {
        gpio_put(LED_PIN, 1);
        if (shm) {
            strcpy((char*)shm, "BLINK");
            printf("Sent BLINK signal\n"); 
        }
        delay_ms(500);
        
        gpio_put(LED_PIN, 0);
        if (shm) {
            strcpy((char*)shm, "COUNT");
            printf("Sent COUNT signal\n"); 
        }
        delay_ms(500);
    }
    if (shm) {
        strcpy((char*)shm, "COUNT");
    }
}

void SPI_DisplayNumber(uint8_t num) {
    uint8_t tens = (num / 10) % 10;
    uint8_t units = num % 10;
    display_buffer[4] = seg7_lut[tens];
    display_buffer[5] = seg7_lut[units];

}

void Task2(void) {
    void* shm = shm_attach();
    uint8_t count = 0;
    uint32_t last_msg_time = 0;
    bool should_blink = false;

    SPI_DisplayNumber(88);
    
    while (1) {
        
        if (shm) {
            if (strcmp((char*)shm, "BLINK") == 0) {
                should_blink = true;
                last_msg_time = Ticks;
                printf("Received BLINK\n"); 
            }
            else if (strcmp((char*)shm, "COUNT") == 0) {
                should_blink = false;
                last_msg_time = Ticks;
                printf("Received COUNT\n"); 
            }            
            if (Ticks - last_msg_time > 1000) {
                should_blink = false;
            }
        }
        if (should_blink) {
            display_buffer[4] = seg7_lut[8];
            display_buffer[5] = seg7_lut[8];
            printf("Displaying 88\n");  
        } 
        else {
            SPI_DisplayNumber(count);
            count = (count + 1) % 100;
            printf("Counting: %d\n", count);  
        }
        
        delay_ms(500);
    }
}



void Task3(void) {
    while (1) {
        display_buffer[3] |= 0x80; 
        delay_ms(250);  
        display_buffer[3] &= ~0x80; 
        delay_ms(250);  
    }
}

void Task4(void) {
     while (1) {
        for (int i = 15; i >= 0; i--) {
            display_buffer[2] = seg7_lut[i];
            delay_ms(500);  
        }
        delay_ms(1000);
               for (int i = 0; i <= 15; i++) {
            display_buffer[3] = seg7_lut[i];
            delay_ms(500);  
        }
    }
}



void Task5(void) {
    uint8_t segments[8] = {
        0x80,
        0x40,
        0x20,
        0x10,
        0x08,
        0x04,
        0x02,
        0x01 
    };

    while (1) {
               for (int i = 0; i < 8; i++) {
            display_buffer[0] = segments[i];
            delay_ms(500);  
        }
        for (int i = 7; i >= 0; i--) {
            display_buffer[0] = segments[i];
            delay_ms(500); 
        }
    }
}

void Task6(void) {
    char input[32];
    printf("\nRTOS Command Line Interface\n");
    printf("Type 'HELP' for available commands\n\n");
    while (1) {
        printf(">> ");
        fflush(stdout);
        memset(input, 0, sizeof(input));
        if (fgets(input, sizeof(input), stdin) == NULL) {
            continue;
        }
        input[strcspn(input, "\n")] = '\0';
        char *end = input + strlen(input) - 1;
        while (end >= input && isspace((unsigned char)*end)) {
            *end-- = '\0';
        }
        if (strlen(input) == 0) continue;
        for (char *p = input; *p; p++) {
            *p = toupper((unsigned char)*p);
        }
        if (strcmp(input, "PS") == 0) {
            printf("\n%-10s %-10s\n", "Task ID", "Priority");
            printf("--------------------\n");
            bool tasksFound = false;
            for (int i = 0; i < MAX_NUM_OF_TASKS; ++i) {
                if (Task_List[i].id != 0) {
                    printf("%-10d %-10d\n", Task_List[i].id, Task_List[i].priority);
                    tasksFound = true;
                }
            }
            if (!tasksFound) {
                printf("No tasks currently running\n");
            }
            printf("\n");
        }
         else if (strcmp(input, "HELP") == 0) {
            printf("\nAvailable commands:\n");
            printf("PS       - List all tasks\n");
            printf("LD <n>   - Load task (1-5)\n");
            printf("RM <n>   - Remove task (1-5)\n");
            printf("HELP     - Show this help message\n\n");
        } 
        else if (strncmp(input, "LD", 2) == 0) {
            char *num_ptr = input + 2;
            while (*num_ptr && !isdigit((unsigned char)*num_ptr)) num_ptr++;
            if (*num_ptr == '\0') {
                printf("Error: Missing task number. Usage: LD <1-5>\n");
                continue;
            }
            int id = atoi(num_ptr);
            if (id < 1 || id > 5) {
                printf("Error: Task number must be between 1-5\n");
                continue;
            }           
            bool exists = false;
            for (int i = 0; i < MAX_NUM_OF_TASKS; ++i) {
                if (Task_List[i].id == id) {
                    exists = true;
                    break;
                }
            }
            if (exists) {
                printf("Error: Task %d is already loaded\n", id);
                continue;
            }
            int status = -1;
            switch (id) {
                case 1: status = Load_Task(Task1, 1, 3); break;
                case 2: status = Load_Task(Task2, 2, 2); break;
                case 3: status = Load_Task(Task3, 3, 1); break;
                case 4: status = Load_Task(Task4, 4, 3); break;
                case 5: status = Load_Task(Task5, 5, 2); break;
            }
            if (status != 0) {
                printf("Task %d loaded successfully\n", id);
            } else {
                printf("Failed to load Task %d (error: %d)\n", id, status);
            }
        }
         else if (strncmp(input, "RM", 2) == 0) {
            char *num_ptr = input + 2;
            while (*num_ptr && !isdigit((unsigned char)*num_ptr)) num_ptr++;
            if (*num_ptr == '\0') {
                printf("Error: Missing task number. Usage: RM <1-5>\n");
                continue;
            }
            int id = atoi(num_ptr);
             if (id == 1) 
             {  
        void* shm = shm_attach();
        if (shm) {
            strcpy((char*)shm, "COUNT");
            printf("Forced COUNT signal on Task1 removal\n");
        }
    }
    
            if (id < 1 || id > 5) {
                printf("Error: Task number must be between 1-5\n");
                continue;
            }
            bool exists = false;
            for (int i = 0; i < MAX_NUM_OF_TASKS; ++i) {
                if (Task_List[i].id == id) {
                    exists = true;
                    break;
                }
            }
            if (!exists) {
                printf("Error: Task %d is not currently loaded\n", id);
                continue;
            }
            int status = Remove_Task(id);
            if (status != 0) {
                printf("Task %d removed successfully\n", id);
            } else {
                printf("Failed to remove Task %d (error: %d)\n", id, status);
            }
        } 
        else {
            printf("Unknown command. Type 'HELP' for available commands\n");
        }
    }
}
