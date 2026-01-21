#ifndef SHM_H
#define SHM_H
#include <stddef.h>
#define SHM_SIZE 32  
extern void shm_init(void);
extern void* shm_attach(void);
extern void shm_detach(void* ptr);
extern void shm_destroy(void);
#endif