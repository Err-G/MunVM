#ifndef VM_H
#define VM_H

/* Includes */

#include "mem.h"

/* Types */

typedef struct {
	/* Memory */
	byte mem[MEM_SIZE];

	/* Stacks */
	cell dstack[STACK_SIZE];
	cell rstack[STACK_SIZE];

	/* Pointers */
	cell sp, rp;  /* Stack Pointer & Return stack Pointer*/
	dcell ip; /* Instruction Pointer */
} vm_t;

typedef vm_t* vm_p;

/* Prototypes */

void vm_init(vm_p vm);
void vm_exec(vm_p vm);
void vm_stat(vm_p vm);

#endif
