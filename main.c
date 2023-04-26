/* I try to not include much boilerplate
 * things like: entire libs just for
 * one function.
 *
 * EVM - v0.1 */

#include <stdio.h>
/* I will try to not use much here
 * basically getchar, putchar and EOF
 * TODO: basically putchar, getchar & EOF
 * for now. */

/* Types */

#define CELL_TYPE  char
#define DCELL_TYPE short int

typedef unsigned char byte;
typedef unsigned CELL_TYPE cell;
typedef unsigned DCELL_TYPE dcell;
typedef cell* cell_p;
typedef dcell* dcell_p;

/* Sizes */

#define MEM_SIZE 0x10000
#define STACK_SIZE 0x100
#define MEM_END MEM_SIZE-1
#define STACK_END STACK_SIZE-1
#define CELL_SIZE  sizeof(cell)
#define DCELL_SIZE sizeof(dcell)

/* VM */

typedef struct {
	/* Memory */
	/* I don't know why, but, for now, stacks live
	 * outside the main memory. */
	byte mem[MEM_SIZE];

	/* Stacks */
	cell dstack[STACK_SIZE];
	cell rstack[STACK_SIZE];

	/* Pointers */
	dcell ip; /* Instruction Pointer */
	cell  sp, rp; /* Stacks Pointers */
} vm_t;

typedef vm_t* vm_p;
typedef void (*impl_fn)(vm_p);

/* Prototypes */

void vm_init(vm_p vm);
void vm_halt(vm_p vm);
void vm_exec(vm_p vm);
void vm_stat(vm_p vm);

/* Instructions Prototypes */

void vm_nop(vm_p vm);
void vm_lit(vm_p vm);
void vm_pop(vm_p vm);
void vm_end(vm_p vm);

/* Globals */

enum vm_opcode {
	VM_NOP, VM_LIT, VM_POP, VM_END,
	VM_COUNT 
};

impl_fn instr[VM_COUNT] = {
	vm_nop, vm_lit, vm_pop, vm_end
};

/* Functions */

void
vm_init(vm_p vm) {
	/* Clear memory */
	for(int i=0; i<MEM_SIZE; i++) {
		vm->mem[i] = 0;
	}

	/* Clear stacks */
	for(vm->ip=0;;vm->ip++) {
		vm->dstack[vm->ip] = 0;
		vm->rstack[vm->ip] = 0;
		if(vm->ip==STACK_SIZE-1) break;
	}

	/* Set up pointers */
	vm->ip = vm->sp = vm->rp = 0;
}

void
vm_exec(vm_p vm) {
	instr[vm->mem[vm->ip]](vm);
}

void
vm_stat(vm_p vm) {
	/* Memory */
	printf("mem:\n");
	for (int i = 0; i < MEM_SIZE; i++) {
		printf("%02X ", vm->mem[i]);
		if ((i + 1) % 16 == 0) {
			printf("\n");
		}
		if(((i+1)%16==0)&&vm->mem[i]==0&&vm->mem[i+1]==0) break;
	}
	printf("\n");

	/* Data stack */
	printf("DStack:\n");
	for (int i = 0; i < STACK_SIZE; i++) {
		printf("%02X ", vm->dstack[i]);
		if ((i + 1) % 16 == 0) {
			printf("\n");
		}
		if((vm->dstack[i]==0)&&(vm->dstack[i+1]==0)) break;
	}
	printf("\n");

	/* Return stack */
	printf("RStack:\n");
	for (int i = 0; i < STACK_SIZE; i++) {
	printf("%02X ", vm->rstack[i]);
		if ((i + 1) % 16 == 0) {
			printf("\n");
		}
		if((vm->rstack[i]==0)&&(vm->rstack[i+1]==0)) break;
	}
	printf("\n");

	/* Pointers */
	printf("ip: 0x%02X\n", vm->ip);
	printf("sp: 0x%02X\n", vm->sp);
	printf("rp: 0x%02X\n", vm->rp);
}

/* VM impl */

void
vm_nop(vm_p vm) {
	vm->ip++;
}

void
vm_lit(vm_p vm) {
	vm->ip++;
	vm->dstack[vm->sp++] = vm->mem[vm->ip++];
}

void
vm_pop(vm_p vm) {
	vm->ip++;
	vm->dstack[--vm->sp] = 0;
}

void
vm_end(vm_p vm) {
	vm->ip = MEM_END;
}

void
test(vm_p vm) {
	vm->mem[0] = VM_NOP; 
	vm->mem[1] = VM_LIT;
	vm->mem[2] = 0xfa;
	vm->mem[3] = VM_POP;
	vm->mem[4] = VM_END;
}

int
main(void) {
	vm_t vm;
	vm_init(&vm);
	test(&vm);

	while((vm.ip<MEM_END)) {
		vm_exec(&vm);
		vm_stat(&vm);
	}
	return 0;
}
