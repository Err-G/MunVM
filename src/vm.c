#include "vm.h"
#include "mem.h"
#include "impl.h"

#include <stdio.h>

void
vm_init(vm_p vm) {
	/* Clear memory */
	for(vm->ip=0;;vm->ip++) {
		vm->mem[vm->ip] = 0;
		if(vm->ip==MEM_END) break;
	}

	/* Clear stacks */
	for(vm->ip=0;;vm->ip++) {
		vm->dstack[vm->ip] = 0;
		vm->rstack[vm->ip] = 0;
		if(vm->ip==STACK_END) break;
	}

	/* Set up 'pointers' */
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
