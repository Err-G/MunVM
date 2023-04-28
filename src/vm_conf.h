#ifndef VM_CONF_H
#define VM_CONF_H

/* Types */

typedef unsigned char byte;      /* 8b  */
typedef unsigned short int addr; /* 16b */

/* Pointers */

typedef byte* byte_p;

/* Sizes */

#define MEM_SIZE 0x10000 /* 64KB */
#define STACK_SIZE 0x100 /* 1B   */

#define MEM_END   MEM_SIZE-1
#define STACK_END STACK_SIZE-1

#define CELL_SIZE sizeof(cell)

#endif
