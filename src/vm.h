#ifndef VM_H
#define VM_H

/* Types */

typedef unsigned char byte;
typedef unsigned short int addr;

/* Sizes */

#define MEM_SIZE 0x10000
#define STACK_SIZE 0x100

#define MEM_END 0xffff
#define STACK_END 0xff

/* VM */

typedef struct {
	/* Memory */
	byte mem[MEM_SIZE];

	/* Stacks */
	byte ds[STACK_SIZE]; /* Data Stack   */
	byte rs[STACK_SIZE]; /* Return Stack */

	/* Pointers */
	byte dp, rp; /* Data Pointer, Return Pointer */
	addr pc;     /* Program Counter              */
} vm_t;
typedef vm_t* vm_p;

/* Prototypes */

void vm_init(vm_p vm);

/* modular instruction set by vm_exec
 * yes this is a feature... */
extern void vm_exec(vm_p vm);

#endif
