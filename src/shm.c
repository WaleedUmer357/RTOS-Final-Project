#include "shm.h"
#include <stdlib.h>
#include <string.h>
static int shm_id = -1;
static void* shm_ptr = NULL;
void shm_init(void) {
    if (shm_ptr == NULL) {
        shm_ptr = malloc(SHM_SIZE);
    }
    memset(shm_ptr, 0, SHM_SIZE);  
}
void* shm_attach(void) {
    return shm_ptr;  
}

void shm_detach(void* ptr) {
    (void)ptr;
}

void shm_destroy(void) {
    if (shm_ptr) {
        free(shm_ptr);
        shm_ptr = NULL;
    }
}