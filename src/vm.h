#ifndef VM_H
#define VM_H

/* Includes */

#include "vm_conf.h"

/* Types */

typedef struct {
	/* Memory */
	byte mem[MEM_SIZE];

	/* Stacks */
	byte ds[STACK_SIZE]; /* Data Stack   */
	byte rs[STACK_SIZE]; /* Return Stack */

	/* Pointers */
	byte dp, rp; /* Data Pointer & Return Pointer */
	addr ip;     /* Instruction Pointer           */
} vm_t;

typedef vm_t* vm_p;

/* Prototypes */

void vm_init(vm_p vm);
int vm_ended(vm_p vm);
void vm_exec(vm_p vm);
void vm_stat(vm_p vm);

#endif
