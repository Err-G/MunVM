#ifndef MEM_H
#define MEM_H

/* Types */

#define CELL_TYPE char
#define DCELL_TYPE short int

typedef unsigned char byte;
typedef unsigned CELL_TYPE cell;
typedef unsigned DCELL_TYPE dcell;

typedef cell* cell_p;
typedef dcell* dcell_p;

/* Sizes */

#define MEM_SIZE 0x10000
#define STACK_SIZE 0x100

#define MEM_END   MEM_SIZE-1
#define STACK_END STACK_SIZE-1

#define CELL_SIZE  sizeof(cell)
#define DCELL_SIZE sizeof(dcell)

/* Prototypes */

void mem_verify(void);

#endif
